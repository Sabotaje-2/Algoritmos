// PROBAR
namespace APB {
int c[MAXN], tim, d[MAXN], dlow[MAXN], DROOT;
bitset<MAXN> ap; // ap[u] = es u AP?
int dfs(int u, int p) {
  c[u] = 0;
  d[u] = dlow[u] = ++tim;
  int vis = 0;
  for (int v : g[u]) {
    if (v == p || c[v] == 1) continue;
    if (c[v] == -1) {
      dlow[u] = min(dlow[u], dfs(v,u));
      if (dlow[v] > d[u]) {} // Puente (u,v)
      if (dlow[v] >= d[u]) { // u es AP
        ap[u] = true;
      }
      vis++;
    } else {
      dlow[u] = min(dlow[u], d[v]);
    }
  }
  if (u == DROOT) { // Solo para AP
    ap[u] = (vis >= 2);
  }
  c[u] = 1;
  return dlow[u];
}
void init(int n) {
  tim = 0;
  fill(c, c+n, -1);
  ap.reset(); // Solo para AP
  for (int i = 0; i < n; ++i) {
    if (c[i] == -1) {
      DROOT = i; // Solo para AP
      dfs(i,-1);
    }
  }
}}
