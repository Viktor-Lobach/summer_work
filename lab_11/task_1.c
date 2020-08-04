#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#include "../include/list.c"

#define loc(x) (*(mystuff*)x -> _struct_data_)
#define pos(x) (*(my_pos*)x -> _struct_data_)


typedef struct core_stuff{
  char surname[15];
  char sex;
  char position[15];
  int wage;
}mystuff;

typedef struct position{
  char name_pos[20];
  int count_man;
  int summ_wage;
}my_pos;


void man_highest_wage(DynamicList head){
  int max_wage=0, buf_input;
  mystuff buf_var;

  while ( head ){
    if ( loc(head).sex == 'f' && loc(head).wage > max_wage ){
      max_wage = loc(head).wage;
      buf_var = loc(head);
    }
    
    head = head -> next;
  }

  printf("\n1) Man with highest wage - [%s], His salary = [%d]", 
         buf_var.surname, buf_var.wage);

}

void avarage_wage(DynamicList head){
  int counter=0, avg_wage=0, buf_input;

  while ( head ){
    avg_wage += loc(head).wage;
    counter++;

    head = head -> next;
  }

  printf("\n\n2) Avarage wage = [%d]\n", (avg_wage/counter) );
}

void avarage_wage_position( DynamicList head ){
  DynamicList position = initList();
  DynamicList iter = NULL;
  my_pos buf_var;

  int buf_input;

  while ( head ){
    iter = position;
    buf_input = 0;

    while ( iter ){
      if( strcmp( loc(head).position, pos(iter).name_pos ) == 0 ){
        pos(iter).summ_wage += loc(head).wage;
        pos(iter).count_man++;
        buf_input = 1;
      }
      iter = iter -> next;
    }
    
    if ( buf_input == 0 ){
      strcpy(buf_var.name_pos, loc(head).position);
      buf_var.count_man = 1;
      buf_var.summ_wage = loc(head).wage;

      push(&position, &buf_var, sizeof(my_pos));
    }

    head = head -> next;
  }
  
  printf("\n3)---Avarage selary on the position-------");
  printf("\n\t+------------+------------------+");
  printf("\n\t|----name----|---Avarage wage---|");
  printf("\n\t+------------+------------------+");

  while ( position ){
    printf("\n\t|%10s  |%11d       |", pos(position).name_pos, pos(position).summ_wage/pos(position).count_man);
    
    position = position -> next;
  }
  printf("\n\t+------------+------------------+");
  
}

void min_wage_group( DynamicList head ){
  int min_man=0, min_woman=0, buf_input;

  while ( head ){
    if ( loc(head).sex == 'f' ){
      if (min_man == 0)
        min_man = loc(head).wage;
      else
        if ( loc(head).wage < min_man )
          min_man = loc(head).wage;
    }
    
    else if ( loc(head).sex == 'm' ){
      if (min_woman == 0)
        min_woman = loc(head).wage;
      else
        if ( loc(head).wage < min_woman )
          min_woman = loc(head).wage;
    }
    head = head -> next;
  }

  printf("\n\n4)----Lowest salary in the group-------");
  printf("\n\t+-----------+------------+");
  printf("\n\t|----Man----|%8d    |", min_man);
  printf("\n\t+---Woman---+%8d    |", min_woman);
  printf("\n\t+-----------+------------+\n");

}


void add_to_list(DynamicList *head){
  mystuff local_var;


  printf("\n\tEnter the surname >  "); scanf("%s", local_var.surname);
  printf("\tEnter the sex(m/f)  >  "); scanf("%s", &local_var.sex);
  printf("\tEnter the position  >  "); scanf("%s", local_var.position);
  printf("\tEnter the wage      >  "); scanf("%d", &local_var.wage);

  push(head, &local_var, sizeof(local_var));
} 

void input_file( DynamicList *head, char name_file[30] ){
  mystuff local_var;
  FILE *file = fopen(name_file, "r");
  
  while ( fscanf(file, "%s %s %s %d", local_var.surname, &(local_var.sex), local_var.position, &local_var.wage) != EOF ){
     push( head, &local_var, sizeof(mystuff) );
  }

  fclose(file);
}


int main(int args, char* argc[]){
  DynamicList head = initList();
  int buf_var;

  printf("\n\tEnter number command:\n\t\t1 - Read from file\n\t\t2 - Live input\n\t\t> ");
  scanf("%d", &buf_var);
  
  switch ( buf_var ){
    case 1:
      input_file(&head, "input.txt");
      break;
    
    case 2:    
      printf("\n\nEnter the number of stuff > "); scanf("%d",& buf_var);
      for (size_t i=0; i<buf_var; i++)
        add_to_list(&head);    
      break;

    default:
      printf("\t\tIDR this command, sorry....\n");
      return 1;
  }

  man_highest_wage( head );
  avarage_wage( head );
  avarage_wage_position( head );
  min_wage_group( head );
  deleteList( &head );


  return 0;
}
