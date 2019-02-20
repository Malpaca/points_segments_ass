#include "points_segments.h"

void print_points(Point *points, int rows){
	for (int i=0; i<rows; i++){
		printf("[%d,%d] ", points[i].position, points[i].type);
	}
	printf("\n");
}

int compfunc(const void * pa, const void * pb){
    Point a = *(Point *)pa;
    Point b = *(Point *)pb;
  // printf("%d, %d, %d\n", a.position,b.position, a.position - b.position);
  int result = a.position - b.position;
  if (result == 0){
    return a.type - b.type;
  }
  return result;
}

Point * generate_point(int ** segments, int * points, int s, int p){
  Point * whole = malloc((2*s+p) * sizeof(Point));
  for (int i = 0; i < s; i++){
    whole[2*i] = (Point){segments[i][0], START, -1};
    whole[2*i+1] = (Point){segments[i][1], END, -1};
  }
  for (int i = 0; i < p; i++){
    whole[i+2*s] = (Point){points[i], POINT, i};
  }
  return whole;
}

int* solve(Point * whole, int size, int p){
  int count = 0;
  int *overlaps = malloc(sizeof(int)*p);
  for (int i = 0; i < size; i++){
    if (whole[i].type == START) count+=1;
    if (whole[i].type == POINT){
      overlaps[whole[i].index] = count;
    }
    if (whole[i].type == END) count -=1;
  }
  return overlaps;
}

int * points_segments_sort(int ** segments, int * points, int s, int p){
  Point * whole = generate_point(segments, points, s, p);
  qsort(whole, 2*s+p, sizeof(Point), compfunc);
  print_points(whole, 2*s+p);
  int* result = solve(whole, 2*s+p, p);
  // print_array(result, p);
  free(whole);
  return result;
}
