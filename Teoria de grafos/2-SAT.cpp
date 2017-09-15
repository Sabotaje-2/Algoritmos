struct sat {
    vector<vector<int>> revg, scc, compact; // scc to nodes
    vector<int> my_scc; // node to scc
    stack<int> topo;
    vector<bool> visited;
    sat(vector<vector<int>>& g) {
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
    void process(int block, vector<int>& arr, int n) {
        for(int& x: scc[block])
            if(arr[x - (x >= n ? n : 0)] == -1)
                arr[x - (x >= n ? n : 0)] = (x < n);
    }
    vector<int> solve(vector<vector<int>>& g, int n) {
        vector<int> ans;
        foi(u,0,n)
            if(my_scc[u] == my_scc[u + n])
                return ans; // no solution
        compact.assign(scc.size(), vector<int>());
        visited.assign(scc.size(), false);
        ans.assign(n, -1);
        foi(u,0,g.size())
            for(const auto& v: g[u])
                if(my_scc[u] != my_scc[v])
                    compact[my_scc[u]].push_back(my_scc[v]);
        foi(u,0,compact.size())
            if(!visited[u])
                dfs(u, compact);
        while(topo.size()) {
            process(topo.top(), ans, n);
            topo.pop();
        }
        return ans;
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
