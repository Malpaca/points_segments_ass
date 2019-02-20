#include "points_segments.h"

int* points_segments_naive(int ** segments, int * points, int s, int p){
  int *overlaps = malloc(sizeof(int)* p);
  for (int i = 0; i < p; i++){
    int count = 0;
    for (int j = 0; j < s; j++){
      if (points[i] >= segments[j][0] && points[i] <= segments[j][1]) count ++;
    }
    overlaps[i] = count;
  }
  // print_array(overlaps, p);
  return overlaps;
}
