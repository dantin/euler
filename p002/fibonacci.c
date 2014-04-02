#include <stdio.h>

#define THRESHOLD 4000000

int main( void )
{
  int sum = 0;
  int i, j, k;

  i = 1;
  j = 1;
  k = i + j;
  while( k < THRESHOLD ) {
    sum += k;
    i = j + k;
    j = k + i;
    k = i + j;
  }

  printf( "Sum even: %d\n", sum );

  return 0;
}
