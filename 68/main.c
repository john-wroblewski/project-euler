#ifndef _HEADERIO
#define _HEADERIO

#include <stdio.h>

#endif

#include "heap_perm.h"

#define N 10

int main(){

   int array[N] = {1,2,3,4,5,6,7,8,9,10};

   heap_perm(N, array);

   return 0;
}
