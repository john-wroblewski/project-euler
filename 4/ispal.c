#ifndef HEAD
#define HEAD

#include <stdio.h>

#endif

#include <string.h>
#include <stdlib.h>
#include <math.h>

void reverse(char * orig, char * rev, int len){
   int i;
   for(i = 0;i < len;i++)
   {
      rev[i] = orig[len - i - 1];
   }
   rev[i] = '\0';
}

int ispalin(int num){
   int char_num;
   char ascii[1024];
   char rev[1024];

   char_num = snprintf(ascii, 1024, "%d", num);
   reverse(ascii, rev, char_num);

   return strcmp(ascii, rev) == 0;
}
