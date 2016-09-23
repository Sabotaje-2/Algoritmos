#include <bits/stdc++.h>

using namespace std;

const int INF = 99999;

struct Edge
{
  int inicio , fin , costo;
};

vector < Edge > aristas; // Arreglo para almacenar los aristas
vector < int > costos; // Arreglo para guardar los costos
int numero_nodos ;

bool bellmanFord( int source ) // Retorna true si hay ciclo infinito , false si no
{
  costos.assign( numero_nodos , INF );
  costos[source] = 0;
  for( int k = 0 ; k < numero_nodos - 1 ; ++k ) // BellmanFord( O( V * E ) )
    for( int i = 0 ; i < aristas.size() ; ++i )
      if( costos[aristas[i].inicio] + aristas[i].costo < costos[aristas[i].fin] )
        costos[aristas[i].fin] = costos[aristas[i].inicio] + aristas[i].costo;
  for( int i = 0 ; i < aristas.size() ; ++i ) // Loop para detectar ciclo infinito
    if( costos[aristas[i].inicio] + aristas[i].costo < costos[aristas[i].fin] )
      return true;
  return false;
}

int main()
{
  return 0;
}
