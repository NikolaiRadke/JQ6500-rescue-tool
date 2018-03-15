/*
 * jq6500 - Program the SPI flash of a JQ6500 MP3 player module.
 *
 * Copyright (C) 2018 Reinhard Max <reinhard@m4x.de>
 *
 * "THE BEER-WARE LICENSE" (Revision 42): As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet
 * some day, and you think this stuff is worth it, you can buy me a
 * beer in return.
 *
 * Modified for NOKOLino with 32MBit flash size: FLASHSIZE 0x400000
 * and -l option to show connected devices.
 */

#include <stdint.h>
#include <scsi/scsi.h>
#include <scsi/sg.h>
#include <unistd.h>
#include <endian.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <glob.h>
#include <stdarg.h>

#define FLASHSIZE 0x400000 /* 2MiB   */
#define BASE       0x40000 /* 256kiB */
#define MAXSIZE (FLASHSIZE - BASE)

#define JQ_ERASE 0xfbd8
#define JQ_WRITE 0xfbd9
#define JQ_READ  0xfd03
#define BLKSZ 0x1000
#define TIMEOUT 30000

struct jqcmd {
    uint16_t j_cmd;
    uint32_t j_off;
    uint32_t j_foo;
    uint32_t j_len;
    uint16_t j_bar;
} __attribute__((packed));

uint8_t buf[FLASHSIZE];
int force = 0;
int debugging = 0;

void
debug(const char* format, ...) {
    if (debugging) {
	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
    }
}

off_t
filesize(char *file)
{
    int result;
    struct stat buf;
    result = stat(file, &buf);
    if (result != 0) {
	err(1, "cannot stat %s", file);
    }
    return buf.st_size;
}

off_t
isdevice(char *file)
{
    int result;
    struct stat buf;
    result = stat(file, &buf);
    if (result != 0) {
	err(1, "cannot stat %s", file);
    }
    return (buf.st_rdev != 0);
}

void
w32le(uint8_t **loc, uint32_t val)
{
    uint32_t le = htole32(val);
    memcpy(*loc, &le, 4);
    (*loc) += 4;
}

void
loadbar(unsigned int x, unsigned int n)
{
    int i;
    unsigned int w = 50;
    float ratio    =  x/(float)n;
    int   c        =  ratio * w;
    
    fprintf(stderr, "\r%7d (%3d%%) [", x, (int)(ratio*100));
    for (i=0; i<c; i++) fprintf(stderr, "-");
    for (i=c; i<w; i++) fprintf(stderr, " ");
    fprintf(stderr, "]");
    fflush(stderr);
}

void
usage(void)
{
    printf("Usage: jq6500 [OPTION]... [FILE]...\n"
	   "\n"
	   "Write files to an MP3 player based on the JQ6500 chip that is connected\n"
	   "via USB. Files can be written in raw mode or as a simple file system which\n"
	   "is created on the fly.\n"
	   "The file system is needed by the device in order to play MP3 or WAV\n"
	   "files. Raw mode can be used to overwrite the ISO image in the first\n"
	   "256kiB of the device or to flash an existing file system image with audio\n"
	   "files.\n"
	   "\n"
	   "Options:\n"
	   "  -d device   SCSI generic device or file to write to (default: autodetect)\n"
       "  -l          Look for a connected device \n"
	   "  -r          write a single file in raw mode without creating a file system\n"
	   "  -o offset   default: 0x40000\n"
	   "  -s prefix   save the content of the pseudo file system on the device\n"
	   "              to a set of files named prefix-dirno-fileno\n"
	   "  -f          force operation (disables sanity checks, use with care!)\n"
	   "  -D          print additional debugging information\n"
	   );
    
    exit(1);
}

