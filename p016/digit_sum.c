#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define BASE 2
#define EXP  15

typedef struct ListNode {
  int value;
  struct ListNode *next;
} list_node;

list_node *make_list_node( const int value );
list_node *multiply( list_node **product, const int number );
list_node *reverse( list_node *list );
void print( list_node *list );

int main( void )
{
  list_node *product = NULL;
  int i;

  product = make_list_node( 1 );

  for( i = 0; i < 15; i++ ) {
    product = multiply( &product, BASE );
  }
  print( product );

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

list_node *multiply( list_node **product, const int number )
{
  list_node *list;

  list = reverse( *product );
  return list;
}

list_node *reverse( list_node *list )
{
  list_node *reversed, *temp;

  reversed = NULL;
  while( list ) {
    temp = list;
    list = list->next;
    temp->next = reversed;
    reversed = temp;
  }

  return reversed;
}

void print( list_node *list ) {
  while( list ) {
    printf( "%d", list->value );
    list = list->next;
  }

  printf( "\n" );
}
