namespace kos {
    const int MAXN = 1 + 100000;
    vector<int> g[MAXN], rg[MAXN], scc[MAXN]; // scc to nodes
    stack<int> ts;
    int my_scc[MAXN], sccno; // node to scc, sccno = # of scc
    bool vis[MAXN];
    void dfs(int u, bool revg) {
        vis[u] = true;
        if(revg)
            scc[sccno].push_back(u), my_scc[u] = sccno;
        for(int v: (revg ? rg : g)[u])
            if(!vis[v]) dfs(v,revg);
        if(!revg) ts.push(u);
    }
    void build(int n) {
        fill(vis, vis + n, false);
        foi(u,0,n) {
            if(!vis[u]) dfs(u,false);
            for(int v: g[u])
                rg[v].push_back(u);
        }
        fill(vis, vis + n, false); sccno = 0;
        while(!ts.empty()) {
            int u = ts.top(); ts.pop();
            if(!vis[u]) dfs(u,true), sccno++;
        }
    }}
