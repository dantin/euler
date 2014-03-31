#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define BASE 2
#define EXP  1000

typedef struct ListNode {
  int value;
  struct ListNode *next;
} list_node;

list_node *make_list_node( const int value );
void multiply( list_node **product, const int number );
list_node *reverse( list_node *list );
void print( list_node *list );
void delete_list( list_node **list );

int main( void )
{
  list_node *node, *product = NULL;
  int i, sum;

  product = make_list_node( 1 );

  for( i = 0; i < EXP; i++ ) {
    multiply( &product, BASE );
  }

  for( node = product, sum = 0; node; node = node->next ) {
    sum += node->value;
  }
  delete_list( &product );

  printf( "%d\n", sum );

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

void multiply( list_node **product, const int number )
{
  list_node *list, *tail, *node;
  int remaining = 0;

  tail = NULL;
  list = reverse( *product );
  node = list;
  while( node ) {
    int n = node->value * number + remaining;
    node->value = n % 10;
    remaining = n / 10;

    tail = node;
    node = node->next;
  }

  while( remaining ) {
    node = make_list_node( remaining % 10 );
    tail->next = node;
    tail = node;
    remaining /= 10;
  }

  *product = reverse( list );
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

void delete_list( list_node **list )
{
  list_node *temp, *node;

  node = *list;
  while( node ) {
    temp = node;
    node = node->next;
    free( temp );
  }

  *list = NULL;
}
