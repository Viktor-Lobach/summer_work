#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int summ_of_perimetr( int **array, int n ){ 
  int summ=0;
  n -= 1;
  for (int i=0; i < n; i++)
    summ += ( array[i][n] + array[n][i] );
  for (int i=1; i < n; i++)
    summ += array[i][n-i];
  summ += array[n][n];
  return summ;
}


int main(){
  srand(time(NULL));
  int n, m, **array=NULL;
  printf("Enter the param of matrix (n) > "); scanf("%d", &n);
  array = (int**)calloc(n, sizeof(int*) );
  if (array == NULL){
    printf("OS did not allocate memory! Sorry...");
    return 1;
  }
  printf("\nMatrix:\n");
  for (int i=0; i < n; i++) {
    array[i] = (int*)calloc(n, sizeof(int) ); 
    for (int j=0; j < n; j++) {
      array[i][j] = 1 + rand() % 15;
      printf("%4d", array[i][j]);
    }
    printf("\n");
  }
 printf("\n\tSumm perimetr = [%d]\n", summ_of_perimetr(array, n) );
 for (int i=0; i < n; i++)
   free(array[i]);
 free(array);
}
