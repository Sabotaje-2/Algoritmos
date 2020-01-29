// PROBAR
namespace kos {
vector<int> g[MAXN], rg[MAXN], scc[MAXN]; // scc to nodes
// BUG: n sin asignar.
int my_scc[MAXN], sccno = 0, n = -1; // node to scc, sccno = # of scc
stack<int> ts;
bool vis[MAXN];
void dfs(int u, bool revg) {
  vis[u] = true;
  if (revg) scc[sccno].push_back(u), my_scc[u] = sccno;
  const auto& gw = (revg ? rg : g);
  for (int v : gw[u]) if(!vis[v]) dfs(v,revg);
  if (!revg) ts.push(u);
}
void solve() {
  foi (i,0,n) vis[i] = false;
  foi (u,0,n) {
    if (!vis[u]) dfs(u,false);
    for (int v : g[u]) rg[v].push_back(u);
  }
  foi (i,0,n) vis[i] = false;
  while (!ts.empty()) {
    int u = ts.top();ts.pop();
    if (!vis[u]) dfs(u,true), sccno++;
  }
}}
