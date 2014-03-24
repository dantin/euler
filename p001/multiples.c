#include <stdio.h>

#define NUM1      3
#define NUM2      5
#define THRESHOLD 1000

int main( void ) {
  long i, total = 0;

  for( i = 1; i < THRESHOLD; i++ ) {
    if( ( i % NUM1 == 0 ) || ( i % NUM2 == 0 ) ) {
      total += i;
    }
  }

  printf( "%ld\n", total );

  return 0;
}
