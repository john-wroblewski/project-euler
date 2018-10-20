#include <stdio.h>
#include "triangle.h"

int main(){
   char * test = "A";

   printf("is \"SKY\" a triangle word? %s\n", istriangle(computewordvalue(test)) ? "yes" : "no");

   return 0;
}
