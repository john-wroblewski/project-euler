/* An implementation of Heap's Algorithm to generate
 * all permuations of N integers.
 *
 * T0D0: Generalize to abstract permutation, possibly
 *       using function pointers.
*/

#ifndef _HEADERIO
#define _HEADERIO

#include <stdio.h>

#endif

#include "magic.h"

void swap(int * A, unsigned int i, unsigned int j){
   int temp = A[i];
   A[i] = A[j];
   A[j] = temp;
}

void out(unsigned int n, int * A){
   for(int i = 0;i < n;i++)
      printf("%3d", A[i]);
   printf("\n");
}

void heap_perm(unsigned int n, int * A){
   if(n == 1)  //base case
   {
      if(magic(A))
         out(10, A);
   }

   else
   {
      for(int i = 0;i < n - 1;i++)
      {
         heap_perm(n - 1, A);
         if(n % 2 == 0)
            swap(A, i, n - 1);
         else
            swap(A, 0, n - 1);
      }
      heap_perm(n - 1, A);
   }
}

