CC = gcc
CFLAGS = -Wall -std=c99

all: test

point_segments_naive.o: points_segments_naive.c points_segments.h
	$(CC) $(CFLAGS) -c points_segments_naive.c

point_segments_sort.o: points_segments_sort.c points_segments.h
	$(CC) $(CFLAGS) -c points_segments_sort.c

test.o: test.c points_segments.h
	$(CC) $(CFLAGS) -c test.c

test: points_segments_naive.o points_segments_sort.o test.o
	$(CC) $(CFLAGS) -o test points_segments_naive.o points_segments_sort.o test.o

test2: points_segments_sort.o test.o
	$(CC) $(CFLAGS) -o test points_segments_sort.o test.o

clean:
	rm *.o test
