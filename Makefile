CFLAGS = -Wall -Wextra -pedantic

wash: main.o file.o
	gcc $(CFLAGS) -0 wash main.o file.o

wash_main.o: main.c file.h
	fcc $(CFLAGS) -c main.c

wash.o: file.c file.h
	gcc $(CFLAGS) -c file.c

clean:
	rm -f file *.o
