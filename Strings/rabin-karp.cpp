#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
#define MAX_CADENA 500000

const ull PRIME = 3ULL;
const ull MOD = 1e9+7ULL;
ull modular_inverse;
int plen , tlen; // pattern length & text length

ull fastPow( ull base , ull exponente ) // Calcular x^y en log(y)
{
  ull res = base , llevo = 1;
  int i = 0;
  while( ( 1LL << i ) <= exponente )
  {
    if( ( exponente & ( 1LL << i ) ) != 0 )
      llevo = ( llevo * res ) % MOD;
    res = res * res % MOD;
    ++i;
  }
  return llevo;
}

bool compare( char *original_text , char * pattern , int p )
{
    for( int i = 0 ; i < plen ; ++i )
      if( pattern[i] != original_text[i+p] ) return false;
    return true;
}

// Pattern Substring search , search pattern in original_text, worst case O( plen * tlen ) , average case O( tlen + plen )
int rabin_karp( char *original_text , char *pattern )
{
  ull hp , pp , ht ; // hash_pattern , prime_power & hash_text
  hp = ht = 0ULL;
  plen = strlen( pattern );
  tlen = strlen( original_text );
  pp = 1;
  for( int i = 0 ; i < plen ; ++i )
  {
    hp = ( hp + pattern[i] * pp ) % MOD;
    ht = ( ht + original_text[i] * pp ) % MOD;
    pp = ( pp * PRIME ) % MOD;
  }
  pp = ( pp * modular_inverse ) % MOD;
  if( hp == ht )
    if( compare( original_text , pattern , 0 ) )  return 0;
  for( int i = plen ; i < tlen ; ++i )
  {
    ht = ( ht - original_text[ i - plen ] + MOD ) % MOD;
    ht = ( ht * modular_inverse ) % MOD;
    ht = ( ht + ( ( original_text[i] * pp ) % MOD ) ) % MOD;
    if( ht == hp )
      if( compare( original_text , pattern , i - plen + 1 ) ) return i - plen + 1;
  }
  return -1;
}

int main()
{
  int index_found;
  modular_inverse = fastPow( PRIME , MOD - 2 );
  char pattern[MAX_CADENA] , original_text[MAX_CADENA];
  while( scanf("%s%s", original_text , pattern ) != EOF )
  {
    index_found = rabin_karp( original_text , pattern );
    if( index_found == -1 )
      puts( "Pattern not found" );
    else
      printf("Pattern found at index %d\n", index_found );
  }
  return 0;
}
