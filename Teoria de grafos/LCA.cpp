// Kattis Tourists.
namespace lca {
// BUG: n sin asignar.
int f[MAXN][MAXLOG], lv[MAXN], n = -1;
vector<int> t[MAXN];
void dfs(int u, int lvl) {
  lv[u] = lvl;
  for (int v : t[u]) {
    if (f[u][0] != v) {
      f[v][0] = u;
      dfs(v, 1+lvl);
    }
  }
}
void init() {
  f[0][0] = 0; dfs(0,1);
  for (int i = 1; i < MAXLOG; ++i)
    for (int u = 0; u < n; ++u)
      f[u][i] = f[f[u][i-1]][i-1];
}
int query(int u, int v) {
  if (lv[u] < lv[v]) swap(u,v);
  for (int i = MAXLOG-1; i >= 0; --i) {
    if (lv[f[u][i]] >= lv[v])
      u = f[u][i];
  }
  if (u == v) return u;
  for (int i = MAXLOG-1; i >= 0; --i) {
    if (f[u][i] != f[v][i])
      u = f[u][i], v = f[v][i];
  }
  return f[u][0];
}}
