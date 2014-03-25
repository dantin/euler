#include <stdio.h>

#define NUMBER 600851475143L

int main( void )
{
  long long number;
  long long factor, last_factor;

  number = NUMBER;
  factor = 2;
  last_factor = 1;

  while( number > 1 ) {
    if( number % factor == 0 ) {
      last_factor = factor;
      number /= factor;
      while( number % factor == 0 ) {
	number /= factor;
      }
    }
    factor++;
  }

  printf( "%ld\n", last_factor );
  
  return 0;
}
