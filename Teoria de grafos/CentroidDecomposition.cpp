// PROBAR
namespace cd {
int sz[MAXN];
bool done[MAXN];
vector<ii> t[MAXN]; // {v,costo}.
void calcsz(int u, int p) {
  sz[u] = 1;
  for (auto x : t[u]) {
    int v = x.first;
    if (v == p) continue;
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
  for (auto x : t[u]) {
    int v = x.first;
    if (v == p || done[v]) continue;
    if (sz[v] > (sz[u] >> 1)) {
      sz[u] -= sz[v];
      sz[v] += sz[u];
      fc(v,u);
      return;
    }
  }
  solve(u); // Se procesan todos los caminos que pasan por este centroide
  for (auto x : t[u]) {
    int v = x.first;
    if (!done[v]) fc(v,u);
  }
}}
