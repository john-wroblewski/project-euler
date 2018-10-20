#include <stdio.h>
#include "triangle.h"

#define BUF_SIZ 1024

int main(){
   char buf[BUF_SIZ];
   int triangle_count = 0;
   FILE * fp = fopen("words.txt", "r");

   if(fp == NULL)
      return 1;

   while( fscanf(fp, " \"%[^\"]\",", buf) > 0 )
   {
      triangle_count += istriangle(computewordvalue(buf));
   }

   printf("total number of triangle numbers: %d\n", triangle_count);

   return 0;
}
