#include <stdio.h>

#define THRESHOLD 4000000

int main( void )
{
  int sum = 0;
  int i, j, k;

  i = 2;
  j = 8;
  sum = i + j;
  while( ( k = i + 4 *j ) < THRESHOLD ) {
    sum += k;
    i = j;
    j = k;
  }

  printf( "Sum even: %d\n", sum );

  return 0;
}
