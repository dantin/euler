#include <stdio.h>
#include <stdbool.h>

int factor_sum( const int number );
bool is_perfect( const int number );
bool is_deficient( const int number );
bool is_abundant( const int number );

int main( void )
{
  int i, j;
  long sum = 0;
  for( i = 1; i < 28123; i++ ) {
    bool found = false;
    for( j = 1; j < i; j++ ) {
      if( is_abundant( j ) && is_abundant( i - j ) ) {
	found = true;
	break;
      }
    }
    if( !found ) {
      sum += i;
    }
  }
  printf( "%ld\n ", sum );

  return 0;
}

int factor_sum( const int number )
{
  int sum = 0;
  int i;

  for( i = 1; i <= number / 2; i++ ) {
    if( number % i == 0 ) {
      sum += i;
    }
  }

  return sum;
}

bool is_perfect( const int number )
{
  return number == factor_sum( number );
}

bool is_deficient( const int number )
{
  return number > factor_sum( number );
}

bool is_abundant( const int number )
{
  return number < factor_sum( number );
}
