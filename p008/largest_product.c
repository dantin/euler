#include <stdio.h>

#define SIZE 1000
#define LEN  5

int main( void )
{

  int digits[SIZE];
  int i, j, p, max;
  char c;

  i = 0;
  while( ( c = getchar() ) != EOF ) {
    if( c >= '0' && c <= '9' ) {
      digits[ i++ ] = c - '0';
    }
  }

  max = 0;
  for( i = 0; i < SIZE; i++ ) {
    p = 1;
    for( j = 0; j < LEN && i + j < SIZE; j++ ) {
      p *= digits[ i + j ];
    }
    if( i + j >= SIZE ) {
      break;
    }
    if( p > max ) {
      max = p;
    }
  }

  printf( "%d\n", max );

  return 0;
}
