// UVa 558.
namespace bfo {
int dist[MAXN], n = -1; // BUG: n sin asignar.
vector<ii> g[MAXN]; // u -> {v, cost}
bool relax(int u) {
  bool r = false;
  for (ii e : g[u]) {
    int v, cost; tie(v, cost) = e;
    if (dist[u] + cost < dist[v])
      dist[v] = cost + dist[u], r = true;
  }
  return r;
}
bool bford(int s) { // true -> ciclo negativo.
  foi (i,0,n) dist[i] = (i == s ? 0 : INF);
  foi (i,0,n) foi (u,0,n)
    if (dist[u] != INF && relax(u) && i == n - 1) return true;
  return false;
}}
