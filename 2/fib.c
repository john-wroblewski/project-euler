#include <stdio.h>

int main(){
   long int cur_fib = 1, prev_fib = 1, temp, sum = 0;

   while(cur_fib <= 4000000)
   {
      if(cur_fib % 2 == 0)
         sum += cur_fib;
      temp = cur_fib;
      cur_fib += prev_fib;
      prev_fib = temp;
   }

   printf("%ld\n", sum);

   return 0;
}
