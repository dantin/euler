#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define BUFFER 50

typedef enum {
  In = 1,
  Out = 0
} state;

typedef struct ListNode {
  char *name;
  int position;
  int score;
  struct ListNode *next;
} list_node;

list_node *make_list_node( char *name, int score );
list_node *read_names( void );

int main( void )
{
  list_node *names = read_names();
  list_node *node;
  long score_sum;

  score_sum = 0L;
  for( node = names; node; node = node->next ) {
    score_sum += node->position * node->score;
  }

  printf( "%ld\n", score_sum );

  return 0;
}

list_node *make_list_node( char *name, int score )
{
  char *buffer = ( char * ) malloc( sizeof( char ) * ( strlen( name ) + 1 ) );
  assert( buffer );
  strcpy( buffer, name );
  buffer[ strlen( name ) ] = '\0';
  list_node *node = ( list_node * ) malloc( sizeof( list_node ) );
  assert( node );

  node->name = buffer;
  node->score = score;
  node->position = 0;
  node->next = NULL;

  return node;
}

list_node *read_names( void )
{
  char buffer[ BUFFER ];
  int c, i;
  state status;
  int score;
  list_node *node, *list, *iter;

  list = NULL;
  i = 0;
  score = 0;
  status = Out;
  while( ( c = getchar() ) != EOF ) {
    if( c == '"' && status == Out ) { // name begin
      status = In;
    } else if( c == '"' && status == In ) { // name end
      status = Out;
      buffer[i] = '\0';

      // make node
      node = make_list_node( buffer, score );
      if( list == NULL ) {
	list = node;
      } else {
	list_node *prev = NULL;
	iter = list;
	while( iter ) {
	  if( strcmp( node->name, iter->name ) < 0 ) {
	    break;
	  }
	  prev = iter;
	  iter = iter->next;
	}

	if( prev == NULL ) {
	  node->next = list;
	  list = node;
	} else {
	  node->next = iter;
	  prev->next = node;
	}
      }

    } else if( c == ',' ) { // separate name
      buffer[0] = '\0';
      i = 0;
      score = 0;
    } else if( status == In ) { // read name
      buffer[i++] = c;
      score += c - 'A' + 1;
    } else {
      ;
    }
  }

  for( i = 1, node = list; node; node = node->next ) {
    node->position = i++;
  }

  return list;
}
