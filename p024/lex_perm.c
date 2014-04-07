#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

static int count = 0;

bool lex_perm( int *array, int end, int size );

int main( void )
{
  int buffer[SIZE];

  lex_perm( buffer, 0, SIZE );

  return 0;
}

bool lex_perm( int *array, int end, int size )
{
  int i, j;
  bool found;

  for( i = 0; i < size; i++ ) {
    found = false;
    for( j = 0; j < end; j++ ) {
      if( array[j] == i ) {
	found = true;
	break;
      }
    }
    if( found ) {
      continue;
    }

    array[ end ] = i;

    if( end + 1 == size ) {
      return true;
    }

    if( lex_perm( array, end + 1, size ) ) {
      count++;
      // print
      if( count == 1000000 ) {
	for( j = 0; j < size; j++ ) {
	  printf( "%d", array[j] );
	}
	printf( "\n" );
      }
    }
  }

  return false;
}
