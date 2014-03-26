#include <stdio.h>
#include <stdbool.h>

#define SIZE 1000

bool is_pythagorean( const int i, const int j, const int k );

int main( void )
{
  int i, j, k;

  for( i = 1; i < SIZE; i++ ) {
    for( j = i + 1; j < SIZE; j++ ) {
      for( k = j + 1; k < SIZE; k++ ) {
	if( i + j + k == SIZE && is_pythagorean( i, j, k ) ) {
	  printf( "%d * %d * %d = %d\n", i, j, k, i * j * k );
	  return 0;
	}
      }
    }
  }

  return 0;
}

bool is_pythagorean( const int i, const int j, const int k )
{
  return i * i + j * j == k * k;
}
