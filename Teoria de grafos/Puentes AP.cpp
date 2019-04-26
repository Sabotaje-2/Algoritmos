// Puntos de articulacion y puentes en O(E)
namespace APB {
    int c[MAXN], tim, d[MAXN], dlow[MAXN];
    bitset<MAXN> ap; // ap[u] = es u AP?
    int DROOT;
    int dfs(int u, int p = -1) {
        c[u] = 0;
        d[u] = dlow[u] = ++tim;
        int vis = 0;
        for(const int& v : g[u]) {
            if(v == p || c[v] == 1) continue;
            if(c[v] == -1) {
                dlow[u] = min(dlow[u], dfs(v,u));
                if(dlow[v] > d[u]) { // Puente (u,v)
                }
                if(dlow[v] >= d[u]) { // u es AP
                    ap[u] = true;
                }
                vis++;
            } else {
                dlow[u] = min(dlow[u], d[v]);
            }
        }
        if(u == DROOT) { // Solo para AP
            ap[u] = (vis >= 2);
        }
        c[u] = 1;
        return dlow[u];
    }
    void init(int n) { // n = numero de nodos
        tim = 0;
        fill(c, c + n, -1);
        ap.reset(); // Solo para AP
        foi(i,0,n) {
            if(c[i] == -1) {
                DROOT = i; // Solo para AP
                dfs(i);
            }
        }
    }
}
