#ifndef POINTS_SEGMENTS_H
#define POINTS_SEGMENTS_H

#include <stdio.h>
#include <stdlib.h>

#define START 0
#define END 1
#define POINT 2

typedef struct point{
  int position;
  int type;
}Point;

void print_array(int *arr, int size);
void print_array_2D(int **arr, int rows, int cols);
void free_array(int **arr, int cols);

int* points_segments_naive(int ** segments, int * points, int s, int p);

void print_points(Point *points, int rows);
int compfunc(const void * pa, const void * pb);
Point * generate_point(int ** segments, int * points, int s, int p);
void points_segments_sort(int ** segments, int * points, int s, int p);
#endif
