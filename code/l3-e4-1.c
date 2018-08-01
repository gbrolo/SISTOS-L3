#include <stdio.h>
#include <unistd.h>
 
int main () {

   pid_t id1, id2, id3;
   int a;

   id1 = fork();

   if (id1 > 0) {
      // parent
      while (1==1) {
         
      }
   } else if (id1 == 0) {
      // child
      for( a = 1; a < 4000001; a = a + 1 ){
         printf("%d\n", a);
      }
   }

   

   return 0;
}

