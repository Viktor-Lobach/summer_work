#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/list.c"
#define LEN_STRING 100
#define loc(x) (*(myword*)x -> _struct_data_)

typedef struct word_param{
  char word[15];
  int _len_;
}myword;


myword get_word_struct( char inpt_str[LEN_STRING] ){
  char _sep_[7] = " ,.?!/", local_str[LEN_STRING];
  strcpy(local_str, inpt_str);
  char *ptr_str = strtok(local_str, _sep_);
  myword fir_max, sec_max, buffer;


  strcpy(fir_max.word, ptr_str);
  fir_max._len_ = strlen(ptr_str);
  
  ptr_str = strtok(NULL, _sep_);
  strcpy(sec_max.word, ptr_str);
  sec_max._len_ = strlen(ptr_str);

  if (fir_max._len_ < sec_max._len_){
    buffer = fir_max;
    fir_max = sec_max;
    sec_max = buffer;
  }

  ptr_str = strtok(NULL, _sep_);
  while ( ptr_str != NULL ){
    if ( strlen(ptr_str) > fir_max._len_ ){
      strcpy(fir_max.word, ptr_str);
      fir_max._len_ = strlen(ptr_str);
    }

    else if ( strlen(ptr_str) > sec_max._len_ ){
      strcpy(sec_max.word, ptr_str);
      sec_max._len_ = strlen(ptr_str);
    }

    ptr_str = strtok(NULL, _sep_);
  }
  return sec_max;
}


void get_word_list(DynamicList *head, myword sec_max, char inpt_str[LEN_STRING] ){
  char _sep_[7] = " .,?!/";
  char *ptr_str = strtok(inpt_str, _sep_);
  myword buffer;

  while ( ptr_str != NULL){
    if ( strlen(ptr_str) == sec_max._len_ ){
      strcpy(buffer.word, ptr_str);
      buffer._len_ = strlen(ptr_str);

      push(head, &buffer, sizeof(myword));
    }

    ptr_str = strtok(NULL, _sep_);
  }
  
}


void print_word_in_file( DynamicList head, char _file_output_name_[20], int n ){
  FILE *file_ptr = fopen(_file_output_name_, "a");

  fprintf(file_ptr, "\n");
  fprintf(file_ptr, "In [%d] string, words: ", n);  

  while ( head ){
    fprintf( file_ptr, " %s ", loc(head).word );

    head = head -> next;
  }
  fclose(file_ptr);
}


void open_file( char _file_input_name_[20], char _file_output_name_[20] ){
  FILE *file_ptr = fopen(_file_input_name_, "r");
  FILE *buf_file = fopen(_file_output_name_, "w"); 
  fclose(buf_file);

  char buf_str[LEN_STRING];
  DynamicList head_file;
  myword second_word;
  int n = 0;

  while ( fgets(buf_str, LEN_STRING-1, file_ptr) != NULL ){
    head_file = initList();

    second_word = get_word_struct( buf_str );
    get_word_list( &head_file, second_word, buf_str );
    n++;

    print_word_in_file( head_file, _file_output_name_, n );
  
    deleteList(&head_file);
  }

  fclose(file_ptr);

  printf("\n\n\t-----------Done!-----------");
}


void main(){
  char inpt[20], oupt[20];

  printf("\nEnter the input file name  > "); scanf("%s", inpt);
  printf("\nEnter the output file name > "); scanf("%s", oupt);

  open_file(inpt, oupt);

}
