// LCA para responder queries en O(1).
// Se construye en O(nlgn).
// Kattis Tourists.
namespace fastlca {
int eu[2*MAXN], p[MAXN], h[MAXN], fo[MAXN], ez;
int pl[2*MAXN], st[2*MAXN][MAXLG];
vector<int> t[MAXN];
void dfs(int u, int lvl) {
  fo[u] = ez;
  h[u] = lvl;
  eu[ez++] = u;
  for (int v: t[u]) {
    if (p[u] == v) continue;
    p[v] = u;
    dfs(v, 1 + lvl);
    eu[ez++] = u;
  }
}
void buildst() {
  foi (i,0,ez) st[i][0] = eu[i];
  foi (j,1,MAXLG)
    for (int i = 0; i + (1 << j) <= ez; ++i) {
      st[i][j] = st[i][j - 1];
      if (h[st[i + (1 << (j - 1))][j-1]] < h[st[i][j]])
        st[i][j] = st[i + (1 << (j - 1))][j-1];
    }
}
void build() {
  dfs(ez = 0, 1);
  buildst();
}
int stquery(int i, int j) {
  if (i > j) swap(i, j);
  int k = pl[1 + j - i], ans = st[i][k];
  if (h[st[1 + j - (1 << k)][k]] < h[ans])
    ans = st[1 + j - (1 << k)][k];
  return ans;
}
// Solo se llama una vez en todo el programa!
void buildpot() {
  for (int i = 1, pot = 0; i < 2*MAXN; ++i)
    if ((1 << pot) == i) pl[i] = pot++;
    else pl[i] = pl[i - 1];
}
int query(int u, int v) {
  return stquery(fo[u], fo[v]);
}}
