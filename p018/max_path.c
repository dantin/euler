#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
  int value;
  int weight;
  struct Node *path;
  struct Node *next;
} node;

node *make_node( const int value );
void destory_list( node **list );
void print( node *list );

int main( void )
{
  int i, line, count;
  int num;
  node *clist, *plist, *pn, *tail;

  i = line = 0;
  count = 1;
  clist = plist = NULL; // set current list and previous list to NULL
  while( scanf( "%d", &num ) != EOF ) {
    // add node to current list
    pn = make_node( num );
    if( clist == NULL ) {
      clist = pn;
      tail = pn;
    } else {
      tail->next = pn;
      tail = pn;
    }

    if( ++i == count ) { // end of current list
      // set ending of the next line
      line++;
      count += line + 1;

      if( plist == NULL ) {
	plist = clist;
      } else {
	node *pp; // parent list's previous node
	node *pc; // parent list's current node
	node *cc; // current list's current node

	// set weight of current list
	pp = NULL;
	pc = plist;
	cc = clist;
	while( cc ) {
	  if( pp == NULL ) {
	    cc->weight = pc->weight + cc->value;
	  } else if( pc == NULL ) {
	    cc->weight = pp->weight + cc->value;
	  } else if( pp->weight > pc->weight ) {
	    cc->weight = pp->weight + cc->value;
	  } else {
	    cc->weight = pc->weight + cc->value;
	  }

	  pp = pc;
	  if( pc != NULL ) {
	    pc = pc->next;
	  }
	  cc = cc->next;
	}
	destory_list( &plist );
	plist = clist;
      }
      clist = NULL;
    }
  }

  int max = 0;
  pn = plist;
  while( pn ) {
    if( max < pn->weight ) {
      max = pn->weight;
    }
    pn = pn->next;
  }
  destory_list( &plist );

  printf( "max total: %d\n", max );

  return 0;
}

node *make_node( const int value )
{
  node *n = ( node * ) malloc( sizeof( node ) );
  assert( n );
  n->value = value;
  n->weight = value;
  n->path = NULL;
  n->next = NULL;

  return n;
}

void destory_list( node **list )
{
  node *cp, *tp;

  if( !list ) {
    return;
  }

  cp = *list;
  while( cp ) {
    tp = cp;
    cp = cp->next;
    free( tp );
  }

  *list = NULL;
}

void print( node *list )
{
  while( list ) {
    printf( "%d ", list->value );
    list = list->next;
  }
}
