// UVa 820.
namespace flows {
// BUG: s, t, sin asignar.
int p[MAXN], f[MAXN][MAXN], mine, s = -1, t = -1;
bitset<MAXN> vis;
vector<int> g[MAXN];
bool bfs() {
  vis.reset(); vis[s] = true;
  p[s] = -1;
  queue<int> q; q.push(s);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v: g[u]) {
      if (!vis[v] && f[u][v] > 0) {
        q.push(v), p[v] = u, vis[v] = true;
        if (v == t) return true;
      }
    }
  }
  return false;
}
void path(int v) {
  int u = p[v];
  if (~u) {
    mine = min(mine, f[u][v]);
    path(u);
    f[u][v] -= mine;
    f[v][u] += mine;
  }
}
int mflow() {
  for (int ans = 0;;) {
    if (!bfs()) return ans;
    mine = numeric_limits<int>::max();
    path(t);
    ans += mine;
  }
}}
