const int MAXN = 5 + 100000;
const int MAXLG = 18; // altura del arbol es a lo sumo 2^(MAXLG-1)
vector<int> t[MAXN]; // arbol a descomponer
int w[MAXN]; // peso de los nodos
namespace HLD {
    int l[MAXN], f[MAXN][MAXLG], sz[MAXN];
    void dfs(int u = 0, int dep = 0) {
        l[u] = dep; sz[u] = 1;
        for(const int& v: t[u])
            if(f[u][0] != v) {
                f[v][0] = u;
                dfs(v, 1 + dep);
                sz[u] += sz[v];
            }
    }
    void calclca(int N) {
        f[0][0] = 0; dfs();
        foi(i,1,MAXLG) foi(u,0,N) f[u][i] = f[f[u][i - 1]][i - 1];
    }
    int getlca(int u, int v) {
        if(l[u] < l[v]) swap(u,v);
        for(int i = MAXLG - 1; i >= 0; --i) if(l[f[u][i]] >= l[v]) u = f[u][i];
        if(u == v) return u;
        for(int i = MAXLG - 1; ~i; --i) if(f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
        return f[u][0];
    }
    // Aqui empieza el hld
    // chain[u] = cadena a la cual pertenece u
    // chainhead[u] = nodo mas alto de la u-esima cadena
    // pos[u] = posicion del nodo u en el recorrido
    // 1 + curcha = numero de cadenas
    // hldtour - recorrido
    int chainhead[MAXN], hldtour[MAXN], pos[MAXN], chain[MAXN], curcha, hldsz;
    stree st;
    void calchld(int u = 0) {
        chain[u] = curcha;
        if(chainhead[curcha] == -1)
            chainhead[curcha] = u;
        hldtour[hldsz] = w[u];
        pos[u] = hldsz++;

        int bc = -1;
        for(int& v: t[u]) {
            if(v == f[u][0]) continue;
            if(bc == -1 || sz[v] > sz[bc]) bc = v;
        }
        if(~bc) calchld(bc);
        for(int& v: t[u]) {
            if(v == f[u][0] || v == bc) continue;
            ++curcha;
            calchld(v);
        }
    }
    int climb(int u, int v) { // query de u a v, donde v es un ancestro de u
        int ans = numeric_limits<int>::min();
        while(chain[u] != chain[v]) {
            ans = max(ans, st.query(pos[chainhead[chain[u]]], pos[u]));
            u = f[chainhead[chain[u]]][0];
        }
        return max(ans, st.query(pos[v], pos[u])); // mirar que quede bien en el segtree
    }
    int query(int u, int v) {
        int lcanode = getlca(u,v);
        return max(climb(u, lcanode), climb(v, lcanode));
    }
    void init(int N) {
        foi(i,0,N) chainhead[i] = -1;
        curcha = hldsz = 0;
        calclca(N); calchld();
        st = stree(hldtour,N,[](int a, int b)->int{return max(a,b);});
    }
}
