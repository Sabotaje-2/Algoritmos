int in[MAX_NODOS]; // hacer memset a 0 antes de leer
vector<vector<int>> g;
vector<int> kahn() {//  O(V + E)
    vector<int> topo;
    queue<int> kahn;
    foi(i,0,g.size()) if(!in[i])  kahn.push(i);
    while(kahn.size()) {
        int u = kahn.front(); kahn.pop();
        topo.push_back(u);
        for(const auto& v: g[u]) if(!--in[v]) kahn.push(v);
    }
    return topo;
}
