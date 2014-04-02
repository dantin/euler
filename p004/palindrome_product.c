#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LOW  100
#define HIGH 999

unsigned int reverse( unsigned int number );
bool is_palindrome( unsigned int number );

int main( void )
{
  unsigned int i, j;

  unsigned int max = 0;
  for( i = HIGH; i >= LOW; i-- ) {
    unsigned int step;

    if( i % 11 == 0 ) {
      j = HIGH - 1;
      step = 1;
    } else {
      j = 990; // largest number less than 999 and divisible by 11
      step = 11;
    }
    while( j >= i ) {
      if( i * j <= max ) {
	break;
      }
      if( is_palindrome( i * j ) ) {
	max = i * j;
      }
      j -= step;
    }
  }

  printf( "%u\n", max );

  return 0;
}

unsigned int reverse( unsigned int number )
{
  unsigned int reversed = 0;

  while( number > 0 ) {
    reversed = 10 * reversed + number % 10;
    number /= 10;
  }

  return reversed;
}

bool is_palindrome( unsigned int number )
{
  return number == reverse( number );
}
