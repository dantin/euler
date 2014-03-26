#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define NUMBER 2000000

typedef struct ListNode {
  int value;
  struct ListNode *next;
} list_node;

list_node *make_list_node( const int value );
void find_primes( const int range, list_node **primes );
void delete_list( list_node **primes );

int main( void )
{
  list_node *primes, *node;
  long long sum = 0L;

  find_primes( NUMBER, &primes );

  node = primes;
  while( node ) {
    sum += node->value;
    node = node->next;
  }
  delete_list( &primes );

  printf( "%lld\n", sum ); // note: 'lld' is requirement here, or the output is wrong

  return 0;
}

list_node *make_list_node( const int value)
{
  list_node *node = ( list_node * ) malloc( sizeof( list_node ) );
  assert( node );
  node->value = value;
  node->next = NULL;

  return node;
}

void find_primes( const int range, list_node **primes )
{
  list_node *list, *node, *tail, *prev, *prime;
  int i;

  // list sequence after 2
  list = make_list_node( 2 );
  tail = list;
  for( i = 2 + 1; i <= range; i++ ) {
    node = make_list_node( i );
    tail->next = node;
    tail = node;
  }

  // split two list: *primes and list
  prime = list;
  list = list->next;
  prime->next = NULL;
  *primes = prime;
  while( pow( prime->value, 2 ) <= range ) {
    // remove current prime from list
    node = list;
    prev = NULL;
    while( node ) {
      if( node->value % prime->value == 0 ) { // remove
	if( prev ) { // in the middle
	  prev->next = node->next;
	  free( node );
	  node = prev->next;
	} else { // in the head
	  list = node->next;
	  free( node );
	  node = list;
	}
      } else { // reserve
	prev = node;
	node = node->next;
      }
    }
    prime->next = list;
    list = list->next;
    prime = prime->next;
    prime->next = NULL;
  }

  if( list ) {
    prime->next = list;
  }
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
