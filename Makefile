CC := gcc
CFLAGS := -Wall -std=c11 -lm -g -ftest-coverage
CFILES := src/main.c src/parser.c
OBJECT_FILES := main.o parser.o

Program:
	@make obj
	$(CC) $(OBJECT_FILES) $(CFLAGS) -o build/build.out
#
#	Program starts here
#
	@echo ---------------
	./build/build.out help
	@echo ---------------
	@make cleanup

obj:
	$(CC) src/main.c $(CFLAGS) -c
	$(CC) src/parser.c $(CFLAGS) -c

cleanup:
	@rm *o