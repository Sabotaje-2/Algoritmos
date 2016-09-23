#include <bits/stdc++.h>

using namespace std;

#define max_nodos 100
// Topological sort
int numero_nodos , numero_aristas , grado_entrada[max_nodos];
vector < vector < int > > grafo; // Grafo con lista de adyacencia

int main()
{
  int origen , llegada , voy;
  while( scanf("%d %d", &numero_nodos , &numero_aristas ) , numero_nodos || numero_aristas )
  {
    queue < int > kahn;
    grafo.assign( numero_nodos , vector < int >() );
    memset( grado_entrada , 0 , sizeof grado_entrada );
    for( int i = 0 ; i < numero_aristas ; ++i )
    {
      scanf("%d %d", &origen , &llegada );
      ++grado_entrada[llegada];
      grafo[origen].push_back( llegada );
    }
    for( int i = 0 ; i < numero_nodos ; ++i )
      if( grado_entrada[i] == 0 )
        kahn.push( i );
    while( !kahn.empty() )
    {
      voy = kahn.front();
      printf("%d\n", voy );
      kahn.pop();
      for( int i = 0 ; i < grafo[voy].size() ; ++i )
        if( --grado_entrada[grafo[voy][i]] == 0 )
          kahn.push( grafo[voy][i] );
    }
  }
  return 0;
}
