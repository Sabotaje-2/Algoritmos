vector < vector < ii > > g; // v, cost
bool relax(int u, vector < int >& dist) {
    bool relaxed = false;
    int v, cost;
    foi(i,0,g[u].size()) {
        v = g[u][i].first;
        cost = g[u][i].second;
        if(dist[u] + cost < dist[v])
            dist[v] = cost + dist[u], relaxed = true;
    }
    return relaxed;
}
bool bellman_ford(int source) {// true = ciclo negativo
    vector < int > dist(g.size(), INF);
    dist[source] = 0;
    foi(i,0,g.size() - 1) // iterar sobre las aristas V - 1 veces
        foi(u,0,g.size()) {
            if(dist[u] == INF)  continue;
            relax(u, dist);
        }
    foi(u,0,g.size()) {
        if(dist[u] == INF)  continue;
        if(relax(u, dist))  return true;
    }
    return false;
}
