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
    if ( istr == NULL )
      strcat(final_str, ptr_str_1);
    
    ptr_str_1 = strtok(NULL, sep);
  }

  FILE *ptr_file = fopen(_oupt_name_, "w");
    fprintf(ptr_file, "%s", final_str);
  fclose(ptr_file);

}

void get_file(char _inpt_name_[20], char _oupt_name_[20]){
  char first_sen[20], second_sen[20];
  
  FILE *ptr_file = fopen(_inpt_name_, "r");
    fgets(first_sen, LEN_STR-1, ptr_file);
    fgets(second_sen, LEN_STR-1, ptr_file);
  fclose(ptr_file);
  
  special_func(first_sen, second_sen, _oupt_name_);
}

void main(){

    char fir_str[LEN_STR], sec_str[LEN_STR];

    printf("\n\tEnter the first string > "); gets(fir_str);
    printf("\n\tEnter the second string > "); gets(sec_str);

    special_func(fir_str, sec_str, "done_task_2.txt");

}
