#include <bits/stdc++.h>

using namespace std;

#define num_elementos 1000
#define max_peso 1000

int dp[num_elementos][max_peso]; // Matriz para memoizar
int beneficio[num_elementos]; // Arreglo para guardar beneficio
int costo[num_elementos]; // Arreglo para guardar costo

int knap( int i , int peso )
{
  if( i == num_elementos || peso == 0 ) // Si ya no puedo seguir tomando objetos
    return 0;
  if( dp[i][peso] != -1 ) // Si ya lo calcule anteriormente
    return dp[i][peso];
  if( costo[i] > peso ) // Si no puedo tomar este objeto
    return dp[i][peso] = knap( i + 1, peso );
  return dp[i][peso] = max( knap( i + 1, peso ), beneficio[i] + knap( i + 1, peso - costo[i] ) ); // Probar todo
}

int main()
{
  return 0;
}
