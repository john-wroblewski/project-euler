#include "stdio.h"
#include "stdlib.h"

unsigned int rect(unsigned int x, unsigned int y){return x*y*(x+1)*(y+1)/4;}
unsigned int score(unsigned int x, unsigned int y){return abs(rect(x,y)-2000000);}

unsigned int M[200][200];

int main()
{
   unsigned int i,j,best_x=0,best_y=0,min=99999999;

   for(i = 0;i < 200;i++)
      for(j = 0;j < 200;j++)
      {
         M[i][j] = score(i,j);
         if(M[i][j] < min)
         {
            best_x=i;best_y=j;min=M[i][j];
         }
      }

   printf("%u\n", best_x * best_y);

   return 0;
}
