#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 20

long long lattice( unsigned int x, unsigned int y );

int main( void )
{
  long long steps;

  steps = lattice( 0, 0 );

  printf( "%lld\n", steps );

  return 0;
}

long long lattice( unsigned int x, unsigned int y )
{
  if( x == SIZE && y == SIZE ) {
    return 0L;
  } else if( x == SIZE ) {
    return 1L;
  } else if( y == SIZE ) {
    return 1L;
  } else {
    return lattice( x + 1, y ) + lattice( x, y + 1 );
  }
}
