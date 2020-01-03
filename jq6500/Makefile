CC=gcc
CFLAGS=$(ARCHFLAGS) -Wall -Os -g
LDFLAGS=$(ARCHFLAGS) -Wall -s
SHELL=/bin/bash
MKISOFS:=$(shell type -p mkisofs || type -p xorrisofs)

all: jq6500

iso: rescue.iso

# The minimal tool that gets into the ISO
isoroot/jq6500: jq6500.o
	$(CC) $(LDFLAGS) -o $@ $^

# The final tool with embedded ISO
jq6500: jq6500.o rescue.o
	$(CC) $(LDFLAGS) -o $@ $^

MKISOFLAGS=-quiet -no-pad -V "JQ6500" -appid "JQ6500 Upload Tools"
rescue.iso: isoroot/jq6500
ifneq (${MKISOFS},)
	${MKISOFS} -o $@ $(MKISOFLAGS) isoroot jq6500.c Makefile
else
	@ echo
	@ echo error: Please install either mkisofs or xorrisofs.
	@ echo
	@ exit 1
endif

install: jq6500
	install -m 755 -D jq6500 ${DESTDIR}/usr/bin/jq6500

%.o: %.iso
	$(LD) --relocatable -bbinary -o $@ $^

clean:
	rm -f isoroot/jq6500 rescue.iso rescue.o jq6500 jq6500.o

.PHONY: all iso clean install
