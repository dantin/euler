#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define NUMBER 600851475143L

typedef struct LongListNode {
  long long value;
  struct LongListNode *next;
} l_list_node;

l_list_node *find_primes( const long long number );
l_list_node *find_factors( long long number, const l_list_node *primes );

int main( void )
{
  l_list_node *primes = NULL;
  l_list_node *factors = NULL;
  l_list_node *node = NULL;

  primes = find_primes( 5000L );
  factors = find_factors( NUMBER, primes );

  while( primes ) {
    node = primes;
    primes = primes->next;
    free( node );
  }

  while( factors ) {
    node = factors;
    printf( "%d\n", factors->value );
    factors = factors->next;
    free( node );
  }

  return 0;
}

l_list_node *find_primes( const long long number )
{
  l_list_node *primes, *node;
  long i;

  // list candidates
  primes = NULL;
  for( i = 2; i <= number; i++ ) {
    if( i % 2 != 0 ) {
      node = ( l_list_node * ) malloc ( sizeof( l_list_node ) );
      assert( node );
      node->next = primes;
      node->value = i;

      primes = node;
    }
  }

  // reverse candidate list
  node = primes;
  primes = NULL;
  while( node ) {
    l_list_node *temp = node->next;
    node->next = primes;
    primes = node;
    node = temp;
  }

  // remove non-prime candidates
  node = primes;
  while( node ) {
    l_list_node *pre = node;
    l_list_node *cur = node->next;
    while( cur ) {
      if( cur->value % node->value == 0 ) {
	pre->next = cur->next;
	free( cur );
	cur = pre->next;
      } else {
	pre = cur;
	cur = cur->next;
      }
    }
    node = node->next;
  }

  // add 2
  node = ( l_list_node * ) malloc( sizeof( l_list_node ) );
  assert( node );
  node->value = 2L;
  node->next = primes;
  primes = node;

  return primes;
}

l_list_node *find_factors( long long number, const l_list_node *primes )
{
  l_list_node *factors = NULL;

  while( primes ) {
    while( number ) {
      if( number % primes->value == 0 ) {
	number /= primes->value;
	l_list_node *node = ( l_list_node * ) malloc( sizeof( l_list_node ) );
	assert( node );
	node->value = primes->value;
	node->next = factors;
	factors = node;
      } else {
	break;
      }
    }
    primes = primes->next;
  }

  if( number ) {
    l_list_node *node = ( l_list_node * ) malloc( sizeof( l_list_node ) );
    assert( node );
    node->value = number;
    node->next = factors;
    factors = node;
  }

  return factors;
}
