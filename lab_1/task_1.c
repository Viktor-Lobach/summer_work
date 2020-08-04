#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int check_entry( float x, float y){
  if ( x>=0 && y>=0 && pow(x, 2)+pow(y, 2)<=1 )
    return 1;
  if ( x<=0 && y>=0 && pow(x, 2)+pow(y, 2)<=1 && y>-x )
    return 1;
  
  return 0;
}


int main(){
  float x, y;
  
  printf("Input X cords > "); scanf("%f", &x);
  printf("Input Y cords > "); scanf("%f", &y);

  if ( check_entry(x, y) )
    printf("\n\tYes! This point belongs to the selected area!");
  else
    printf("\n\tSorry!");

  printf("\n");
  return 1;
}
