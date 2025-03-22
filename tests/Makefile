CC=gcc
CFLAGS=-Wall -Wextra -O0

all: string_tests

string_tests: string_tests.c
	$(CC) $(CFLAGS) -o string_tests string_tests.c

run: string_tests
	./string_tests

clean:
	rm -f string_tests

