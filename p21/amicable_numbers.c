#include <stdio.h>

#define SIZE 10000

int amicable_number( int number );

int main( void )
{
  int sum;
  int i;

  sum = 0;
  for( i = 1; i < SIZE; i++ ) {
    int j = amicable_number( i );
    int p = amicable_number( j );
    if( i == p && i != j ) {
      sum += i;
    }
  }

  printf( "%d\n", sum );

  return 0;
}

int amicable_number( int number )
{
  int sum;
  int i;

  sum = 0;
  for( i = 1; i <= number / 2; i++ ) {
    if( number % i == 0 ) {
      sum += i;
    }
  }

  return sum;  
}
