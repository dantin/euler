#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 20

typedef struct Point {
  unsigned int x;
  unsigned int y;
  unsigned int count;
  struct Point *next;
} point;

point *make_point( const unsigned int x, const unsigned int y );
point *find_point( point *list, const unsigned int x, const unsigned int y );
long long lattice( unsigned int x, unsigned int y );

int main( void )
{
  unsigned int level = 0;
  point *list, *iter, *tail, *node;

  list = make_point( 0, 0 );
  tail = list;
  level = list->x + list->y;
  while( level < SIZE ) { // if expand
    while( list ) {
      unsigned int x = list->x;
      unsigned int y = list->y;

      if( x + y == level ) {
	iter = find_point( list, x + 1, y );
	if( !iter ) {
	  node = make_point( x + 1, y );
	  node->count = list->count;
	  tail->next = node;
	  tail = node;
	} else {
	  iter->count += list->count;
	}
	iter = find_point( list, x, y + 1 );
	if( !iter ) {
	  node = make_point( x, y + 1 );
	  node->count = list->count;
	  tail->next = node;
	  tail = node;
	} else {
	  iter->count += list->count;
	}
      } else {
	break;
      }
      point *temp = list;
      list = list->next;
      free( temp );
    }

    level++;
  }

  long long steps = 0L;
  while( list ) {
    node = list;
    printf( "%d ( %d, %d )\n", node->count, node->x, node->y );
    steps += node->count * lattice( node->x, node->y );
    list = list->next;
    free( node );
  }

  printf( "%lld\n", steps );

  return 0;
}

point *make_point( const unsigned int x, const unsigned int y )
{
  point *ptr = ( point * ) malloc( sizeof( point ) );
  assert( ptr );
  ptr->x = x;
  ptr->y = y;
  ptr->count = 1;
  ptr->next = NULL;

  return ptr;
}

point *find_point( point *list, const unsigned int x, const unsigned int y )
{
  while( list ) {
    if( list->x == x && list->y == y ) {
      return list;
    }

    list = list->next;
  }

  return NULL;
}

long long lattice( unsigned int x, unsigned int y )
{
  if( x == SIZE && y == SIZE ) {
    return 0L;
  } else if( x == SIZE ) {
    return 1L;
  } else if( y == SIZE ) {
    return 1L;
  } else {
    return lattice( x + 1, y ) + lattice( x, y + 1 );
  }
}
