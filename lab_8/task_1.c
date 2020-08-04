#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int quarter( int x, int y ){
  if (x > 0 && y > 0)
    return 1;
  
  if (x < 0 && y > 0)
    return 2;
  
  if (x < 0 && y < 0)
    return 3;
  
  if (x > 0 && y < 0)
    return 4;
}

void translate( int point ){
  switch( point ){
    case 1:
      printf("\n\tFirst quarter!");
      break;
    
    case 2:
      printf("\n\tSecond quarter!");
      break;

    case 3:
      printf("\n\tThird quarter!");
      break;

    case 4:
      printf("\n\tFourth quarter!");
      break;
    
    defaulf:
      printf("\n\tIDK... Sorry...\n");
  }
}


void main(){
  int x, y;
  char bool_;

  for(;;){
    printf("Enter X cords > "); scanf("%d", &x);
    printf("Enter Y cords > "); scanf("%d", &y);
    
    translate( quarter(x, y) );
    
    printf("\n\nEnter agein? (y/n)"); scanf("%s", &bool_);
    
    if(bool_ != 'y')
       break;
    printf("\n");
  }

}
