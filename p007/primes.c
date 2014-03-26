#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define MAX   10001
#define SCALE 2

typedef struct ListNode {
  long long value;
  struct ListNode *next;
} list_node;

list_node *make_list_node( const long long value );
void find_primes( const long long low, const long long high, list_node **primes, int *count );
void delete_list( list_node **list );

int main( void )
{
  list_node *primes = NULL;
  int count = 1;
  long long low = 1L, high = 2L;

  primes = make_list_node( 2L );
  count = 1;

  while( 1 ) {
    find_primes( low, high, &primes, &count );
    low = high;
    high *= SCALE;

    if( count >= MAX ) {
      break;
    }
  }

  list_node *node = primes;
  count = 1;
  while( node ) {
    if( count++ == MAX ) {
      printf( "%ld\n", node->value );
    }
    node = node->next;
  }

  delete_list( &primes );

  return 0;
}

list_node *make_list_node( const long long value )
{
  list_node *node = ( list_node * )malloc( sizeof( list_node ) );
  assert( node );
  node->value = value;
  node->next = NULL;

  return node;
}

void find_primes( const long long low, const long long high, list_node **primes, int *count )
{
  list_node *tail, *node;
  long long i;

  for( tail = *primes; tail && tail->next; tail = tail->next )
    ;

  for( i = low + 1; i <= high; i++ ) {
    bool found = false;
    for( node = *primes; node != NULL; node = node->next ) {
      if( i % node->value == 0 ) {
	found = true;
	break;
      }
    }
    if( !found ) {
      ( *count )++;
      tail->next = make_list_node( i );
      tail = tail->next;
    }
  }
}

void delete_list( list_node **list )
{
  if( !list )
    return;

  list_node *temp, *node = *list;

  while( node ) {
    temp = node;
    node = node->next;
    free( temp );
  }

  *list = NULL;
}
