#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull MOD;

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

int main()
{
  MOD = 1e9 + 7;
  return 0;
}
