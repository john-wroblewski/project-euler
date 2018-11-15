#include "stdio.h"
#include "stdlib.h"

#define UNIT		200
#define COIN_COUNT 	8

unsigned int ways_to_make_change(unsigned int, unsigned int);
unsigned int next_less_coin(unsigned int);
unsigned int coin_val_to_index(unsigned int);

unsigned int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
unsigned int M[UNIT + 1][COIN_COUNT];   // memoization table

int main(){

  printf("euler 31: %u\n", ways_to_make_change(UNIT, coins[COIN_COUNT - 1]));

  return 0;
}

unsigned int coin_val_to_index(unsigned int c)
{
  unsigned int i;
  for(i = 0;c != coins[i];i++)
  { } // intentionally left empty

  return i;
}

unsigned int next_less_coin(unsigned int c)  // could use bin search for log n runtime but array size is trivial
{
  unsigned int i;

  for(i = COIN_COUNT - 1;c != coins[i];i--)
  { }  // intentionally left empty

  return coins[i - 1];
}

unsigned int ways_to_make_change(unsigned int n, unsigned int c)
{
  if(n == 0 || c == 1)
    return 1;

  if(M[n][coin_val_to_index(c)])
    return M[n][coin_val_to_index(c)];

  unsigned count = 0;
  unsigned int u = next_less_coin(c);
  
  if(n < c)
    return ways_to_make_change(n, u);
  
  count += ways_to_make_change(n, u);
  count += ways_to_make_change(n - c, c);
  M[n][coin_val_to_index(c)] = count;
  
  return count;
}
