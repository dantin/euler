#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX   10001

bool is_prime( const unsigned int number );

int main( void )
{
  int i = 2, count = 1;

  while( count != MAX ) {
    i++;
    if( is_prime( i ) ) {
      count++;
    }
  }
  printf( "%d\n", i );

  return 0;
}

bool is_prime( const unsigned int n )
{
  int r, f;

  if( n == 1 ) {
    return false;
  } else if( n < 4 ) { // 2, 3
    return true;
  } else if( n % 2 == 0 ) {
    return false;
  } else if( n < 9 ) {
    return true;
  } else if( n % 3 == 0 ) {
    return false;
  } else {
    r = floor( sqrt( n ) );
    f = 5;
    while( f <= r ) {
      if( n % f == 0 ) {
	return false;
      }
      if( n % ( f + 2 ) == 0 ) {
	return false;
      }
      f += 6;
    }
    return true;
  }
}
