namespace lca {
    // build O(Vlog(V)), query O(log(V))
    const int MAXN = 1+1000*1000; // Max No. Nodos
    const int MAXLG = 21; // 2^(MAXLG-1) > MAXN
    vector<int> t[MAXN];
    int f[MAXLG][MAXN], lv[MAXN];
    void dfs(int u, int lvl) {
        lv[u] = lvl;
        for(int v : t[u])
            if(f[0][u] != v)
                f[0][v] = u, dfs(v, 1 + lvl);
    }
    void build(int n, int r) { // |V|, nodo raiz
        f[0][r] = r; dfs(r,0);
        foi(i,1,MAXLG) foi(u,0,n)
            f[i][u] = f[i - 1][f[i - 1][u]];
    }
    int query(int u, int v) {
        if(lv[u] < lv[v]) swap(u,v);
        for(int i = MAXLG - 1; i >= 0; --i)
            if(lv[f[i][u]] >= lv[v])
                u = f[i][u];
        if(u == v) return u;
        for(int i = MAXLG - 1; i >= 0; --i)
            if(f[i][u] != f[i][v])
                u = f[i][u], v = f[i][v];
        return f[0][u];
    }
    int dist(int u, int v) {
      return lv[u] + lv[v] - 2*lv[query(u,v)];
    }}
