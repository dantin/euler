#include <stdio.h>

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
  while( number > 1 ) {
    if( number % factor == 0 ) {
      last_factor = factor;
      number /= factor;
      while( number % factor == 0 ) {
	number /= factor;
      }
    }
    factor += 2L;
  }

  printf( "%ld\n", last_factor );
  
  return 0;
}
