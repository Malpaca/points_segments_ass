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
  return a.position - b.position;
}

Point * generate_point(int ** segments, int * points, int s, int p){
  Point * whole = malloc((2*s+p) * sizeof(Point));
  for (int i = 0; i < s; i++){
    whole[2*i] = (Point){segments[i][0], START};
    whole[2*i+1] = (Point){segments[i][1], END};
  }
  for (int i = 2*s; i < 2*s+p; i++){
    whole[i] = (Point){points[i-2*s], POINT};
  }
  return whole;
}

int solve(Point * whole, int size){
  int count = 0;
  int max = 0;
  for (int i = 0; i < size; i++){
    if (whole[i].type == START) count+=1;
    if (whole[i].type == END) count -=1;
    if (whole[i].type == POINT){
      if (max < count) max = count;
    }
  }
  return max;
}

void points_segments_sort(int ** segments, int * points, int s, int p){
  Point * whole = generate_point(segments, points, s, p);
  qsort(whole, 2*s+p, sizeof(Point), compfunc);
  print_points(whole, 2*s+p);
  int result = solve(whole, 2*s+p);
  printf("%d\n", result);
  free(whole);
}
