#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main () {

   pid_t id1, id2, id3;
   clock_t start_t, end_t;
   int a, b, c;
   double diff;

   start_t = clock();

   id1 = fork();

   if (id1 > 0) {
      id2 = fork();

      if (id2 > 0) {
         id3 = fork();

         if (id3 > 0) {
            for( a = 0; a < 1000000; a = a + 1 ){
     	        printf("%d\n", a);
            }
         } else if (id3 == 0) {
            wait(NULL);
            for( b = 0; b < 1000000; b = b + 1 ){
                printf("%d\n", b);
            }
         }
      } else if (id2 == 0) {
         wait(NULL);
         for( c = 0; c < 1000000; c = c + 1 ){
                printf("%d\n", c);
         }

      }
   } else if (id1 == 0) {
      wait(NULL);
      end_t = clock();
      diff = (double)(start_t - end_t);
      printf (" %lf " , diff ) ;
   }

   

   return 0;
}

