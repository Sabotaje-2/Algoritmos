// BIT para updates y queries en rangos (1-BASED).
// Para updates -> update(l, r, x) (l <= r).
// Para consultas -> query(r) - query(l - 1).
// Para llenar todo de ceros -> reset().
// SPOJ HORRIBLE.
namespace bit {
int n = -1; // BUG: n sin asignar.
ll b1[MAXN], b2[MAXN];
void add(int p, ll x1, ll x2) {
  for (; p <= n; p += p&-p) b1[p] += x1, b2[p] += x2;
}
ll get(ll b[], int p) {
  ll s = 0LL;
  for (; p; p -= p&-p) s += b[p];
  return s;
}
void reset() {
  for (int i = 1; i <= n; ++i) b1[i] = b2[i] = 0;
}
void update(int l, int r, int x) {
  add(l, x, -1LL*x*(l-1));
  add(1+r, -x, 1LL*x*r);
}
ll query(int x) {return get(b1,x)*x + get(b2,x);}}
