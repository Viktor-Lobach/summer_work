#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEN_STR 40
char *gets(char *str);
  
void param_str( char full_name[LEN_STR] ){
  int _iter_ = 0, len;
  char *check_str = strpbrk(full_name, "a");
  
  while ( check_str ){
    _iter_++;
    check_str++;
    check_str = strpbrk(check_str, "a");
  }

  len = strlen(full_name);
  printf("\n\tLength string = [%d], count 'a' = [%d]\n", len, _iter_);
}

void standart_function( char full_name[LEN_STR] ){
  char *ptr_str = strtok(full_name, " ");
  int iter=0;  

  while ( ptr_str != NULL ){
    if ( iter == 0 ){
      printf("\nUsed standart function:\n\t%s", ptr_str);
      iter++;
    }

    else{
      printf(" %c.", ptr_str[0]);
      iter++;
    }
    ptr_str = strtok(NULL, " ");
  }
  printf("\n");
}

void array_symbol( char full_name[LEN_STR]){
  int len = strlen(full_name);
  int check_space=0;

  printf("\n\nArray symbol:\n\t");
  for (int i=0; i < len; i++){
     if (full_name[i] == ' ') {
       i++;
       printf(" %c.", full_name[i]);
       check_space++;
     }
     
     else if (check_space == 0)
       printf("%c", full_name[i]);
  }
  printf("\n");
}

void main(){

  char full_name[LEN_STR];
  printf("\n\tEnter the full name\n\t\t> "); gets(full_name);
  
  param_str(full_name);
  array_symbol(full_name);
  standart_function(full_name);
}
