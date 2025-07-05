CC=cc
CFLAGS=-Wall -Wextra -std=c99
LDFLAGS=

CFLAGS += $(shell pkg-config --cflags json-c)
LDFLAGS += $(shell pkg-config --libs json-c)

manifest2md: manifest2md.c
	$(CC) manifest2md.c -o $@.o $(CFLAGS) $(LDFLAGS)
