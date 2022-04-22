// Codeforces GYM 100342I.
namespace apb {
  int c[MAXN], tim, d[MAXN], dlow[MAXN], DROOT;
  bool ap[MAXN]; // ap[u] = is u an AP?

  int dfs(int u, int p) {
    c[u] = 0;
    d[u] = dlow[u] = ++tim;
    int vis = 0;
    for (int v : g[u]) {
      if (v == p || c[v] == 1) continue;
      if (c[v] == -1) {
        dlow[u] = min(dlow[u], dfs(v,u));
        if (dlow[v] > d[u]) {} // Bridge (u,v)
        ap[u] |= (dlow[v] >= d[u]);
        vis++;
      } else {
        dlow[u] = min(dlow[u], d[v]);
      }
    }
    if (u == DROOT) { // AP
      ap[u] = (vis >= 2);
    }
    c[u] = 1;
    return dlow[u];
  }

  void solve(int n) {
    tim = 0;
    fill(c, c+n, -1);
    ap.reset(); // AP
    for (int i = 0; i < n; ++i) {
      if (c[i] == -1) {
        DROOT = i; // AP
        dfs(i,-1);
      }
    }
  }
}
