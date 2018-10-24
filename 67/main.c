#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

unsigned int opt(int, int);

unsigned int T[5050];     //n(n+1)/2, n=100
unsigned int opt_arr[5050];
unsigned int set[5050];

#define I	1
#define J	1
#define INDEX(x,y)   ((((x)*((x)-1))/2) + (y) - 1)

int main(int argc, char *argv[]){
  if(argc != 2)
  {
    puts("expects triangle data input file");
    exit(EXIT_FAILURE);
  }

  FILE * data_file = fopen(argv[1], "r");

  if(data_file == NULL)
  {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  unsigned int i = 0;

  while(fscanf(data_file, "%u ", T+i) != EOF)
  { i++; }

  if(ferror(data_file))
  {
    perror("fscanf");
    exit(EXIT_FAILURE);
  }

  unsigned int optimal = opt(I,J);

  printf("maximal sum from row %u, column %u: %u\n", I, J, optimal);

  return 0;
}

unsigned int opt(int i, int j){
  if(j > i)
  {
    puts("indexing error in opt...abort");
    exit(EXIT_FAILURE);
  }

  if(i == 100)
    return T[4950 + j - 1];  // INDEX(100,j)

  if(set[INDEX(i,j)])
    return opt_arr[INDEX(i,j)];

  unsigned int max1 = opt(i+1,j);
  unsigned int max2 = opt(i+1,j+1);
  unsigned int val  = T[INDEX(i,j)];
  unsigned int temp;

  temp = val + ((max1 > max2) ? max1 : max2);
  opt_arr[INDEX(i,j)] = temp;
  set[INDEX(i,j)] = 1;

  return opt_arr[INDEX(i,j)];
}
