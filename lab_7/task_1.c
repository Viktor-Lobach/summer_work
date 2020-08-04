#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int *count_dod( int *array, int n ){
  int *rezult = calloc(2, sizeof(int));
  int count=0, dod=1;

  for(int i=0; i < n; i++){
    if ( array[i] < 0 )
      dod *= array[i];
    else
      count++;
  }
  
  rezult[0] = count; rezult[1] = dod;
  return rezult;
}


void main(){
  srand(time(NULL));
  int *array_y = NULL, len_arr, *rezult;
  
  printf("\n\tEnter the number of array: "); scanf("%d", &len_arr);
  array_y = (int*)calloc(len_arr, sizeof(int));
  
  printf("\nArray Y:\n\t");
  for(int i=0; i < len_arr; i++){
    array_y[i] = -10 + rand() % 20;
    printf("%4d", array_y[i]);
  }

  rezult = count_dod( array_y, len_arr );
  printf("\n\n\tCount pozitiv = [%d], \n\tProduct negative = [%d]\n\n", rezult[0], rezult[1]);


  free(rezult);
  free(array_y);
}
