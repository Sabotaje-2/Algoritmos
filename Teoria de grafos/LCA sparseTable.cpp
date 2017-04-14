vector < vector < int > > tree;
vector < int > ocurrences;
int p[MAX_N]; // El padre inmediato de cada nodo
int h[MAX_N]; // La altura de cada nodo, MAX_N = Maximo numero de nodos
int fo[MAX_N]; // Indice de la primer ocurrencia de cada nodo en ocurrences

void dfs(int u , int alt = 0) {
    int v;
    fo[u] = ocurrences.size();
    h[u] = alt;
    ocurrences.push_back(u);
    foi(i,0,tree[u].size()) {
        v = tree[u][i];
        if(p[u] == v)    continue;
        p[v] = u;
        dfs(v, 1 + alt);
        ocurrences.push_back(u);
    }
}

struct st {
    vector < vector < int > > table;
    st(vector < int >& arr) {
        int columns = 1 + floor(log2(arr.size()));// C++11
        table.assign(arr.size() , vector < int >(columns , -2));
        foi(i,0,arr.size()) table[i][0] = arr[i];
        for(int j = 1 ; j < columns ; ++j)
            for(int i = 0 ; i + (1 << j) - 1 < (int)arr.size() ; ++i) {
                table[i][j] = table[i][j-1];
                if(h[table[i + (1 << (j - 1))][j-1]] < h[table[i][j]])
                    table[i][j] = table[i + (1 << (j - 1))][j-1];
            }
    }
    int query(int i, int j) {
        if(i > j) swap(i, j);
        int len = j - i + 1, k = floor(log2(len));
        int ans = table[i][k];
        if(h[table[i + len - (1 << k)][k]] < h[ans])
            ans = table[i + len - (1 << k)][k];
        return ans;
    }
    int lca(int u, int v) {
        return query(fo[u], fo[v]);
    }};
