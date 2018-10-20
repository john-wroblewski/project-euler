int computewordvalue(char * word)
{
   int c, i = 0, sum = 0;

   while((c = *(word + i++)) != '\0')
      sum += (c - 64);

   return sum;
}
