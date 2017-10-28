struct lca {
    vector<vector<int>> f,pw;
    vector<int> l;
    int MAX_LOG;
    lca(vector<vector<ii>>& tree) {
        MAX_LOG = 1 + floor(log2(tree.size()));
        f.assign(tree.size(), vector<int>(MAX_LOG, -1));
        pw.assign(tree.size(), vector<int>(MAX_LOG, -1));
        l.resize(tree.size());
        f[0][0] = 0;
        pw[0][0] = numeric_limits<int>::min();
        dfs(tree);
        foi(i,1,MAX_LOG)
            foi(u,0,tree.size()) {
                f[u][i] = f[f[u][i-1]][i - 1];
                pw[u][i] = max(pw[u][i - 1], pw[f[u][i-1]][i - 1]);
            }
    }
    void dfs(vector<vector<ii>>& tree, int u = 0, int lvl = 0) {
        int v,cost;
        l[u] = lvl;
        foi(i,0,tree[u].size()) {
            v = tree[u][i].first;
            cost = tree[u][i].second;
            if(f[u][0] != v) {
                f[v][0] = u;
                pw[v][0] = cost;
                dfs(tree, v, 1 + lvl);
            }
        }
    }
    ii query(int u, int v) {
        int maxi = numeric_limits<int>::min();
        if(l[u] < l[v]) swap(u,v);
        for(int i = MAX_LOG - 1; i >= 0; --i)
            if(l[f[u][i]] >= l[v]) {
                maxi = max(maxi, pw[u][i]);
                u = f[u][i];
            }
        if(u == v) return ii(u, maxi);
        for(int i = MAX_LOG - 1; i >= 0; --i)
            if(f[u][i] != f[v][i]) {
                maxi = max(maxi, pw[u][i]);
                maxi = max(maxi, pw[v][i]);
                u = f[u][i];
                v = f[v][i];
            }
        return ii(f[u][0],max(maxi, max(pw[u][0], pw[v][0]))); // lca(u,v), max_edge(u,v)
    }};
