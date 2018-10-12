#ifndef HEAD
#define HEAD

#include <stdio.h>
#include "header.h"

#endif


int main(){
   int i, j, max = 0, maxi, maxj;

   for(i = 100;i <= 999;i++)
      for(j = 100;j <= 999;j++)
         if(ispalin(i * j) && max < i * j)
         {
            max  = i * j;
            maxi = i;
            maxj = j;
         }

   printf("%d * %d = %d\n", maxi, maxj, max);

   return 0;
}
