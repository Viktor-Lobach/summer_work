#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void create_vector( int **array, int *vector, int n, int m ){
  int max_mtx;

  for (int i=0; i < n; i++){
    max_mtx = array[i][0];
    for (int j=0; j < m; j++)
      if ( array[i][j] > max_mtx )
        max_mtx = array[i][j];

    vector[i] = max_mtx;
  }

}

int main(){
  srand(time(NULL));
  int n, m, **array=NULL, *rezult_vector=NULL, param_search, summ=0;

  printf("Enter the param of matrix (n and m) > "); scanf("%d%d", &n, &m);
  printf("Enter the param > "); scanf("%d", &param_search);

  rezult_vector = (int*)calloc(n, sizeof(int) );
  array = (int**)calloc(n, sizeof(int) );
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
  create_vector( array, rezult_vector, n, m );

  for (int i=0; i < n; i++){
    for (int j=0; j < m; j++)
      if (array[i][j] < param_search)
        summ += array[i][j];
  }

  printf("\nCreated vector: ");
  for (int i=0; i < n; i++)
    printf("%4d", rezult_vector[i]);

  printf("\nFind sum =        [%d]", summ);


  for (int i=0; i < n; i++)
    free(array[i]);

  free(array);
  free(rezult_vector);

  printf("\n");
  }
