AR = ar
CFLAGS = -Wall -g
CC = gcc

all: mains maind

#dynamic
maind: main.o libmyBank.so
	$(CC) $(CFLAGS) -o maind main.o ./libmyBank.so

#static
mains: main.o libmyBank.a
	$(CC) $(CFLAGS) -o mains main.o libmyBank.a

#creating dynamic lib .so
libmyBank.so: myBank.o
	$(CC) -shared -o libmyBank.so myBank.o

#creating dynamic lib .a
libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a myBank.o

main.o: main.c myBank.h
	$(CC) $(CFLAGS) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(CFLAGS) -c myBank.c

.PHONY: clean

clean:
	rm -rf *o *so *a mains maind
