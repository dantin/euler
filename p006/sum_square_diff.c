#include <stdio.h>

#define MAX 100

int main( void )
{
  int sum = MAX * ( MAX + 1 ) / 2;
  int sq = ( 2 * MAX + 1 ) * ( MAX + 1 ) * MAX / 6;


  printf( "%d - %d = %d\n", sum * sum, sq, sum * sum - sq );

  return 0;
}
