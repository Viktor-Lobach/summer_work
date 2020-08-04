#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void special_function(char str_check[50]){
  char sep[6] = " ,.?!";
  int min=99, max=0;
  char *ptr_str = strtok(str_check, sep);

  while ( ptr_str != NULL ){
    if (strlen(ptr_str) > max)
      max = strlen(ptr_str);
    
    if (strlen(ptr_str) < min)
      min = strlen(ptr_str);

    ptr_str = strtok(NULL, sep);
  }
  
  printf("\n\tMin = [%d]\n\tMax = [%d]\n", min,max);
}

void main(){
  char buf[50] = "Mathematic – a queen of the science";
  special_function(buf);

  
}
