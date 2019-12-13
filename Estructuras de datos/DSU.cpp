namespace dsu {
const int MAXN = 500*500;
int f[MAXN], sz[MAXN];
void build(int n) {
  fill(sz, sz + n, 1);
  foi (i,0,n) f[i] = i;
}
int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
void join(int x, int y) {
  int p = find(x), q = find(y);
  if (p == q) return;
  if (sz[q] > sz[p]) swap(p, q);
  sz[p] += sz[q];
  f[q] = p;
}
bool connected(int i, int j) {return find(i) == find(j);}}
