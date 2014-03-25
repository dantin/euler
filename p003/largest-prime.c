#include <stdio.h>
#include <math.h>

#define NUMBER 600851475143L

int main( void )
{
  long long number;
  long long factor, last_factor;

  number = NUMBER;

  if( number % 2L == 0 ) {
    last_factor = 2;
    while( number % 2L == 0 ) {
      number /= 2L;
    }
  } else {
    last_factor = 1;
  }

  factor = 3L;
  long long max_factor = sqrt( number );

  while( number > 1 && factor <= max_factor) {
    if( number % factor == 0 ) {
      last_factor = factor;
      number /= factor;
      while( number % factor == 0 ) {
	number /= factor;
      }
      max_factor = sqrt( number );
    }
    factor += 2L;
  }

  if( number == 1 ) {
    printf( "%ld\n", last_factor );
  } else {
    printf( "%ld\n", number );
  }
  
  return 0;
}
