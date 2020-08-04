#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEN_STRING 100

void check_word( char input_str[LEN_STRING] ){
  int _iter_, verify;
  char _sep_[7] = " ,./?!";
  char *ptr_str = strtok(input_str, _sep_);

  printf("Currect words: ");

  while( ptr_str != NULL){
    _iter_ = strlen(ptr_str);
    for (int i=0; i < _iter_; i++)
      if (ptr_str[i] >=65 && ptr_str[i] <= 122)
        verify++;
    if (verify == _iter_)
      printf("\n\t[%s]", ptr_str);

    verify = 0;
    ptr_str = strtok(NULL, _sep_);
  }
}


void main(){

  char check_str[LEN_STRING] = "This is правельні words";

  check_word( check_str );

  printf("\n");
}
