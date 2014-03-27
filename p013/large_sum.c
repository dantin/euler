#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct ListNode {
  int value;
  struct ListNode *next;
} list_node;

list_node *make_list_node( const int value );
void delete_list( list_node **list );
int read( list_node **list );
void add( list_node **sum, list_node **number );
list_node *reverse( list_node *list );
void print( list_node **list, unsigned int size );

int main( void )
{
  list_node *sum = NULL;
  list_node *number = NULL;

  while( read( &number ) != EOF ) {
    add( &sum, &number );
    print( &number, 0 );
    delete_list( &number );
  }

  print( &sum, 100 );

  return 0;
}

list_node *make_list_node( const int value )
{
  list_node *node = ( list_node * ) malloc( sizeof( list_node ) );
  assert( node );
  node->value = value;
  node->next = NULL;

  return node;
}

void delete_list( list_node **list )
{
  if( !list ) {
    return;
  }

  list_node *temp, *node = *list;

  while( node ) {
    temp = node;
    node = node->next;
    free( temp );
  }

  *list = NULL;
}

int read( list_node **list )
{
  list_node *node, *tail;
  int c;

  tail = *list;
  while( ( c = getchar() ) != EOF ) {
    if( isdigit( c ) ) {
      node = make_list_node( c - '0' );
      if( tail == NULL ) {
	*list = node;
      } else {
	tail->next = node;
      }
      tail = node;
    } else {
      break;
    }
  }

  return c;
}

void add( list_node **sum, list_node **number )
{

}

list_node *reverse( list_node *list )
{
}

void print( list_node **list, unsigned int size )
{
  list_node *node = *list;
  
  while( node ) {
    printf( "%d", node->value );
    node = node->next;
  }

  printf( "\n" );
}
