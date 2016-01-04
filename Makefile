CC = gcc
LINKER = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpointer-arith -Wfatal-errors -I$(IDIR)
DEBUG = -g

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

# disable default suffixes
.SUFFIXES:

# pattern rule for compiling .c-file to executable
adventure:
	$(CC) $(SOURCES) $(CFLAGS) $(DEBUG) $< -L../prog1lib/lib -lprog1 -lm -iquote../prog1lib/lib -o $@

# do not treat "clean" as a file name
.PHONY: clean 

# remove produced files, invoke as "make clean"
clean: 
	rm -f *.o
	rm -rf *.dSYM
	rm -f *.exe
	rm .DS_Store