int
mkjqfs(int count, char **files, int offset)
{
    int size, i, len;
    uint8_t *dir, *data;
    memset(buf, 0xff, FLASHSIZE);

    dir = buf;
    /* 2 for main dir, 1 for length of subdir, 2 for each file */
    size = (2 + 1 + 2 * count) * sizeof(uint32_t);
    data = dir + size;

    w32le(&dir, 1);		/* Number of Subdirs */
    w32le(&dir, offset + 8);	/* Offset of first subdir */
    w32le(&dir, count);		/* Number of files in subdir 1 */

    for (i = 0; i < count; i++) {
	int fd;
	char *fname = files[i];
	len = filesize(fname);
	size += len;
	if (!force && size >= MAXSIZE) {
	    errx(1, "length %d exceeds maximum of %d\n", size, MAXSIZE);
	}
	fd = open(fname, O_RDONLY);
	if (fd < 0) 
	    err(1, "cannot open %s", fname);
	if (read(fd, data, len) != len) 
	    err(1, "cannot read %s", fname);
	close(fd);
	w32le(&dir, offset + data - buf); /* File offset */
	w32le(&dir, len);                 /* File length */
	data += len;
    }
    return size;
}

void
jqwrite(char *device, uint8_t *buf, int offset, int size)
{
    int dev, i;

    dev = open(device, O_RDWR);
    if (dev < 0)
	err(1, "cannot open device %s", device);

    fprintf(stderr, "Uploading %d bytes...\n", size);

    for (i = 0; i < size; i += BLKSZ) {
	
	struct jqcmd cmd;
	struct sg_io_hdr hdr;

	loadbar(i, size);

	memset(&cmd, 0, sizeof(cmd));
	cmd.j_cmd = htobe16(JQ_ERASE);
	cmd.j_off = htobe32(offset + i);

	memset(&hdr, 0, sizeof(hdr));
	hdr.interface_id = 'S';
	hdr.timeout = TIMEOUT;
	hdr.cmdp = (unsigned char *) &cmd;
	hdr.cmd_len = sizeof(cmd);
	hdr.dxfer_direction = SG_DXFER_NONE;

	if (ioctl(dev, SG_IO, &hdr) < 0) {
	     fprintf(stderr, "\n");
	     err(1, "erase failed at offset %x", offset + i);
	}

	memset(&cmd, 0, sizeof(cmd));
	cmd.j_cmd = htobe16(JQ_WRITE);
	cmd.j_off = htobe32(offset + i);
	cmd.j_len = htobe32(BLKSZ);

	memset(&hdr, 0, sizeof(hdr));
	hdr.interface_id = 'S';
	hdr.timeout = TIMEOUT;
	hdr.cmdp = (unsigned char *) &cmd;
	hdr.cmd_len = sizeof(cmd);
	hdr.dxfer_direction = SG_DXFER_TO_DEV;
	hdr.dxferp = buf + i;
	hdr.dxfer_len = BLKSZ;
	
	if (ioctl(dev, SG_IO, &hdr) < 0) {
	    fprintf(stderr, "\n");
	    err(1, "\nwrite failed at offset %x", offset + i);
	}
    }
    loadbar(size, size);
    fprintf(stderr, "\n");
    close(dev);
}

int
jq_identify(char *devname)
{
    int dev;
    struct sg_io_hdr hdr;
    char buf[36];
    char vendor[9], product[17], revision[5];
    uint8_t cmd[6] = {INQUIRY, 0, 0, 0, sizeof(buf), 0};
    
    debug("Identifying %s ...\n", devname);

    dev = open(devname, O_RDONLY);
    if (dev < 0) {
	debug("  open failed: %s\n", strerror(errno));
	return 0;
    }

    memset(&hdr, 0, sizeof(hdr));
    hdr.interface_id = 'S';
    hdr.timeout = TIMEOUT;
    hdr.cmdp = cmd;
    hdr.cmd_len = sizeof(cmd);
    hdr.dxfer_direction = SG_DXFER_FROM_DEV;
    hdr.dxfer_len = sizeof(buf);
    hdr.dxferp = buf;
    if (ioctl(dev, SG_IO, &hdr) < 0) {
	err(1, "INQUIRY failed");
    }
    close(dev);

    strncpy(vendor, buf + 8, sizeof(vendor)-1);
    vendor[sizeof(vendor)-1] = '\0';
    strncpy(product, buf + 16, sizeof(product)-1);
    product[sizeof(product)-1] = '\0';
    strncpy(revision, buf + 32, sizeof(revision)-1);
    revision[sizeof(revision)-1] = '\0';
    
    debug("  VENDOR='%s'\n", vendor);
    debug("  PRODUCT='%s'\n", product);
    debug("  REVISION='%s'\n", revision);
    
    return (strcmp(vendor, "YULIN   ") == 0 &&
	    strcmp(product, " PROGRAMMER     ") == 0);
}

