// Codeforces 1295E.
namespace stree {
#define m ((s+e)/2)
ll t[4*MAXN], lazy[4*MAXN];
void prop(int p, int s, int e) {
  t[p] += lazy[p];
  if (s < e) lazy[2*p] += lazy[p], lazy[1+2*p] += lazy[p];
  lazy[p] = 0;
}
ll query(int s, int e, int p, int l, int r) {
  prop(p,s,e);
  if (l > r) return 1LL<<60; // Elemento neutro.
  if (s == l && e == r) return t[p];
  return min(query(s, m, 2*p, l, min(m,r)),
             query(1+m, e, 1+2*p, max(1+m,l), r));
}
void update(int s, int e, int p, int l, int r, ll add) {
  prop(p,s,e);
  if (l > r) return;
  if (s == l && e == r) {
    lazy[p] += add;
    prop(p,s,e);
  } else {
    update(s, m, 2*p, l, min(m,r), add);
    update(1+m, e, 1+2*p, max(1+m,l), r, add);
    t[p] = min(t[2*p], t[1+2*p]);
  }
}}
