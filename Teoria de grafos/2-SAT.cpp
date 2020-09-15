// Codeforces GYM 100342G.
namespace sat {
// [0, n) = x, [n, 2*n) = ~x.
int f[MAXN2], scc;
bool vis[MAXN2];
deque<int> topo;
vector<int> rg[MAXN2];
void dfs(int u) {
  vis[u] = true;
  for (int v : g[u])
    if (!vis[v]) dfs(v);
  topo.push_front(u);
}
void dfs2(int u) {
  vis[u] = true;
  f[u] = scc;
  for (int v : rg[u])
    if (!vis[v]) dfs2(v);
}
vector<int> solve(int n) {
  fill(vis, vis+2*n, false);
  for (int u = 0; u < 2*n; ++u) {
    if (!vis[u]) dfs(u);
    for (int v: g[u])
      rg[v].push_back(u);
  }
  fill(vis, vis+2*n, false); scc = 0;
  for (int u : topo)
    if (!vis[u]) dfs2(u), scc++;
  vector<int> ans(n);
  for (int u = 0; u < n; ++u)
    if (f[u] == f[u+n]) return {};
    else ans[u] = f[u+n] < f[u];
  return ans;
}}
