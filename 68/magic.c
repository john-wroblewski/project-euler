unsigned int magic(int *);

unsigned int magic(int * A){
   unsigned int ismagic = 0;

   int possible_total = A[0] + A[1] + A[9];

   ismagic = ( possible_total == (A[1] + A[2] + A[3]) &&
               possible_total == (A[3] + A[4] + A[5]) &&
               possible_total == (A[5] + A[6] + A[7]) &&
               possible_total == (A[7] + A[8] + A[9]) );

   return ismagic && (A[0] == 10 || A[2] == 10 ||
                      A[4] == 10 || A[6] == 10 ||
                      A[8] == 10);
}
