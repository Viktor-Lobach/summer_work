#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int find_max( int *array, int n ){
  int max = array[0];
  
  for (int i=0; i < n; i++)
    if (array[i] > max)
       max = array[i];

   return max;
}

int current_summ( int *array, int n ){
  int summ=0;

  for (int i=0; i < n; i++)
    if (array[i] > 0){
      for (int j=i+1; j < n; j++){
        if (array[j] < 0)
           summ+= array[j];
        else
           break;
      }
      break;
    }

  return summ;
}

int main(){
  srand(time(NULL));
  int n, *array=NULL;

  printf("Enter the param of array (n) > "); scanf("%d", &n);

  array = (int*)calloc(n, sizeof(int) );
  if (array == NULL){
    printf("OS did not allocate memory! Sorry...");
    return 1;
  }

  printf("\nInput array:\n"); 
  for (int i=0; i < n; i++) {
      array[i] = -15 + rand() % 30;
      printf("%4d", array[i]);
  }

  printf("\n\tMax = [%d]", find_max(array, n));
  printf("\n\tCurrent summ = [%d]\n", current_summ(array, n));

  free(array);
}
