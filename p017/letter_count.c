#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE   1000
#define BUFFER 100

char *to_19[] = {
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
  "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
  "sixteen", "seventeen", "eighteen", "nineteen", NULL
};

char *tens[] = {
  "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty",
  "ninety", NULL
};

char *denom[] = {
  "", "thousand", "million", "billion", "trillion",
  "quadrillion", "quintillion", "sextillion", "septillion",
  "octillion", "nonillion", "decillion", "undecillion",
  "duodecillion", "tredecillion", "quattuordecillion",
  "sexdecillion", "septendecillion", "octodecillion",
  "novemdecillion", "vigintillion", NULL
};

void convert_nn( char *buffer, int value );
void convert_nnn( char *buffer, int value );
void english_number( char *buffer, int value );

int main( void )
{
  char buffer[BUFFER];
  int i, count;

  count = 0;
  for( i = 1; i <= 1000; i++ ) {
    english_number( buffer, i );
    for( int j = 0; j < strlen( buffer ); j++ ) {
      char c = buffer[j];
      if( c == ' ' || c == '-' ) {
	continue;
      }
      count++;
    }
  }

  printf( "%d\n", count );

  return 0;
}

void convert_nn( char *buffer, int value )
{
  if( value < 20 ) {
    strcpy( buffer, to_19[ value ] );
  } else {
    char **tensp = tens;
    int i = 0;
    while( *tensp ) {
      int lower = 20 + 10 * i;
      if( lower + 10 > value ) {
	strcat( buffer, *tensp );
	if( value % 10 != 0 ) {
	  strcat( buffer, "-" );
	  strcat( buffer, to_19[ value % 10 ] );
	}
	break;
      }
      i++;
      tensp++;
    }
  }
}

void convert_nnn( char *buffer, int value )
{
  int rem = value / 100;
  int mod = value % 100;

  if( rem > 0 ) {
    strcat( buffer, to_19[ rem ] );
    strcat( buffer, " hundred" );
    if( mod > 0 ) {
      strcat( buffer, " and " );
    }
  }
  if( mod > 0 ) {
    convert_nn( buffer + strlen( buffer ), mod );
  }
}

void english_number( char *buffer, int value )
{
  buffer[0] = '\0';

  if( value < 100 ) {
    convert_nn( buffer, value );
    return;
  }
  if( value < 1000 ) {
    convert_nnn( buffer, value );
    return;
  }

  int i = 0;
  char **denomp = denom;
  while( *denomp ) {
    int didx = i - 1;
    int dval = pow( 1000, i );
    if( dval > value ) {
      int mod = pow( 1000, didx );
      int l = value / mod;
      int r = value - ( l * mod );
      convert_nnn( buffer, l );
      strcat( buffer, " " );
      strcat( buffer, denom[ didx ] );
      if( r > 0 ) {
	strcat( buffer, ", " );
	english_number( buffer + strlen( buffer ), r );
      }
      return;
    }
    i++;
    denomp++;
  }

}
