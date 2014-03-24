#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define NUMBER 600851475143L
#define SCALE  2L

typedef struct ListNode {
  long long value;
  struct ListNode *next;
} list_node;

list_node *make_list_node( const long long value );
void find_primes ( const long long low, const long long high, list_node **primes );
long long find_factors( long long number, list_node **primes, list_node **factors );
void delete_list( list_node **list );

int main( void )
{
  list_node *primes = NULL;
  list_node *factors = NULL;
  list_node *node = NULL;
  long long low = 1L;
  long long high = 2L;
  long long number;

  primes = make_list_node( 2L );
  number = NUMBER;

  while( number != 1 ) {
    find_primes( low, high, &primes );
    number = find_factors( number, &primes, &factors );
    low = high;
    high *= SCALE;
  }

  long long max_prime_factor = 0L;
  while( factors ) {
    if( factors->value > max_prime_factor ) {
      max_prime_factor = factors->value;
    }
    factors = factors->next;
  }
  delete_list( &primes );
  delete_list( &factors );

  printf( "%ld\n", max_prime_factor );
  
  return 0;
}

list_node *make_list_node( const long long value )
{
  list_node *node = ( list_node * ) malloc( sizeof( list_node ) );
  assert( node );
  node->value = value;
  node->next = NULL;

  return node;
}

void find_primes( const long long low, const long long high, list_node **primes  )
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
      tail->next = make_list_node( i );
      tail = tail->next;
    }
  }
}

long long find_factors( long long number, list_node **primes, list_node **factors )
{
  list_node *node = *primes;
  while( node ) {
    while( number ) {
      if( number % node->value == 0 ) {
	number /= node->value;
        list_node *temp = make_list_node( node->value );
	temp->next = *factors;
	*factors = temp;
      } else {
	break;
      }
    }
    node = node->next;
  }

  return number;
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
