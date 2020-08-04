#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int *count_dod( int *array, int n ){
  int *rezult = calloc(3, sizeof(int));
  int number_neg=0, number_pos=0, product_pos=1;

  for(int i=0; i < n; i++){
    if ( array[i] >= 0 ){  
      number_pos++;
      product_pos *= array[i];
    }
    else
      number_neg++;
  }
  
  rezult[0] = number_neg; rezult[1] = number_pos, rezult[2] = product_pos;
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
  printf("\n\n\tCount positiv = [%d], \n\tProduct positive = [%d]", rezult[1], rezult[2]);
  printf("\n\tCount negative = [%d]\n\n", rezult[0]);

  free(rezult);
  free(array_y);
}
