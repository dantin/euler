#include <stdio.h>

#define THRESHOLD 4000000

int main( void )
{
  int sum = 0;
  int i, j, k;

  for( i = 1, j = 2, sum += j; ( k = i + j ) < THRESHOLD; i = j, j = k ) {
    if( k % 2 == 0 ) {
      sum += k;
    }
  }

  printf( "Sum even: %d\n", sum );

  return 0;
}
