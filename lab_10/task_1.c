#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct name{
  char name[25];
  char surname[25];
}FullName;


typedef struct dataList{
  FullName first;
  FullName second;
  char city[12];
  int marks[10];
}DataList;


void avarage_city( DataList *head, char *name_city, int n ){
  int avrg_mark = 0, iter_var=0;

  for ( int i=0; i<n; i++ )
    if ( strcmp(head[i].city, name_city) == 0){
      printf("\n\tName - [%s] and [%s]", head[i].first.name, head[i].second.name);
      iter_var++;

      for (int j=0; j<10; j++)
         avrg_mark += head[i].marks[j];
    }

  avrg_mark /= (n*10);
  printf("\n\tAvarage mark for [%s] = [%d]", name_city, avrg_mark);
  printf("\n\tNumber of participant = [%d]", iter_var);
}


void main(){

  int n; 
  char buf_var[25];

  printf("Enter the number of struct elements > "); scanf("%d", &n);

  DataList *head=(DataList*)calloc(n, sizeof(DataList) );

  for (int i=0; i < n; i++){
    printf("---Information of [%d] team---", i+1);

    printf("\n\tEnter the I name > "); scanf("%s", head[i].first.name);
    printf("\tEnter the I surname > "); scanf("%s", head[i].first.surname);
    printf("\tEnter the II name > "); scanf("%s", head[i].second.name);
    printf("\tEnter the II surname > "); scanf("%s", head[i].second.surname);
    printf("\tEnter the city > "); scanf("%s", head[i].city);

    for (int j=0; j < 10; j++)
      head[i].marks[j] = 1 + rand() % 11;

    system("clear");
  }
  
  printf("\nEnter a city to determine the number of participant > ");
  scanf("%s", buf_var);

  avarage_city(head, buf_var, n);

    free(head);

  printf("\n");
}
