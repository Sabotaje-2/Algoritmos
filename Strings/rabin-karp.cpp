#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
#define MAX_CADENA 500000

const ull PRIME = 3ULL;
const ull MOD = 1e9+7ULL;
ull minv; // modular inverse
int plen , tlen; // pattern length & text length

ull fastPow(ull base , ull exponente) // Calcular x^y en log(y)
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

bool compare( char *text , char * pattern , int p )
{
    for(int i = 0 ; i < plen ; ++i)
      if(pattern[i] != text[i+p]) return false;
    return true;
}

// Pattern Substring search , search pattern in text, worst case O( plen * tlen ) , average case O( tlen + plen )
int rabin_karp(char *text , char *pattern)
{
  ull hp , pp , ht ; // hash_pattern , prime_power & hash_text
  hp = ht = 0ULL;
  plen = strlen(pattern);
  tlen = strlen(text);
  pp = 1;
  for(int i = 0 ; i < plen ; ++i)
  {
    hp = (hp + pattern[i] * pp) % MOD;
    ht = (ht + text[i] * pp) % MOD;
    pp = (pp * PRIME) % MOD;
  }
  pp = (pp * minv) % MOD;
  if( hp == ht )
    if(compare(text , pattern , 0))  return 0;
  for(int i = plen ; i < tlen ; ++i)
  {
    ht = (ht - text[ i - plen ] + MOD) % MOD;
    ht = (ht * minv) % MOD;
    ht = (ht + ((text[i] * pp) % MOD)) % MOD;
    if(ht == hp)
      if(compare(text , pattern , i - plen + 1)) return i - plen + 1;
  }
  return -1;
}

int main()
{
  int index_found;
  minv = fastPow( PRIME , MOD - 2 );
  char pattern[MAX_CADENA] , text[MAX_CADENA];
  while(scanf("%s%s", text , pattern) != EOF)
  {
    index_found = rabin_karp(text , pattern);
    if(index_found == -1)
      puts("Pattern not found");
    else
      printf("Pattern found at index %d\n", index_found);
  }
  return 0;
}
