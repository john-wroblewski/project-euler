#ifndef _IOHEADER
#define _IOHEADER
#include <stdio.h>
#endif

void populate_grid(unsigned int size, unsigned long long grid[][size]){
   unsigned int i, j;

   //seed the grid with a few values
   for(j = 0;j < size;j++)
   {
      grid[0][j] = j + 1;
      grid[j][j] = 1;
   }

   //use n choose r recurrence relation
   for(i = 1;i < size;i++)
      for(j = i + 1;j < size;j++)
         grid[i][j] = grid[i][j - 1] + grid[i - 1][j - 1];
}

void out(unsigned int size, unsigned long long grid[][size]){
   for(unsigned int i = 0;i < size;i++)
   {
      for(unsigned int k = 0;k < i;k++)
         printf("%7s", " ");

      for(unsigned int j = i;j < size;j++)
         printf("%7llu", grid[i][j]);

      printf("\n");
   }
}

//basically this does the same thing as populate_grid() except
//that this stops generating values for a particular n once
//we've found an n-value that generates a choose-value over the ceiling
//which is one million (10^6) for problem 53. (rule 3)
void solve53(unsigned int size, unsigned int grid[][size], unsigned int ceiling){

   int i, j, sum = 0;

   //seed the grid with a few values
   for(j = 0;j < size;j++)
   {
      grid[0][j] = j + 1;
      grid[j][j] = 1;
   }

   //use n choose r recurrence relation
   for(i = 1;i < size;i++)
      for(j = i + 1;j < size;j++)
      {
         if((grid[i][j] = grid[i][j - 1] + grid[i - 1][j - 1]) > ceiling)
         {
            sum += size - j;
            break;
         }
      }
   printf("%d\n", sum);
}

void choose(unsigned int n, unsigned int r, unsigned int size, unsigned long long grid[][size]){
   printf("%llu\n", grid[r - 1][n - 1]);
}