char *
jq_find(const char *pattern)
{
    glob_t gb;
    int i, ret;
    char *devname = NULL;
    
    ret = glob(pattern, GLOB_NOSORT | GLOB_ERR, NULL, &gb);   
    if (ret != 0) {
	return NULL;
    }
    for (i = 0; i < gb.gl_pathc; i++) {
	if (jq_identify(gb.gl_pathv[i])) {
	    devname = strdup(gb.gl_pathv[i]);
	    break;
	}
    }
    globfree(&gb);

    return devname;
}

int
main(int argc, char **argv)
{
    int size, opt;
    char *device = NULL;
    char *endptr;
    int offset = BASE;
    int rawmode = 0;

    if (argc == 1) {
	usage();
    }
    
    while ((opt = getopt(argc, argv, "d:o:rs:fhDl")) != -1) {
	switch (opt) {
	case 'd':
	    device = optarg;
	    break;
	case 'o':
	    errno = 0;
	    offset = strtol(optarg, &endptr, 0);
	    if (errno != 0 || *optarg == 0 || *endptr != 0) {
		errx(1, "Invalid number: '%s'", optarg);
	    }
	    break;
	case 'r':
	    rawmode = 1;
	    break;
	case 'f':
	    force = 1;
	    break;
	case 's':
	    errx(1, "-%c: Option not implemented.", opt);
	    break;
	case 'D':
	    debugging = 1;
	    break;
    case 'l':
        device = jq_find(device ? device : "/dev/sg*");
	    if (device == NULL) {
	        errx(1, "Cannot identify a JQ6500 device.");
	    }
	    fprintf(stderr, "Found a JQ6500 module on %s.\n", device);
        return 0;
	case 'h':
	default:
	    usage();
	}
    }

    if (!force) {
	if (offset < 0 || offset >= FLASHSIZE) {
	    errx(1, "Offset out of range [0..0x%x].", FLASHSIZE);
	}
	if (offset % BLKSZ != 0) {
	    errx(1, "Offset must be a multiple of %d.", BLKSZ);
	}
    }

    if (optind == argc) {
	errx(1, "Missing file operand.");
    }

    if (force && device != NULL) {
	fprintf(stderr, "Using %s as a JQ6500 module without check.\n", device);
    } else {
	device = jq_find(device ? device : "/dev/sg*");
	if (device == NULL) {
	    errx(1, "Cannot identify a JQ6500 device.");
	}
	fprintf(stderr, "Found a JQ6500 module on %s.\n", device);
    }

    if (rawmode) {
	char *fname = argv[optind];
	int fd;
	size = filesize(fname);

	if (!force && size > FLASHSIZE) {
	    errx(1, "length %d exceeds maximum of %d\n", size, MAXSIZE);
	}
	fd = open(fname, O_RDONLY);
	if (read(fd, buf, size) != size) {
	    err(1, "cannot read %s", fname);
	}
    } else {
	size = mkjqfs(argc - optind, argv + optind, offset);
    }

    if (isdevice(device)) {
	jqwrite(device, buf, offset, size);
    } else {	
	int fd = open(device, O_WRONLY | O_CREAT, "0666");
	if (write(fd, buf, size) != size) {
	    err(1, "write failed in %s", device);
	}
    }
    
    return 0;
}

/* Local Variables:  */
/* mode: c           */
/* c-basic-offset: 4 */
/* End:              */
