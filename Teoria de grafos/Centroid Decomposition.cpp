const int MAXN = 5 + 200000;
int sz[MAXN];
bool done[MAXN];
vector<pair<int,int>> t[MAXN]; // {v,costo}
void calcsz(int u, int p = -1) {
    sz[u] = 1;
    foi(i,0,t[u].size()) {
        int v = t[u][i].first;
        if(v == p) continue;
        calcsz(v,u);
        sz[u] += sz[v];
    }
}
void solve(int u) {
    // Se procesan todos los caminos que pasan por el centroide u
    // IMPORTANTE marcar el centroide para que sea O(NlgN)
    done[u] = true;
}
void fc(int u, int p) {
    foi(i,0,t[u].size()) {
        int v = t[u][i].first;
        if(v == p || done[v]) continue;
        if(sz[v] > (sz[u] >> 1)) {
            sz[u] -= sz[v];
            sz[v] += sz[u];
            fc(v,u);
            return;
        }
    }
    solve(u); // Se procesan todos los caminos que pasan por este centroide
    foi(i,0,t[u].size()) {
        int v = t[u][i].first;
        if(!done[v])
            fc(v,u);
    }
}
