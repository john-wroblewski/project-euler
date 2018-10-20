#include <stdio.h>
#include <math.h>


int main(){
  unsigned int line_number = 0, best_line;
  double base, exponent, maximum = 0, current;
  FILE * file;

  file = fopen("input.txt", "r");

  if(!file){
    puts("file read errrrrr");
    return 1;
  }

  while(fscanf(file, "%lf%*c%lf", &base, &exponent) > 0){
    line_number++;
    current = exponent * log(base);
    if(current > maximum){
      maximum = current;
      best_line = line_number;
    }
  }

  printf("%d\n", best_line);

  return 0;
}
