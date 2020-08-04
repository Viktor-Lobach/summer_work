#include <stdio.h>
#include <stdlib.h>

#include "../include/list.c"

#define loc(x) (*(myclass*)x->_struct_data_)


typedef struct {
  char name[20];
  int avrg_mark;
}myclass;

int check_currect(int mark){
  if (mark >= 1 && mark <= 12)
    return 1;
  return 0;
}

void add_to_list(DynamicList *head, int n){
  myclass buf_var;
  int buf_mark;
  
  for(int i=0; i < n; i++){
    system("clear");
    
    printf("\n\t-----Informatin of [%d] students------", i+1);
    printf("\n\tEnter the name of student > "); scanf("%s", buf_var.name);

    for(;;){
      printf("\tEnter the his marks       > "); scanf("%d",&buf_mark);
      if(check_currect(buf_mark)){
        buf_var.avrg_mark = buf_mark;
        break;
      }
      else
         printf("\n\tEnter the currect mark (1-12)\n");
    
    }
    push(head, &buf_var, sizeof(buf_var));
  }
}

void pushFile(DynamicList head, FILE *file_ptr){
  int buf_avrg=0, iter=0;
  
  fprintf(file_ptr, "+--------------------+--------+");
  while ( head ){
    fprintf(file_ptr, "\n|%17s   |%5d   |", loc(head).name, loc(head).avrg_mark);
    
    buf_avrg += loc(head).avrg_mark;
    iter++;

    head = head -> next;
  } 
  fprintf(file_ptr, "\n+--------------------+--------+");
  fprintf(file_ptr, "\n|----Avarage mark----|%5d   |", buf_avrg/iter);
  fprintf(file_ptr, "\n+--------------------+--------+");


  if (head == NULL)
    printf("\n\n\tYour list append in File!\n");
}

void main(){
  DynamicList head = initList();
  
  FILE *new_open_file = fopen("task_1.txt", "w");
  if (new_open_file == NULL){
    fprintf(stderr, "\n\tFile don`t open. Exit...");
    exit(1);
  }

  int n;
  printf("Enter the number of students > "); scanf("%d", &n);
  
  add_to_list(&head, n);  

  pushFile(head, new_open_file);

  deleteList(&head);
}
