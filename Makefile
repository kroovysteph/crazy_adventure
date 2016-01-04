CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpointer-arith -Wfatal-errors -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: adventure run clean

adventure:
	$(CC) $(SOURCES) $(CFLAGS) -o $< -L../prog1lib/lib -lprog1 -lm -iquote../prog1lib/lib -o $@

run:
	./adventure

clean:
	rm adventure
