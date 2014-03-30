#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 15

typedef struct Point {
  int x;
  int y;
  struct Point *next;
} point;

point *make_point( const int x, const int y );

int main( void )
{
  long count;
  point *q, *tail, *node;

  count = 0L;
  q = make_point( 0, 0 );
  tail = q;

  while( q ) {
    int x = q->x;
    int y = q->y;

    if( x != SIZE || y != SIZE ) {
      if( x != SIZE ) {
	node = make_point( x + 1, y );
	tail->next = node;
	tail = node;
      }
      if( y != SIZE ) {
	node = make_point( x, y + 1 );
	tail->next = node;
	tail = node;
      }
    } else {
      count++;
    }
    node = q;
    q = q->next;
    free( node);
  }

  printf( "%ld\n", count );

  return 0;
}

point *make_point( const int x, const int y )
{
  point *ptr = ( point * ) malloc( sizeof( point ) );
  assert( ptr );
  ptr->x = x;
  ptr->y = y;
  ptr->next = NULL;

  return ptr;
}
