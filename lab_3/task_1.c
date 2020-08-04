#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void matrix_statistics( int **array, int n, int m ){
  int min_value = array[0][0], max_value = array[0][0];
  float avarage;
  for (size_t i=0; i < n; i++)
    for (size_t j=0; j < m; j++) {
      if ( array[i][j] > max_value )
        max_value = array[i][j]; 
      if ( array[i][j] < min_value )
        min_value = array[i][j];
    }
  avarage = (min_value+max_value)/2;
  printf("\n\tMin = [%d]", min_value);
  printf("\n\tMax = [%d]", max_value);
  printf("\n\tAvarage = [%0.2f]", avarage );
}

int main(){
  srand(time(NULL));
  int n, m, **array=NULL;
  printf("Enter the param of matrix (n amd m) > "); scanf("%d%d", &n, &m);
  array = (int**)calloc(n, sizeof(int*) );
  if (array == NULL){
    printf("OS did not allocate memory! Sorry...");
    return 1;
  }
  printf("\nMatrix:\n");
  for (int i=0; i < n; i++) {
    array[i] = (int*)calloc(m, sizeof(int) ); 
    for (int j=0; j < m; j++) {
      array[i][j] = 1 + rand() % 15;
      printf("%4d", array[i][j]);
    }
    printf("\n");
  }
  matrix_statistics(array, n, m);
  for (int i=0; i < n; i++)
    free(array[i]);
  free(array);
  return 0;
}
