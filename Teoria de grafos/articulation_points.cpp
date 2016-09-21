#include <bits/stdc++.h>

using namespace std;

#define MAX_NUMERO_NODOS 1000

bitset < MAX_NUMERO_NODOS > visited; // bitmask para guardar nodos visitados
int parent[MAX_NUMERO_NODOS]; // guardar el padre de cada nodo en el dfs
int dfs_low[MAX_NUMERO_NODOS]; // minima iteracion en la cual visito este nodo
int dfs_num[MAX_NUMERO_NODOS]; // primera iteracion en la cual visito este nodo
int iteration_counter; // contador para ver en que recursion voy
int root_dfs; // nodo desde el cual se comenzo el dfs
int children; // guardar numero de hijos de la raiz
vector < vector < int > > grafo; // grafo almacenado como lista de adyacencia
bitset < MAX_NUMERO_NODOS > ap; // array para guardar puntos de articulacion

void articulation_points( int from )
{
  visited[from] = true;
  dfs_low[from] = dfs_num[from] = iteration_counter++;
  for( int i = 0 ; i < grafo[from].size() ; ++i )
  {
    int to = grafo[from][i];
    if( !visited[to] )
    {
      parent[to] = from;
      articulation_points(to);
      if( root_dfs == from ) ++children;
      dfs_low[from] = min( dfs_low[from] , dfs_low[to] );
      if( dfs_low[to] >= dfs_num[from] && parent[from] != -1 )
        ap[from] = true;
    }
    else if( parent[from] != to )
      dfs_low[from] = min( dfs_low[from] , dfs_num[to] );
  }
}

int main()
{
  int num_nodos , num_vertices , origen , destino ;
  while( scanf("%d %d", &num_nodos , &num_vertices ) , num_nodos )
  {
    grafo.assign( num_nodos , vector < int > () );
    visited.reset();
    ap.reset();
    memset( parent , -1 , sizeof parent );
    memset( dfs_low , 0 , sizeof dfs_low );
    memset( dfs_num , 0 , sizeof dfs_num );
    for( int i = 0 ; i < num_vertices ; ++i )
    {
      scanf("%d %d", &origen , &destino );
      grafo[origen].push_back(destino);
      grafo[destino].push_back(origen);
    }
    iteration_counter = 0;
    for( int i = 0 ; i < num_nodos ; ++i )
      if( !visited[i] )
      {
        root_dfs = i;
        children = 0;
        articulation_points(i);
        if( children > 1 )
          ap[i] = true;
      }
  for( int i = 0 ; i < MAX_NUMERO_NODOS ; ++i ) if( ap[i] )printf("Un punto de articulacion es %d\n", i );
  }
  return 0;
}
