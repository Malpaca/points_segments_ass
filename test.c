#include "points_segments.h"

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void print_array_2D(int **arr, int rows, int cols){
	for (int i=0; i<rows; i++){
		printf("[");
		for (int j=0; j<cols; j++)
			printf("%d ",arr[i][j]);
		printf("] ");
	}
	printf("\n");
}

void free_array(int **arr, int cols){
	for (int i = 0; i < cols; i++){
		free(arr[i]);
	}
	free(arr);
}

int compare_array(int *arr1, int *arr2, int size){
	for (int i = 0; i < size; i++){
		if (arr1[i] != arr2[i]){
			return 1;
		}
	}
	return 0;
}

int main() {
	const char * files[] = {"input1.txt", "input2.txt", "input3.txt"};
	// const char * files[] = {"tryout.txt"};

	for (int f=0; f < 3; f++){
		FILE *pfile = fopen(files[f], "r");
		if(pfile == NULL)  {
			printf("Error opening file %s\n", files[f]);
			return 1;
		}

		int s, p;
		while(fscanf(pfile, "%d %d", &s, &p)!=EOF){

			//allocate 2D array to hold s segments
			int ** segments = malloc(s*sizeof(int *));
			for (int i=0; i < s; i++){
				segments[i] = malloc(2*sizeof(int));
			}

			//scan all segment lines and populate the segments
			for (int i=0; i < s; i++){
				fscanf(pfile, "%d %d", &segments[i][0], &segments[i][1]);
			}

			//allocate a single array to hold p points
			int * points = malloc(p*sizeof(int));

			//scan all point coordinates into points array
			for (int i=0; i < p; i++){
				fscanf(pfile, "%d", &points[i]);
			}

			printf("There are total %d segments, and %d points\n", s, p);

			print_array_2D(segments, s, 2);
			print_array(points, p);

			int * result_sort = points_segments_sort(segments, points, s, p);
			int * result_naive = points_segments_naive(segments, points, s, p);
			if (compare_array(result_sort, result_naive, p)){
				printf("Incorrect!\nNaive got:");
				print_array(result_naive, p);
				printf("\nBut sort got:");
				print_array(result_sort, p);
				printf("\n");
				return 0;
			} else{
				printf("Result is:");
				print_array(result_sort, p);
				printf("\n");
			}
			free_array(segments, s);
			free(points);
		}
		fclose(pfile);
	}
	return 0;
}
