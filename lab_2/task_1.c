#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double avarage_square( int *array, int n ){
  int summ=0, iter_index=0;
  double rezult;

  for ( int i=0; i < n; i++ )
    if ( array[i] % 2 == 0 ){
      iter_index++;
      summ += pow(array[i], 2);
    }
  
  rezult = sqrt( summ/iter_index );
  return rezult;
}

int main(){
  srand(time(NULL));

  int n, *array=NULL;

  printf("Enter the number of elements > "); scanf("%d", &n);

  array = calloc(n, sizeof(int) );
  if (array == NULL){
    printf("OS did not allocate memory! Sorry...");
    return 1;
  }

  for (int i=0; i < n; i++) {
    array[i] = rand() % 15;
    printf("%4d", array[i]);
  }

  printf("\n\tStandart square - %0.2f\n", avarage_square(array, n));

  free(array);
  return 0;
}
