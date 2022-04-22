// PROBAR
namespace scc {
  int mscc[MAXN], sccn = 0;
  vector<int> g[MAXN], rg[MAXN];
  deque<int> ts;
  bool vis[MAXN];

  void dfs(int u, bool revg) {
    vis[u] = true;
    const auto& gw = (revg ? rg : g);
    for (int v : gw[u])
      if (!vis[v]) dfs(v,revg);
    if (!revg) ts.push_front(u);
    else mscc[u] = sccn;
  }

  void kos(int n) {
    fill(vis, vis+n, false);
    for (int u = 0; u < n; ++u) {
      if (!vis[u]) dfs(u,false);
      for (int v : g[u]) rg[v].push_back(u);
    }
    fill(vis, vis+n, false);
    for (int u : ts)
      if (!vis[u]) dfs(u,true), sccn++;
  }
}
