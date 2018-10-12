#include <stdio.h>
#include <math.h>

int main(){
   long int n = 600851475143;
   long int root = sqrt(n);

   for(long int i = 3; i < root; i++)
   {
      if(!(n % i))   // if n is divisible by i
      {
         printf("%ld ", i);
         n = n / i;
      }
   }

   if(n != 1)
      printf("%ld\n", n);
   else
      printf("\n");

   return 0;
}
