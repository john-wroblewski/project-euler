#include <stdio.h>
#include <string.h>
#include <math.h>

#define N	2000000

unsigned short A[N];

int main(){
  memset((void *)A, 0, N * sizeof(unsigned short));
  A[0] = 1;
  int i = 2;

  // sieve
  while(i <= sqrt(N))
  {
    for(int j = 2 * i;j <= N;j += i)
      A[j - 1] = 1;

    i++;

    while(A[i - 1])
      i++;
  }

  unsigned long sum = 0;

  for(i = 0;i < N;i++)
    if(!A[i])
    {
      //printf("adding %u to %lu to obtain %lu\n", i+1, sum, sum + i + 1);
      sum += (i + 1);
    }
  printf("%lu\n", sum);

  return 0;
}
