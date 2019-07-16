namespace lca {
    // build O(Vlog(V)), query O(log(V))
    using T = int; // Costo de las aristas
    const int MAXN = 1+1000*1000; // Max No. Nodos
    const int MLG = 21; // 2^(MLG-1) > MAXN
    vector<pair<T,int>> t[MAXN]; // u->{costo,v}
    int f[MLG][MAXN], l[MAXN];
    T pw[MLG][MAXN];
    void dfs(int u, int lu) {
        l[u] = lu;
        for(auto p : t[u]) {
            int v; T c; tie(c,v) = p;
            if(f[0][u] != v) {
                f[0][v] = u, pw[0][v] = c;
                dfs(v, 1 + lu);
            }
        }
    }
    void build(int n, int r) { // |V|, nodo raiz
        f[0][r] = r; pw[0][r] = numeric_limits<T>::min();
        dfs(r,0);
        foi(i,1,MLG) foi(u,0,n)
            f[i][u] = f[i - 1][f[i - 1][u]],
            pw[i][u] = max(pw[i - 1][u], pw[i - 1][f[i - 1][u]]);
    }
    pair<int,T> query(int u, int v) { // {lca(u,v),max_edge(u,v)}
        if(u == v) assert(false); // definir el max_edge de u a u
        if(l[u] < l[v]) swap(u,v);
        T me = numeric_limits<T>::min();
        for(int i = MLG - 1; i >= 0; --i)
            if(l[f[i][u]] >= l[v]) {
                me = max(me, pw[i][u]);
                u = f[i][u];
            }
        if(u == v) return {u,me};
        for(int i = MLG - 1; i >= 0; --i)
            if(f[i][u] != f[i][v]) {
                me = max({me, pw[i][u], pw[i][v]});
                u = f[i][u], v = f[i][v];
            }
        return {f[0][u], max({me, pw[0][u], pw[0][v]})};
    }}
