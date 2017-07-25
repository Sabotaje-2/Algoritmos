struct kosaraju {
    vector<vector<int>> revg, scc; // scc to nodes
    vector<int> my_scc; // node to scc
    stack<int> topo;
    vector<bool> visited;
    kosaraju(vector<vector<int>>& g) {
        my_scc.resize(g.size());
        visited.assign(g.size(), false);
        revg.assign(g.size(), vector<int>());
        foi(u,0,g.size()) {
            if(!visited[u]) dfs(u,g);
            for(const auto& v: g[u])
                revg[v].push_back(u);
        }
        visited.assign(g.size(), false);
        scc.reserve(g.size());
        while(topo.size()) {
            int u = topo.top();topo.pop();
            if(!visited[u]) {
                scc.push_back(vector<int>());
                dfs2(u, revg);
            }
        }
    }
    void dfs(int u, vector<vector<int>>& g) {
        visited[u] = true;
        for(const auto& v: g[u])
            if(!visited[v]) dfs(v,g);
        topo.push(u);
    }
    void dfs2(int u, vector<vector<int>>& g) {
        visited[u] = true;
        scc[scc.size() - 1].push_back(u);
        my_scc[u] = scc.size() - 1;
        for(const auto& v: g[u])
            if(!visited[v]) dfs2(v,g);
    }};
