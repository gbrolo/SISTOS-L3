#include <stdio.h>
#include <time.h>
 
int main () {
   clock_t start_t, end_t;
   double diff;

   int i;
   start_t = clock();
   for( i = 0; i < 1000000; i = i + 1 ){
      printf("%d\n", i);
   }

   int j;
   for( j = 0; j < 1000000; j = j + 1 ){
      printf("%d\n", j);
   }

   int k;
   for( k = 0; k < 1000000; k = k + 1 ){
      printf("%d\n", k);
   }

   end_t = clock();
 
   diff = (double)(end_t - start_t);

   printf (" %lf " , diff ) ;

   return 0;
}

