#include <stdio.h>
 
int main () {

   int i;
   for( i = 0; i < 4; i = i + 1 ){
      fork();
      printf("%d\n", (int)getpid());
   }
 
   return 0;
}
