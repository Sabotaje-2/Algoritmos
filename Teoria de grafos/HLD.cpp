struct hld {
    vector<int> sts,p;
    vector<int> to_chain,chain_head; // chains info
    vector<int> tour,pos; // nodes info
    int n,chains;
    lca l;
    stree t;
    hld(vector<vector<int>>& g, vector<int>& w) {
        sts.resize(n = g.size());
        p.resize(n);
        to_chain.resize(n);
        chain_head.assign(n, -1);
        pos.resize(n);
        chains = 0;
        dfs(g);
        decompose(g, w);
        l = lca(g);
        t = stree(tour);
    }
    int dfs(vector<vector<int>>& g, int u = 0) {
        sts[u] = 1;
        for(const int& v: g[u])
            if(p[u] != v) {
                p[v] = u;
                sts[u] += dfs(g, v);
            }
        return sts[u];
    }
    void decompose(vector<vector<int>>& g, vector<int>& w, int u = 0) {
        to_chain[u] = chains;
        if(chain_head[chains] == -1)
            chain_head[chains] = u;
        pos[u] = tour.size();
        tour.push_back(w[u]);
        int sc = -1, sc_size;
        for(const int& v: g[u])
            if(p[u] != v && (sc == -1 || sts[v] > sc_size)) {
                sc_size = sts[v];
                sc = v;
            }
        if(~sc)
            decompose(g, w, sc);
        for(const int& v: g[u])
            if(p[u] != v && v != sc) {
                ++chains;
                decompose(g, w, v);
            }
    }
    void update(int u, int neww, vector<int>& w) {
        w[u] += neww;
        t.update(pos[u], w[u]);
    }
    int query2(int u, int v) {
        int uchain = to_chain[u], up;
        int ans = numeric_limits<int>::min();
        for(;;) {
            if(uchain == to_chain[v]) {
                ans = max(ans, t.query(pos[v], pos[u]));
                return ans;
            }
            up = chain_head[uchain];
            ans = max(ans, t.query(pos[up], pos[u]));
            u = p[up];
            uchain = to_chain[u];
        }
    }
    int query(int u, int v) {
        int lcanode = l.query(u,v);
        return max(query2(u, lcanode), query2(v, lcanode));
    }};
