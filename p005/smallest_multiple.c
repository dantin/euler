#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define MAX   20

typedef struct ListNode {
  int value;
  struct ListNode *next;
} list_node;

list_node *make_list_node( const int value );
void find_primes( const int low, const int high, list_node **primes );
void delete_list( list_node **list );

int main( void )
{
  list_node *primes = NULL;

  primes = make_list_node( 2 );
  // find primes under MAX
  find_primes( 2, MAX, &primes );

  const int limit = sqrt( MAX );
  int lcm = 1; // least common multiple

  while( primes ) {
    int power = 1;

    // find power of each prime
    if( primes->value <= limit ) {
      power = floor( log( MAX ) / log( primes->value ) );
    } else {
      power = 1;
    }

    lcm *= ( int )pow( primes->value, power );
    primes = primes->next;
  }
  delete_list( &primes );

  printf( "%d\n", lcm );

  return 0;
}

list_node *make_list_node( const int value )
{
  list_node *node = ( list_node * )malloc( sizeof( list_node ) );
  assert( node );
  node->value = value;
  node->next = NULL;

  return node;
}

void find_primes( const int low, const int high, list_node **primes )
{
  list_node *tail, *node;
  int i;

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
