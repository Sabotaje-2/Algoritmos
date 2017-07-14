int p[MAX_NODOS], f[MAX_NODOS][MAX_NODOS], mine;
// reiniciar el flujo(f) a 0 en cada caso
bitset<MAX_NODOS> visited;
vector<vector<int>> g;
bool bfs(const int s, const int t) {
    queue<int> q;
    int u;
    p[s] = -1;
    visited.reset();
    visited[s] = true;
    q.push(s);
    while(q.size()) {
        u = q.front();q.pop();
        for(const auto& v: g[u])
          if(!visited[v] && f[u][v] > 0) {
            q.push(v), p[v] = u, visited[v] = true;
            if(v == t) return true;
          }
    }
    return false;
}
void path(int v) {
    int u = p[v];
    if(~u) {
        mine = min(mine, f[u][v]);
        path(u);
        f[u][v] -= mine;
        f[v][u] += mine;
    }
}
int max_flow(const int s, const int t) {
    int flow = 0;
    while(bfs(s, t)) {
        mine = LONG_MAX;
        path(t);
        flow += mine;
    }
    return flow;
}
