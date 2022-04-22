namespace mbm {
  int lm[MAXL], rm[MAXR];
  bool vis[MAXL];

  int dfs(int u) {
    if (vis[u]) return 0;
    vis[u] = true;
    for (int v : g[u]) {
      if (rm[v] == -1 || dfs(rm[v])) {
        lm[u] = v;
        rm[v] = u;
        return 1;
      }
    }
    return 0;
  }

  int kuhn(int ln, int rn) {
    memset(lm, -1, sizeof lm);
    memset(rm, -1, sizeof rm);
    int ans = 0;
    for (int u = 0; u < ln; ++u) {
      if (lm[u] == -1) {
        fill(vis, vis+ln, false);
        ans += dfs(u);
      }
    }
    return ans;
  }
}
