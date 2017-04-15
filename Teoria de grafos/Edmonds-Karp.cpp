int p[MAX_NODOS], f[MAX_NODOS][MAX_NODOS], mine;
// reiniciar el flujo(f) a 0 en cada caso
vector < vector < int > > g;
bool bfs(int source, int sink) {
  memset(p, -1, sizeof p);
  int u,v;
  queue < int > q;
  q.push(source);
  p[source] = DUMMY; // DUMMY <= -2
  while(q.size()) {
    u = q.front();
    q.pop();
    if(u == sink) return true;
    foi(i,0,g[u].size()) {
      v = g[u][i];
      if(p[v] == -1 && f[u][v] > 0)
        q.push(v), p[v] = u;
    }
  }
  return false;
}
void path(int u) {
  if(p[u] == DUMMY) return;
  mine = min(mine, f[p[u]][u]);
  path(p[u]);
  f[p[u]][u] -= mine;
  f[u][p[u]] += mine;
}
int max_flow(int source, int sink) {
  int flow = 0;
  while(bfs(source, sink)) {
    mine = INF;
    path(sink);
    flow += mine;
  }
  return flow;
}
