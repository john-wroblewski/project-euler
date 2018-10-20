#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define BUF_SIZ 4096
#define KEY_SIZ 3

int    fill_buf(char *);
void   dec_out(char *);
void   char_out(char *);
void   decipher(char *, char *, char *);
void   calc_score(char *);

int freq[26];
int len;
double best_score = 0.0;
char best_key[KEY_SIZ];

int main(){
   void * buf = malloc(BUF_SIZ);
   void * plaintext = malloc(BUF_SIZ);
   char testkey[] = {'a', 'a', 'a'};
   char key[KEY_SIZ];

   len = fill_buf(buf);

   for(int i = 0; i < 26; i++)
      for(int j = 0; j < 26; j++)
         for(int k = 0; k < 26; k++)
         {
            key[0] = testkey[0] + i;
            key[1] = testkey[1] + j;
            key[2] = testkey[2] + k;
            decipher(buf, plaintext, key);
            calc_score(key);
         }

   printf("best score: %f\nbest key: %c%c%c\n", best_score, best_key[0], best_key[1], best_key[2]);

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
//   printf("\n\n\tdeciphering with key: \"%c%c%c\"\n\n", key[0], key[1], key[2]);

   for(int j = 0; j < 26; j++)
      freq[j] = 0;

   for(int i = 0; i < len; i++)
   {
      /* xor'ing each byte */
      plaintext[i] = buf[i] ^ key[i % KEY_SIZ];

      if(isalpha(plaintext[i]))
      { /* frequency tracking of letters */
         freq[tolower(plaintext[i]) - 97]++;
      }
   }
}

void calc_score(char * key){
   double score;
   score = freq[0] + freq[3] + freq[4] + freq[7]
         + freq[8] + freq[13] + freq[14] + freq[17] + freq[18] + freq[19];
   score = score / len;
   if(score > best_score)
   {
      best_score = score;
      strcpy(best_key, key);
   }
}
