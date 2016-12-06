CC = gcc
CFLAGS = -std=c99 -Wall -g
CPPFLAGS = -I include/

SRC = $(wildcard src/*.c)
OBJSRC = $(SRC:.c=.o)

TEST = $(wildcard test/*.c)
OBJTEST = $(TEST:.c=.o)

all: liblist.a test
	./runtest

liblist.a: $(OBJSRC)
	ar -rs $@ $^

test: liblist.a $(OBJTEST)
	$(CC) -o runtest $(OBJTEST) $<

-include depends.txt
-include test/depends.txt

depends.txt: $(SRC)
	$(CC) -MM $(CPPFLAGS) $^ > depends.txt

test/depends.txt: $(TEST)
	$(CC) -MM $(CPPFLAGS) $^ > test/depends.txt

.PHONY : clean
clean:
	rm -f liblist.a depends.txt test/depends.txt $(OBJSRC) $(OBJTEST) runtest
