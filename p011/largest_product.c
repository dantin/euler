#include <stdio.h>

#define ROWS 20
#define COLS 20
#define SIZE 4

#define HORIZONTAL 0
#define VERTICAL   1
#define DIAGONAL   2
#define CROSS      3

#define DIRECTION  4

int main( void )
{
  int grid[ROWS][COLS];
  int num;
  int i, j, k;
  int max;
  int product[DIRECTION];

  // read input data
  i = j = 0;
  while( scanf( "%d", &num ) ) {
    grid[i][j] = num;
    j++;
    if( j % COLS == 0 ) {
      i++;
      j = 0;
    }
    if( i > 0 && i % ROWS == 0 ) {
      break;
    }
  }

  max = 0;
  for( i = 0; i < ROWS; i++ ) {
    for( j = 0; j < COLS; j++ ) {
      for( k = 0; k < DIRECTION; k++ ) {
	product[k] = 1;
      }
      for( k = 0; k < SIZE; k++ ) {
	// horizontal
	if( product[HORIZONTAL] && j + k < COLS ) {
	  product[HORIZONTAL] *= grid[i][j + k];
	} else {
	  product[HORIZONTAL] = 0;
	}
	// vertical
	if( product[VERTICAL] && i + k < ROWS ) {
	  product[VERTICAL] *= grid[i + k][j];
	} else {
	  product[VERTICAL] = 0;
	}
	// diagonal
	if( product[DIAGONAL] && i + k < ROWS && j + k < COLS ) {
	  product[DIAGONAL] *= grid[i + k][j + k];
	} else {
	  product[DIAGONAL] = 0;
	}
	// cross
	if( product[CROSS] && i - k >= 0 && j + k < COLS ) {
	  product[CROSS] *= grid[i - k][j + k];
	} else {
	  product[CROSS] = 0;
	}
      }

      for( k = 0; k < DIRECTION; k++ ) {
	if( product[k] > max ) {
	  max = product[k];
	}
      }
    }
  }

  printf( "%d\n", max );

  return 0;
}
