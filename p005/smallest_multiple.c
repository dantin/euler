#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int main( void )
{
  int n, i;

  for( n = 1; ; n++ ) {
    bool divided = true;
    for( i = 1; i <= MAX; i++ ) {
      if( n % i != 0 ) {
	divided = false;
	break;
      }
    }
    if( divided ) {
      printf( "%d\n", n );
      break;
    }
  }

  return 0;
}
