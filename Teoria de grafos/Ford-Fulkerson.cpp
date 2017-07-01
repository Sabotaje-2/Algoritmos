vector<vector<int> > g;
int f[MAX_NODES][MAX_NODES], p[MAX_NODES], bottleneck;
bitset<MAX_NODES> visited;
// reiniciar el flujo(f) a 0 en cada caso
bool dfs(int u, const int t) {
    visited[u] = true;
    if(u == t) return true;
    foi(i,0,g[u].size()) {
        int v = g[u][i];
        if(!visited[v] && f[u][v] > 0) {
            p[v] = u;
            if(dfs(v, t)) return true;
        }
    }
    return false;
}

void path(int v) {
    int u = p[v];
    if(~u) {
        bottleneck = min(bottleneck, f[u][v]);
        path(u);
        f[u][v] -= bottleneck;
        f[v][u] += bottleneck;
    }
}

int max_flow(int s, int t) {
    int flow = 0;
    for(;;) {
        visited.reset();
        p[s] = -1;
        if(!dfs(s, t)) return flow;
        bottleneck = INF;
        path(t);
        flow += bottleneck;
    }
}
