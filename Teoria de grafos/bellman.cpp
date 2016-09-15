#include <bits/stdc++.h>

using namespace std;

const int INF = 99999;

struct Edge
{
  int inicio , fin , costo;
};

vector < Edge > vertices; // Arreglo para almacenar los vertices
vector < int > costos; // Arreglo para guardar los costos
int numero_nodos , numero_vertices;

bool bellmanFord( int source ) // Retorna true si hay ciclo infinito , false si no
{
  costos.assign( numero_nodos , INF );
  costos[source] = 0;
  for( int k = 0 ; k < numero_nodos - 1 ; ++k ) // BellmanFord( O( V * E ) )
    for( int i = 0 ; i < vertices.size() ; ++i )
      if( costos[vertices[i].inicio] + vertices[i].costo < costos[vertices[i].fin] )
        costos[vertices[i].fin] = costos[vertices[i].inicio] + vertices[i].costo;
  for( int i = 0 ; i < vertices.size() ; ++i ) // Loop para detectar ciclo infinito
    if( costos[vertices[i].inicio] + vertices[i].costo < costos[vertices[i].fin] )
      return true;
  return false;
}

int main()
{
  return 0;
}
