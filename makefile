TARGET=main
CC=gcc
OBJS= main.o cache.o mmu.o input.o
all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
	rm -f *.o
	./main
 
main.o: main.c
	$(CC) -c  main.c -o main.o

cache.o: lib/cache.c
	$(CC) -c  lib/cache.c  -o cache.o

mmu.o: lib/mmu.c
	$(CC) -c  lib/mmu.c  -o mmu.o

input.o: input/input.c
	$(CC) -c  input/input.c  -o input.o

