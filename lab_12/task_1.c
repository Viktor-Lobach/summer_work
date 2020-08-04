#include <stdlib.h>
#include <stdio.h>

#include "../include/list.c"
#include "../include/function.h"

#define loc(x) (*(mylist*)x -> _struct_data_)

typedef struct data{
  float var;
}mylist;

float avrg_in_list(DynamicList head){
  int count=0, summ=0;

  while ( head ){
    summ += loc(head).var;
    count++;

    head = head -> next;
  }

  return summ/count;
}

void insert_number(DynamicList head, float var){
  while (head->next){
    if ( loc(head->next).var < var )
      pop(head);
    else 
      head = head -> next;
  }
}

void print_list(DynamicList head){
  printf("\nYour list: \n");
  while ( head ){
    printf("  %0.2f", loc(head).var);


    head = head -> next;
  }
  printf("\n");
}


int main(){
  mylist buf_var;

  float number;
  DynamicList head = initList();

  for (int i=0; i<5; i++){
    buf_var.var = (float)i;

    push(&head, &buf_var, sizeof(buf_var));
    pushBack(head, &buf_var, sizeof(buf_var));
  }
  print_list(head);

  printf("\tAvarage = [%0.2f]\n", avrg_in_list(head));
  printf("\tEnter the number > "); scanf("%f", &number);
  
  insert_number(head, number);

  print_list(head);

  deleteList(&head);
}
