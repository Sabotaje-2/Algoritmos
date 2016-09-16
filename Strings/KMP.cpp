#include <bits/stdc++.h>

using namespace std;

vector < int > lps; // Arreglo temporal del patron(precalcular)

// Dado un patron k y una secuencia s, indique si s esta contenido en k en O( k.size() + s.size() )
// Se puede modificar para trabajar con strings o vector
bool kmp( vector < int > &original, vector < int > &pattern )
{
  int i = 0;
  int j = 0;
  while( i < original.size() && j < pattern.size() )
  {
      if( original[i] == pattern[j] )
      {
          ++i;
          ++j;
      }
      else
      {
          if( j != 0 )
              j = lps[j-1];
          else
              ++i;
      }
  }
  if( j == pattern.size() )
      return true;
  return false;
}

void arregloTemporal( vector < int > &pattern )
{
  lps.assign( pattern.size() , 0 );
  int index = 0 ;
  for( int i = 1 ; i < pattern.size() ;  )
  {
     if( pattern[i] == pattern[index] )
     {
         lps[i] = index + 1;
         ++index;
         ++i;
     }
     else
     {
         if( index != 0 )
             index = lps[index-1];
         else
         {
             lps[i] = 0;
             ++i;
         }
     }
  }
}

int main()
{
  return 0;
}
