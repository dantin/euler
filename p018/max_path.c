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
node *copy_list( node *list );
node *reverse_list( node *list );

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
	  if( pp == NULL && pc == NULL ) {
	    // will not happen
	  } else if( pp == NULL && pc != NULL ) {
	    pn = make_node( pc->value );
	    pn->next = copy_list( pc->path );
	    cc->weight = pc->weight + cc->value;
	    cc->path = pn;
	  } else if( pc == NULL && pp != NULL) {
	    pn = make_node( pp->value );
	    pn->next = copy_list( pp->path );
	    cc->weight = pp->weight + cc->value;
	    cc->path = pn;
	  } else if( pp->weight > pc->weight ) {
	    pn = make_node( pp->value );
	    pn->next = copy_list( pp->path );
	    cc->weight = pp->weight + cc->value;
	    cc->path = pn;
	  } else {
	    pn = make_node( pc->value );
	    pn->next = copy_list( pc->path );
	    cc->weight = pc->weight + cc->value;
	    cc->path = pn;
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
  node *max_node = NULL;
  node *path;
  pn = plist;
  while( pn ) {
    if( max < pn->weight ) {
      max = pn->weight;
      max_node = pn;
    }
    pn = pn->next;
  }

  path = make_node( max_node->value );
  path->next = copy_list( max_node->path );
  path = reverse_list( path );
  print( path );

  destory_list( &path );
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
    if( tp->path ) {
      destory_list( &( tp->path ) );
    }
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

node *copy_list( node *list )
{
  node *copy = NULL;
  node *tail, *node;

  while( list ) {
    node = make_node( list->value );
    if( copy == NULL ) {
      copy = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }

    list = list->next;
  }

  return copy;
}

node *reverse_list( node *list )
{
  node *reversed = NULL;
  node *n;

  while( list ) {
    n = list;
    list = list->next;
    n->next = reversed;
    reversed = n;
  }

  return reversed;
}
