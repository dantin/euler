#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOW  100
#define HIGH 1000

int main( void )
{
  char buffer[10];
  int i, j;
  char *s, *e;

  int max_i = 0, max_j = 0, max = 0;
  for( i = LOW; i < HIGH; i++ ) {
    for( j = LOW; j < HIGH; j++ ) {
      sprintf( buffer, "%d", i * j );
      s = buffer;
      e = buffer + strlen( buffer ) - 1;
      while( *s++ == *e-- ) {
	if( s >= e ) {
	  if( i * j > max ) {
	    max = i * j;
	    max_i = i;
	    max_j = j;
	  }
	}
      }
    }
  }

  printf( "%d * %d = %d\n", max_i, max_j, max );

  return 0;
}
