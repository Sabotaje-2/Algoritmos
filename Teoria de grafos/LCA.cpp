// LCA para responder queries en O(lgn).
// Se construye en O(nlgn).
// Kattis Tourists.
namespace lca {
vector<int> t[MAXN];
// BUG: n sin asignar.
int f[MAXN][MAXLG], lv[MAXN], n = -1;
void dfs(int u, int lvl) {
  lv[u] = lvl;
  for (int v : t[u])
    if (f[u][0] != v)
      f[v][0] = u, dfs(v, 1 + lvl);
}
void build() {
  f[0][0] = 0; dfs(0,1);
  foi (i,1,MAXLG) foi (u,0,n)
    f[u][i] = f[f[u][i - 1]][i - 1];
}
int query(int u, int v) {
  if (lv[u] < lv[v]) swap(u,v);
  for (int i = MAXLG - 1; i >= 0; --i)
    if (lv[f[u][i]] >= lv[v])
      u = f[u][i];
  if (u == v) return u;
  for (int i = MAXLG - 1; i >= 0; --i)
    if (f[u][i] != f[v][i])
      u = f[u][i], v = f[v][i];
  return f[u][0];
}}
