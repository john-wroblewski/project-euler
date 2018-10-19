#include <stdio.h>

#define		NUMOFLINES	100

void process_digits( FILE * , int * );
int main()
{
	int i , solution[ 52 ];
	FILE * ifp;
	char * file_name = "numbers.txt";
	char * mode      = "r";

	ifp = fopen( file_name , mode );
	if( ifp == NULL )
	{
		printf( "error: unable to open file '%s'\n" , file_name );
		return 1;
	}

	for( i = 0; i < 52; i++ )
		solution[ i ] = 0;

	for( i = 0; i < NUMOFLINES; i++ )
		process_digits( ifp , solution );

	for( i = 0; i < 10; i++ )
		printf( "%d" , solution[ i ] );
	printf( "\n" );

	fclose( ifp );
	return 0;
}
void process_digits( FILE * ifp , int * solution )
{
	int i , c;
	int temp[ 52 ];
	// read in integers from file

	for( i = 0; i < 2; i++ ) //pad first two(2) spots with zero(0)'s
		temp[ i ] = 0;

	for( ; i < 52; i++ )
	{
		c = fgetc( ifp );
		temp[ i ] = c - '0';
	}
	c = fgetc( ifp );	// eat newline
	// add the nums from current line to solution array
	for( i = 51; i >= 0; i-- )
	{
		c = ( solution[ i ] += temp[ i ] );
		if( c >= 10 )
		{
			if( i )
				solution[ i - 1 ] += ( c / 10 );
			solution[ i ] %= 10;
		}
	}
	return;
}
