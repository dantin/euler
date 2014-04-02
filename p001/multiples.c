#include <stdio.h>

#define NUM1      3
#define NUM2      5
#define THRESHOLD 1000

int main( void ) {
  int total = 0;

  for( int i = 1; i < THRESHOLD; i++ ) {
    if( ( i % NUM1 == 0 ) || ( i % NUM2 == 0 ) ) {
      total += i;
    }
  }

  printf( "%d\n", total );

  return 0;
}
