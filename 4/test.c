#ifndef HEAD
#define HEAD

#include <stdio.h>

#endif

#include "header.h"

int main(){
   int nums[] = { 1, 303, 78944987,
                  12, 12343212 };

   char bank[] = "78944987";
   char rev[8];

   for(int i = 0;i < 5;i++)
      printf("%d\n", ispalin(nums[i]));

   reverse(bank, rev, 8);
   printf("%s\n" , rev);

   return 0;
}
