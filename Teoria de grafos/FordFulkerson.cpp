// UVa 820.
namespace flows {
// BUG: s, t, sin asignar.
int f[MAXN][MAXN], s = -1, t = -1;
vector<int> g[MAXN];
bitset<MAXN> vis;
int dfs(int u, int b) {
  if (u == t) return b;
  vis[u] = true;
  int r;
  for (int v : g[u]) {
    if (!vis[v] && f[u][v] > 0 &&
      (r = dfs(v, min(b, f[u][v])))) {
      f[u][v] -= r; f[v][u] += r;
      return r;
    }
  }
  return 0;
}
int mflow() {
  for (int ans = 0;;) {
    vis.reset();
    int add = dfs(s, numeric_limits<int>::max());
    if (add == 0) return ans;
    ans += add;
  }
}}
