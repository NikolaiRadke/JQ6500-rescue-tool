CC=gcc
ARCHFLAGS=-m32
CFLAGS=$(ARCHFLAGS) -Wall -O0 -g
LDFLAGS=$(ARCHFLAGS) -Wall -s
all: jq6500

iso: rescue.iso

jq6500mini: jq6500.o
	$(CC) $(LDFLAGS) -o $@ $^

jq6500: jq6500.o rescue.o
	$(CC) $(LDFLAGS) -o $@ $^

rescue.iso: autorun.inf config.ini jq6500.exe Makefile jq6500mini jq6500.c
	mkisofs -o $@ -quiet -V "JQ6500" -appid "JQ6500 Upload Tools" -no-pad -graft-points \
	autorun.inf config.ini jq6500.exe Makefile jq6500=jq6500mini jq6500.c

install: jq6500
	install -m 755 -D jq6500 ${DESTDIR}/usr/bin/jq6500

%.o: %.iso
	$(CC) $(LDFLAGS) -nostdlib -Wl,--relocatable -Wl,-bbinary -o $@ $^

clean:
	rm -f jq6500mini rescue.iso rescue.o jq6500 jq6500.o

.PHONY: all iso clean install
