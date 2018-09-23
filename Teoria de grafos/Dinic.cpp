int dist[MAXN], flow[MAXE], to[MAXN][MAXN], max_e; /* set to 0 */
vector<int> g[MAXN];
bool bfs(int s, int t) {
    memset(dist, -1, sizeof dist);

    queue<int> q;
    q.push(s); dist[s] = 0;
    while(q.size()) {
        int u = q.front();q.pop();
        for(const int& v: g[u]) {
            if(dist[v] == -1 && flow[to[u][v]] > 0) {
                q.push(v);
                dist[v] = 1 + dist[u];
                if(v == t) return true;
            }
        }
    }
    return false;
}
int dfs(int u, int mine, int t) {
    if(u == t) return mine;
    int tot = 0, fs;
    for(const int& v: g[u]) {
        if(dist[v] == 1 + dist[u] && flow[to[u][v]] > 0 && (fs = dfs(v, min(mine, flow[to[u][v]]), t))) {
            mine -= fs;
            flow[to[u][v]] -= fs;
            flow[to[v][u]] += fs;
            tot += fs;
        }
        if(mine == 0) break;
    }
    return tot;
}
int max_flow(int s, int t, int ans = 0) {
    while(bfs(s,t)) ans += dfs(s,numeric_limits<int>::max(),t);
    return ans;
}
void add_edge(int u, int v, int fadd) { // cambiar a matriz de ady cuando hayan aristas repetidas
    g[u].push_back(v); g[v].push_back(u);
    to[u][v] = max_e++; to[v][u] = max_e++;
    flow[to[u][v]] = fadd; flow[to[v][u]] = 0;
}
