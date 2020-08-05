#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEN_STR 100

void special_func( char text_1[LEN_STR], char text_2[LEN_STR], char _oupt_name_[20] ){
  char sep[7] = " ,./?!";
  char *ptr_str_1 = strtok(text_1, sep);
  char final_str[LEN_STR];
  char *istr;


  while ( ptr_str_1 != NULL ){
    istr = strstr(text_2, ptr_str_1);
    if ( istr == NULL ){
      strcat(final_str, ptr_str_1);
      strcat(final_str, " ");
    }
    ptr_str_1 = strtok(NULL, sep);
  }

  FILE *ptr_file = fopen(_oupt_name_, "w");
    fprintf(ptr_file, "%s", final_str);
  fclose(ptr_file);

  printf("\n\n-----------Done-------------");
}

void get_file(char _inpt_name_[20], char _oupt_name_[20]){
  char first_sen[LEN_STR], second_sen[LEN_STR];
  
  FILE *ptr_file = fopen(_inpt_name_, "r");
    fgets(first_sen, LEN_STR-1, ptr_file);
    fgets(second_sen, LEN_STR-1, ptr_file);
  fclose(ptr_file);

  special_func(first_sen, second_sen, _oupt_name_);
}

void main(){

    char inpt[LEN_STR], oupt[LEN_STR];

    printf("\tEnter the input file > "); gets(inpt); 
    printf("\tEnter the output file > "); gets(oupt);

    get_file(inpt, oupt);
}
