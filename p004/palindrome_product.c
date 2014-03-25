#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LOW  100
#define HIGH 1000

unsigned int reverse( unsigned int number );
bool is_palindrome( unsigned int number );

int main( void )
{
  unsigned int i, j;

  unsigned int max = 0;
  for( i = HIGH - 1; i >= LOW; i-- ) {
    unsigned int step;

    if( i % 11 == 0 ) {
      j = HIGH - 1;
      step = 1;
    } else {
      j = 990;
      step = 11;
    }
    for( ; j >= i; j -= step ) {
      if( i * j <= max ) {
	break;
      }
      if( is_palindrome( i * j ) ) {
	max = i * j;
      }
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
