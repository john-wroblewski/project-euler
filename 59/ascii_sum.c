#include <stdio.h>

int main(){
   long int sum = 0;
   int c;

   while((c = getchar()) != EOF && c != '\n')
      sum += c;

   printf("Total sum of ascii values: %ld\n", sum);

   return 0;
}
