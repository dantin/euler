#include <stdio.h>

#define NUM1      3
#define NUM2      5
#define THRESHOLD 1000

int main( void ) {
  long i, total = 0;

  for( i = 1; i < THRESHOLD; i++ ) {
    if( i % ( NUM1 * NUM2 ) == 0 ) { // multiples of both 3 and 5
      total += i;
    } else if( i % NUM1 == 0 ) { // multiples of 3 but not 5
      total += i;
    } else if( i % NUM2 == 0 ) { // multiples of 5 but not 3
      total += i;
    }
  }

  printf( "%ld\n", total );

  return 0;
}
