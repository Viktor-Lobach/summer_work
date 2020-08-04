#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct index_position{
  int i;
  int j;
}matrix;


void inplace_matrix( int **array, int n, int m ){
  matrix min_indx;
  max_indx.i = 0; max_indx.j = 0;


  for (int i=0; i < n; i++)
    for (int j=0; j < m; j++)
      if ( array[i][j] > array[max_indx.i][max_indx.j] ){
        max_indx.i = i;
        max_indx.j = j;
      }

  array[max_indx.i][max_indx.j] = 0;
}

int main(){
  srand(time(NULL));
  int n, m, **array=NULL;

  printf("Enter the param of matrix (n and m) > "); scanf("%d%d", &n, &m);

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

 
 for (size_t i=0; i < 2; i++)
   inplace_matrix( array, n, m );

 printf("\nNew Matrix:\n");
 for (int i=0; i < n; i++) {
    for (int j=0; j < m; j++)
      printf("%4d", array[i][j]);
    
    printf("\n");
  }

 for (int i=0; i < n; i++)
   free(array[i]);
 
 free(array);
}
