using Tedge = int; // Costo de las aristas
namespace lca {
    // build O(Vlog(V)), query O(log(V))
    const int MAXN = 1+1000*1000; // Max No. Nodos
    const int MAXLG = 21; // 2^(MAXLG-1) > MAXN
    vector<pair<Tedge,int>> t[MAXN]; // u->{costo,v}
    int f[MAXLG][MAXN], lv[MAXN];
    Tedge pw[MAXLG][MAXN];
    void dfs(int u, int lvl) {
        lv[u] = lvl;
        for(auto p : t[u]) {
            int v; Tedge c; tie(c,v) = p;
            if(f[0][u] != v) {
                f[0][v] = u, pw[0][v] = c;
                dfs(v, 1 + lvl);
            }
        }
    }
    void build(int n, int r) { // |V|, nodo raiz
        f[0][r] = r; pw[0][r] = numeric_limits<Tedge>::min();
        dfs(r,0);
        foi(i,1,MAXLG) foi(u,0,n)
            f[i][u] = f[i - 1][f[i - 1][u]],
            pw[i][u] = max(pw[i - 1][u], pw[i - 1][f[i - 1][u]]);
    }
    pair<int,Tedge> query(int u, int v) { // {lca(u,v),max_edge(u,v)}
        if(u == v) assert(false); // definir el max_edge de u a u
        if(lv[u] < lv[v]) swap(u,v);
        Tedge medge = numeric_limits<Tedge>::min();
        for(int i = MAXLG - 1; i >= 0; --i)
            if(lv[f[i][u]] >= lv[v]) {
                medge = max(medge, pw[i][u]);
                u = f[i][u];
            }
        if(u == v) return {u,medge};
        for(int i = MAXLG - 1; i >= 0; --i)
            if(f[i][u] != f[i][v]) {
                medge = max({medge, pw[i][u], pw[i][v]});
                u = f[i][u], v = f[i][v];
            }
        return {f[0][u], max({medge, pw[0][u], pw[0][v]})};
    }}
