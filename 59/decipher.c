#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZ 4096
#define KEY_SIZ 3

int    fill_buf(char *);
void   dec_out(char *);
void   char_out(char *);
void   decipher(char *, char *, char *);

int len;

int main(){
   void * buf = malloc(BUF_SIZ);
   void * plaintext = malloc(BUF_SIZ);

   len = fill_buf(buf);

   decipher(buf, plaintext, "god");
   char_out(plaintext);

   return 0;
}

int fill_buf(char * buf){
   int i = 0, c;

   while(i < BUF_SIZ && scanf("%d,", &c) > 0)
   {
      buf[i++] = c;
   }

   return i;
}

void dec_out(char * buf){
   printf("\n\t**Printing buffer in decimal format\n\n");
   for(int i = 0; i < len; i++)
   {
      printf("%d ", ((char *)buf)[i]);
   }
   printf("\n");
}

void char_out(char * buf){
   printf("\n\t**Printing buffer in character format\n\n");
   for(int i = 0; i < len; i++)
   {
      printf("%c", ((char *)buf)[i]);
   }
   printf("\n");
}

void decipher(char * buf, char * plaintext, char * key){
   printf("\n\n\tdeciphering with key: \"%c%c%c\"\n\n", key[0], key[1], key[2]);

   for(int i = 0; i < len; i++)
   {
      plaintext[i] = buf[i] ^ key[i % KEY_SIZ];
   }
}

