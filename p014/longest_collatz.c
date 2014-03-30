#include <stdio.h>
#include <stdlib.h>

#define SIZE    1000000

unsigned int length( const unsigned long n );

int main( void )
{
  int i;
  unsigned int max;
  int max_num;

  for( max = 0U, max_num = 0, i = 2; i <= SIZE; i++ ) {
    if( length( i ) > max ) {
      max = length( i );
      max_num = i;
    }
  }

  printf( "%d\n", max_num );

  return 0;
}

unsigned int length( const unsigned long n )
{
  unsigned int step = 0;
  unsigned long number = n;

  while( 1 ) {
    if( number % 2 == 0 ) {
      number /= 2UL;
    } else {
      number = 3 * number + 1UL;
    }

    if( number <= 1 ) {
      return 1;
    } else {
      step++;
      return step + length( number );
    }
  }
}
