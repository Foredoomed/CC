CC = gcc
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -Iinclude
LFLAGS = -Wall $(DEBUG)
MKDIR_P = mkdir -p

.PHONY: directories

all: directories hash stack utils interpreter main cc

directories: bin

bin :
	${MKDIR_P} bin

cc : main interpreter utils stack
	$(CC) $(LFLAGS) -o bin/cc bin/main.o bin/interpreter.o bin/utils.o bin/stack.o bin/hash.o

main : include/interpreter.h
	$(CC) $(CFLAGS) -o bin/main.o core/main.c

interpreter : include/interpreter.h include/utils.h include/type.h include/stack.h include/code.h include/hash.h
	$(CC) $(CFLAGS) -o bin/interpreter.o core/interpreter.c

utils : include/utils.h include/core.h include/code.h
	$(CC) $(CFLAGS) -o bin/utils.o core/utils.c

stack : include/stack.h
	$(CC) $(CFLAGS) -o bin/stack.o core/stack.c

hash : include/hash.h
	$(CC) $(CFLAGS) -o bin/hash.o core/hash.c


clean:
	rm -f bin/*
	rm -rf bin



