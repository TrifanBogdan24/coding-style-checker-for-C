CC = gcc
CFLAGS = -Wall -g
EXC = coding_style

build:
	$(CC) $(CFLAGS) -o $(EXC) checker.c

clean:
	rm -f *.o exec $(EXEC)

archive:
	rm -r coding_style.zip
	zip -r *.c *.h README.md README Makefile
