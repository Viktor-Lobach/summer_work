#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SWAP(A, B) { int t = A; A = B; B = t; }


void bubble_array_sort(int *array, int n)
{
  int nn;
  do {
    nn = 0;
    for (size_t j = 1; j < n; ++j)
      if (array[j-1] < array[j]) {
        SWAP( array[j-1], array[j] );
        nn = j;
      }
    n = nn;
  } while (n);
}

int main(){
  srand(time(NULL));
  int n, *array=NULL, summ=0;
  printf("Enter the number of elements( more 5 ) > "); scanf("%d", &n);
  array = calloc(n, sizeof(int) );
  if (array == NULL){
    printf("OS did not allocate memory! Sorry...");
    return 1;
  }
  printf("\nArray:\n");
  for (int i=0; i < n; i++) {
    array[i] = rand() % 15;
    printf("%4d", array[i]);
  }
  bubble_array_sort( array, n );
  printf("\n\n5 max elements:\n");
  for (size_t i=0; i < 5; i++){
    printf("%4d", array[i]);
    summ += array[i];
  }
  printf("\n\nSumm = %d\n", summ);
  free(array);
  return 0;
}
