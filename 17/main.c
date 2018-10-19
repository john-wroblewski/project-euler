#include <stdio.h>
#include <string.h>

#define LENGTHOFHUNDRED        7
#define LENGTHOFONETHOUSAND	11
#define NUMSTART		1
#define NUMEND			1000
#define ANDLENGTH		3

static char * base_digits[] = { "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" };
static char * teens[] = { "eleven" , "twelve" , "thirteen" , "fourteen" , "fifteen" , "sixteen" , "seventeen" , "eighteen" , "nineteen" };
static char * mults_of_ten[] = { "ten" , "twenty" , "thirty" , "forty" , "fifty" , "sixty" , "seventy" , "eighty" , "ninety" };

unsigned int count_letters( unsigned int );

int main(){
	unsigned int count = 0 , i;

	for( i = 1; i <= 1000; i++ )
		count += count_letters( i );
	printf( "total letters-> %d\n" , count );
	return 0;
}
unsigned int count_letters( unsigned int num ){

	if( num == 1000 )
		return LENGTHOFONETHOUSAND;

	unsigned int digitcount = 0 , n , mdivisor = 1000;

	do{
		if( num < 20 && num > 10 ){
			return digitcount + strlen( teens[ num - 11 ] );
		}
		n = ( num / ( mdivisor /= 10 ) );
		num -= n * mdivisor;
		if( n ){
			if( mdivisor == 100 ){
				digitcount += ( strlen( base_digits[ n - 1 ] ) + LENGTHOFHUNDRED );
				if( num ){
					digitcount += ANDLENGTH;
				}
			}else if( mdivisor == 10 ){
				digitcount += strlen( mults_of_ten[ n - 1 ] );
			}else if( mdivisor == 1 ){
				digitcount += strlen( base_digits[ n - 1 ] );
			}
		}
	}while( num );

	return digitcount;
}
