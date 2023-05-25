CC = gcc
CFLAGS = -Wall -g
EXC = coding_style

build:
	$(CC) $(CFLAGS) -o $(EXC) checker.c
build: checker

checker: checker.o liner.o byte_string.o
	$(CC) $(CFLAGS) -o $(EXC) checker.o liner.o byte_string.o

checker.o: checker.c liner.h byte_string.h macrouri.h
	$(CC) $(CFLAGS) -c checker.c

liner.o: liner.c liner.h byte_string.h	macrouri.h
	$(CC) $(CFLAGS) -c liner.c

byte_string.o: byte_string.c byte_string.h macrouri.h
	$(CC) $(CFLAGS) -c byte_string.c


clean:
	rm -f *.o exec $(EXEC)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXC) $< $(filter-out $@,$(MAKECMDGOALS))

archive:
	rm -r coding_style.zip
	zip -r *.c *.h README.md README Makefile
