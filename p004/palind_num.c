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
  for( i = LOW; i < HIGH; i++ ) {
    for( j = LOW; j < HIGH; j++ ) {
      if( is_palindrome( i * j ) && i * j > max) {
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