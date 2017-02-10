CC = gcc
CFLAGS = -std=c99 -Wall -g
CPPFLAGS = -I include/

SRC = $(wildcard src/*.c)
OBJSRC = $(SRC:.c=.o)

TEST = $(wildcard test/*.c)
OBJTEST = $(TEST:.c=.o)

all: liblist.a test
	./runtest

memory_test: test
	valgrind --leak-check=full ./runtest

liblist.a: $(OBJSRC)
	ar -rs $@ $^

test: liblist.a $(OBJTEST)
	$(CC) -o runtest $(OBJTEST) $<

-include src/depends.txt
-include test/depends.txt

src/depends.txt: $(SRC)
	$(CC) -MM $(CPPFLAGS) $^ > src/depends.txt

test/depends.txt: $(TEST)
	$(CC) -MM $(CPPFLAGS) $^ > test/depends.txt

.PHONY : clean
clean:
	rm -f liblist.a src/depends.txt test/depends.txt $(OBJSRC) $(OBJTEST) runtest
