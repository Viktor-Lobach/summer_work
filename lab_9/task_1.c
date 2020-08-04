#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int counter( int *array, int n ){
  int count=0;

  for (int i=0; i < n; i++)
    if ( array[i] % 3 != 0 )
      count++;

   return count;
}

void show( int *array, int n ){
  for (int i=0; i < n; i++)
    printf("%4d", array[i]);
}

int main(){
  srand(time(NULL));

  int n, m, *array_a=NULL, *array_b=NULL, count_a, count_b;

  printf("Enter the number of elements (n and m)) > "); scanf("%d%d", &n, &m);

  array_a = calloc(n, sizeof(int) );
  array_b = calloc(m, sizeof(int) );

  if (array_a == NULL || array_b == NULL){
    printf("OS did not allocate memory! Sorry...");
    return 1;
  }

  printf("\nArray A:\n");
  for (int i=0; i < n; i++){
    array_a[i] = rand() % 15;
    printf("%4d", array_a[i]);
  }

  printf("\n\nArray B:\n");
  for (int i=0; i < m; i++){
    array_b[i] = rand() % 15;
    printf("%4d", array_b[i]);
  } 
  
  count_a = counter( array_a, n );
  count_b = counter( array_b, m );


  if ( count_a > count_b ){
    printf("\n\nIn A array more elements( %d )!\n", count_a);
    show( array_a, n );
  }

  else if( count_b > count_a ){
    printf("\n\nIn B array more elements( %d )!\n", count_b);
    show( array_b, m );
  }

  else
     printf("\n\nOoops.... A == B\n");


  free(array_a); free(array_b);
  
  return 0;
}
