// UVa 820.
namespace flows {
  int f[MAXN][MAXN];
  vector<int> g[MAXN];
  bitset<MAXN> vis;

  int dfs(int u, int t, int b) {
    if (u == t) return b;
    vis[u] = true;
    int r;
    for (int v : g[u]) {
      if (!vis[v] && f[u][v] > 0 && (r = dfs(v, t, min(b, f[u][v])))) {
        f[u][v] -= r; f[v][u] += r;
        return r;
      }
    }
    return 0;
  }

  int ff(int s, int t) {
    for (int ans = 0;;) {
      vis.reset();
      int x = dfs(s, t, numeric_limits<int>::max());
      if (x == 0) return ans;
      ans += x;
    }
  }
}
