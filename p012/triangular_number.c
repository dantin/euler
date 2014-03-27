#include <stdio.h>
#include <math.h>

#define FACTOR 500

int main( void )
{
  long i, j, factors;
  long number;
  int sum;
  i = 1;
  number = 0;
  while( 1 ) {
    number += i++;

    factors = 0;
    long limit = sqrt( number );
    for( j = 1; j < limit; j++ ) {
      if( number % j == 0 ) {
	factors++;
      }
    }
    sum = factors * 2;
    if( limit * limit == number ) {
      sum++;
    }
    if( sum > FACTOR ) {
      break;
    }
  }

  printf( "%d\n", number );

  return 0;
}
