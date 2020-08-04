#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEN_STR 100

void special_func( char text_1[LEN_STR], char text_2[LEN_STR] ){
  char sep[7] = " ,./?!";
  char *ptr_str_1 = strtok(text_1, sep);
  char *ptr_str_2 = strtok(text_2, sep);
  int _iter_=0;

  while ( ptr_str_1 != NULL ){
    while ( ptr_str_2 != NULL ){
      if ( strcmp(ptr_str_1, ptr_str_2) == 0 )
        _iter_++;

      ptr_str_2 = strtok(NULL, sep);
    }
    ptr_str_1 = strtok(NULL, sep);
  }

  printf("\n Count of non unicorn elements = [%d]", _iter_);

}


void main(){

  char text_1[LEN_STR], text_2[LEN_STR];

  printf("\n\tEnnter the first text > "); gets(text_1);
  printf("\n\tEnnter the second text > "); gets(text_2);

  special_func(text_1, text_2);
}
