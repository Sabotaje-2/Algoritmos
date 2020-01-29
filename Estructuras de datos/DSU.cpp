// UVa 10583.
namespace dsu {
int f[MAXN], sz[MAXN];
void build(int n) {
  fill(sz, sz + n, 1);
  foi (i,0,n) f[i] = i;
}
int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
bool join(int x, int y) {
  if ((x = find(x)) == (y = find(y))) return false;
  if (sz[x] < sz[y]) swap(x, y);
  sz[x] += sz[y];
  f[y] = x;
  return true;
}
bool connected(int i, int j) {return find(i) == find(j);}}
