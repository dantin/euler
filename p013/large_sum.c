#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct ListNode {
  int value;
  struct ListNode *next;
} list_node;

list_node *make_list_node( const int value );
int read( list_node **list );
list_node * add( list_node **sum, list_node **number );
list_node *reverse( list_node *list );
void print( list_node **list, unsigned int size );

int main( void )
{
  list_node *sum = NULL;
  list_node *number = NULL;

  while( read( &number ) != EOF ) {
    //print( &number, 0 );
    sum = add( &sum, &number );
    print( &sum, 0 );
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

list_node *add( list_node **num_a, list_node **num_b )
{
  list_node *pa, *pb, *node, *tail, *temp;
  list_node *sum;

  if( *num_a == NULL ) {
    pb = *num_b;
    tail = NULL;
    while( pb ) {
      node = make_list_node( pb->value );
      if( tail ) {
	tail->next = node;
	tail = node;
      } else {
	sum = node;
	tail = node;
      }
      temp = pb;
      pb = pb->next;
      free( temp );
    }
    *num_b = NULL;
  } else {
    sum = NULL;
    tail = NULL;

    pa = reverse( *num_a );
    pb = reverse( *num_b );

    int remaining = 0;
    while( pa || pb ) {
      int a = pa ? pa->value : 0;
      int b = pb ? pb->value : 0;

      node = make_list_node( ( a + b + remaining ) % 10 );
      remaining = ( a + b + remaining) / 10;

      if( sum ) {
	node->next = sum;
	sum = node;
      } else {
	sum = node;
      }      

      if( pa ) {
	temp = pa;
	pa = pa->next;
	free( temp );
      }
      if( pb ) {
	temp = pb;
	pb = pb->next;
	free( temp );
      }
    }

    while( remaining ) {
      node = make_list_node( remaining % 10 );
      node->next = sum;
      sum = node;
      remaining /= 10;
    }

    *num_a = NULL;
    *num_b = NULL;
  }

  return sum;
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

void print( list_node **list, unsigned int size )
{
  list_node *node = *list;
  
  while( node ) {
    printf( "%d", node->value );
    node = node->next;
  }

  printf( "\n" );
}
