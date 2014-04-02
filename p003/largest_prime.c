#include <stdio.h>
#include <math.h>

#define NUMBER 600851475143L

int main( void )
{
  long long number;
  int factor, last_factor, limit;

  number = NUMBER;

  // handle 2 separatly
  if( number % 2 == 0 ) {
    last_factor = 2;
    while( number % 2 == 0 ) {
      number /= 2;
    }
  } else {
    last_factor = 1;
  }

  factor = 3;
  limit = sqrt( number ); // set limit of factor
  while( number > 1 && factor <= limit ) {
    if( number % factor == 0 ) {
      last_factor = factor;
      number /= factor;
      while( number % factor == 0 ) {
	number /= factor;
      }
      limit = sqrt( number ); // update limit
    }
    factor += 2;
  }
  // every number n can at most have one prime factor greater than n^(1/2)
  if( number != 1 ) {
    last_factor = number;
  }
  
  printf( "%d\n", last_factor );
  
  return 0;
}
