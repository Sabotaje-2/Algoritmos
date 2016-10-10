#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
#define MAX_CADENA 500000

const ull PRIME = 3ULL;
const ull MOD = 1e9+7ULL;
ull modular_inverse;
int tam_pattern , tam_text;

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
    for( int i = 0 ; i < tam_pattern ; ++i )
      if( pattern[i] != original_text[i+p] ) return false;
    return true;
}

// Pattern Substring search , search pattern in original_text, worst case O( tam_pattern * tam_text ) , average case O( tam_text + tam_pattern )
int rabin_karp( char *original_text , char *pattern )
{
  ull hash_pattern , prime_power , hash_text ;
  hash_pattern = hash_text = false;
  tam_pattern = strlen( pattern );
  tam_text = strlen( original_text );
  prime_power = 1;
  for( int i = 0 ; i < tam_pattern ; ++i )
  {
    hash_pattern = ( hash_pattern + pattern[i] * prime_power ) % MOD;
    hash_text = ( hash_text + original_text[i] * prime_power ) % MOD;
    prime_power = ( prime_power * PRIME ) % MOD;
  }
  prime_power = ( prime_power * modular_inverse ) % MOD;
  if( hash_pattern == hash_text )
    if( compare( original_text , pattern , 0 ) )  return 0;
  for( int i = tam_pattern ; i < tam_text ; ++i )
  {
    hash_text = ( hash_text - original_text[ i - tam_pattern ] + MOD ) % MOD;
    hash_text = ( hash_text * modular_inverse ) % MOD;
    hash_text = ( hash_text + ( ( original_text[i] * prime_power ) % MOD ) ) % MOD;
    if( hash_text == hash_pattern )
      if( compare( original_text , pattern , i - tam_pattern + 1 ) ) return i - tam_pattern + 1;
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
