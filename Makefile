CC=cc
CFLAGS=-Wall -Wextra -std=c99
LDFLAGS=

CFLAGS += $(shell pkg-config --cflags json-c)
LDFLAGS += $(shell pkg-config --libs json-c)

json2md: json2md.c
	$(CC) json2md.c -o json2md.o $(CFLAGS) $(LDFLAGS)
