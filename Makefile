TARGET=main
CFLAGS=-Wall -Werror
CC=gcc
ifeq (, $(shell which gcc))
CC=clang
ifeq (, $(shell which clang))
	$(error "no gcc or clang found")
endif
endif

.PHONY: all
all:
	$(CC) main.c $(CFLAGS) -o $(TARGET)

.PHONY: clean
clean:
	rm $(TARGET)
