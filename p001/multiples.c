#include <stdio.h>

#define NUM1      3
#define NUM2      5
#define THRESHOLD 1000

int main( void ) {
  long total = 0;
  long a1, a2;

  a1 = NUM1;
  while( a1 < THRESHOLD ) {
    total += a1;
    a1 += NUM1;
  }

  a2 = NUM2;
  while( a2 < THRESHOLD ) {
    if( a2 % NUM1 != 0 ) {
      total += a2;
    }
    a2 += NUM2;
  }

  printf( "%ld\n", total );

  return 0;
}
