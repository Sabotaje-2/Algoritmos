// PROBAR
namespace cd {
  int sz[MAXN];
  bool done[MAXN];
  vector<ii> t[MAXN]; // {v,w}.

  void solve(int u) {
    // Process all paths that contains u.
    done[u] = true;
  }

  void fc(int u, int p) {
    for (auto x : t[u]) {
      int v = x.first;
      if (v == p || done[v]) continue;
      if (sz[v] > (sz[u] >> 1)) {
        sz[u] -= sz[v];
        sz[v] += sz[u];
        fc(v,u);
        return;
      }
    }
    solve(u);
    for (auto x : t[u]) {
      int v = x.first;
      if (!done[v]) fc(v,u);
    }
  }
}
