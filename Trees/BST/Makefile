CC = gcc
CFLAGS = -Wall -Werror

main: main.o BSTree.o BSTPrint.o BSTBalance.o BSTProperty.o
	$(CC) $(CFLAGS) -o main main.o BSTree.o BSTPrint.o BSTBalance.o BSTProperty.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

BSTree.o: BSTree.c BSTree.h
	$(CC) $(CFLAGS) -c BSTree.c

BSTPrint.o: BSTPrint.c BSTPrint.h
	$(CC) $(CFLAGS) -c BSTPrint.c

BSTBalance.o: BSTBalance.c BSTProperty.c BSTree.c BSTree.h
	$(CC) $(CFLAGS) -c BSTBalance.c

BSTProperty.o: BSTProperty.c BSTree.c BSTProperty.h
	$(CC) $(CFLAGS) -c BSTProperty.c

clean:
	rm -rf *.o main