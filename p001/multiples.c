#include <stdio.h>

#define NUM1      3
#define NUM2      5
#define THRESHOLD 999

int sum( const int n, const int limit );

int main( void ) {
  int total = sum( NUM1, THRESHOLD ) + sum( NUM2, THRESHOLD )
    - sum( NUM1 * NUM2, THRESHOLD );

  printf( "%d\n", total );

  return 0;
}

int sum( const int n, const int limit )
{
  int len = limit / n;

  return n * ( len * ( len + 1 ) ) / 2;
}
