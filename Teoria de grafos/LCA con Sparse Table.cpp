struct lca {
    vector<vector<int>> table;
    vector<int> euler,p,h,fo;
    lca(vector<vector<int>>& tree) { // O(nlgn)
        p.resize(tree.size());
        h.resize(tree.size());
        fo.resize(tree.size());
        dfs(tree);
        build(euler);
    }
    void dfs(vector<vector<int>>& tree, int u = 0, int alt = 0) {
        fo[u] = euler.size();
        h[u] = alt;
        euler.push_back(u);
        for(const auto& v: tree[u]) {
            if(p[u] == v)    continue;
            p[v] = u;
            dfs(tree, v, 1 + alt);
            euler.push_back(u);
        }
    }
    void build(vector<int>& arr) {
        int columns = 1 + floor(log2(arr.size()));
        table.assign(arr.size(), vector<int>(columns , -2));
        foi(i,0,arr.size()) table[i][0] = arr[i];
        foi(j,1,columns)
            for(int i = 0; i + (1 << j) - 1 < (int)arr.size(); ++i) {
                table[i][j] = table[i][j-1];
                if(h[table[i + (1 << (j - 1))][j-1]] < h[table[i][j]])
                    table[i][j] = table[i + (1 << (j - 1))][j-1];
            }
    }
    int st_query(int i, int j) {
        if(i > j) swap(i, j);
        int len = j - i + 1, k = floor(log2(len));
        int ans = table[i][k];
        if(h[table[i + len - (1 << k)][k]] < h[ans])
            ans = table[i + len - (1 << k)][k];
        return ans;
    }
    int query(int u, int v) { // O(1)
        return st_query(fo[u], fo[v]);
    }};
