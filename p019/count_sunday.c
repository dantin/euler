#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define MONTHS 12
#define WEEK   7

int m_days[] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool is_leap_year( const int year );
int month_days( const int year, const int month );

int main( void )
{
  const int by = 1901, bm =  1, bd =  1;
  const int ey = 2000, em = 12, ed = 31;

  int y = 1900, m = 1, d = 1, w = 1;
  int sum = 0;

  while( 1 ) {
    d++;
    w++;
    if( w % WEEK == 0) {
      w = 0;
    }
    if( d > month_days( y, m ) ) {
      m++;
      d = 1;
    }
    if( m > MONTHS ) {
      y++;
      m = 1;
    }

    if( y >= by && y <= ey &&
	m >= bm && m <= em &&
	d >= bd && d <= ed ) {
      if( d == 1 && w == 0 ) {
	sum++;
      }
    } else if( y > ey ) {
      break;
    }
  }

  printf( "%d\n", sum );

  return 0;
}

bool is_leap_year( const int year )
{
  return ( ( year % 4 == 0 ) && ( year % 100 != 0 ) ) || ( year % 400 == 0 );
}

int month_days( const int year, const int month )
{
  assert( month > 0 && month < 13 );
  if( month != 2 ) {
    return m_days[ month ]; 
  } else if( is_leap_year( year ) ) {
    return m_days[ 0 ];
  } else {
    return m_days[ 2 ];
  }
}
