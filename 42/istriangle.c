#include <stdlib.h>

#define NUM_OF_TRIANGLES 50

int triangles[NUM_OF_TRIANGLES] = {1,   3,   6,   10,  15 , 21,  28,  36,  45,  55,  66,  78,
                                   91 , 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300,
                                   325, 351, 378, 406, 435, 465, 496, 528, 561, 595, 630, 666,
                                   703, 741, 780, 820, 861, 903, 946, 990, 1035, 1081, 1128,
                                   1176, 1225, 1275};

int cmp_int(const void * a, const void * b)
{
   return *(int *)a - *(int *)b;
}

int istriangle(int num)
{
   int * container;
   container = (int *)bsearch(&num, triangles, NUM_OF_TRIANGLES, sizeof(int), cmp_int);

   return container != NULL;
}
