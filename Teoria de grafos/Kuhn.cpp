vector < vector < int > > g;
bitset < MAX_N > visited;
int n,k,matching[MAX_K];
// n = numero de nodos en izquierda
// k = numero de nodos en la derecha
// matching[i] = nodo de la izquierda que matchea con i
bool kuhn(int u) {
  if(visited[u])  return false;
  visited[u] = true;
  int v;
  foi(i,0,g[u].size()) {
    v = g[u][i];
    if(matching[v] == -1 || kuhn(matching[v])) {
      matching[v] = u;
      return true;
    }
  }
  return false;
}
int kuhn() {
  int max_matching = 0;
  memset(matching, -1, sizeof matching);
  foi(i,0,n) {
    visited.reset();
    max_matching += kuhn(i);
  }
  return max_matching;
}
