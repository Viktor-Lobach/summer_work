#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void viev_table(int **matrix, int n, int k ){
  printf("\n\t+---+----+----+----+----+----+----+");
  printf("\n\t|n\\k|--1-|--2-|--3-|--4-|--5-|--6-|");
  printf("\n\t+---+----+----+----+----+----+----+");
  
 for (int i=0; i < n; i++) {
    printf("\n\t|-%d-", i+1);
    
    for (int j=0; j < k; j++)
      printf("| %d ", matrix[i][j]);
    
    printf("|");
  }
  printf("\n\t+---+----+----+----+----+----+----+\n");
}

void find_print_summ(int **matrix, int k ){
  int summ = 0;

  for (int i=0; i < k; i++)
    summ += ( matrix[0][i] + matrix[2][i] );
  
  printf("\t|Summ >  |%24d|\n", summ);
  
  printf("\t+--------+------------------------+\n\n");

}

int main(){
  srand(time(NULL));
  int n=5, k=6, **matrix=NULL;


  matrix = (int**)calloc(n, sizeof(int*) );
  if (matrix == NULL){
    printf("\nOS did not allocate memory! Sorry...");
    return 1;
  }

  for (int i=0; i < n; i++) {
      matrix[i] = (int*)calloc(k, sizeof(int) );
      for (int j=0; j < k; j++)
        matrix[i][j] = 10 + rand() % 80;
  }

  viev_table(matrix, n, k);
   find_print_summ(matrix, k);


  for (int i=0; i < n; i++)
    free(matrix[i]);

  free(matrix);
}
