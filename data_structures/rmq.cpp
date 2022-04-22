// Codeforces 1295E.
namespace rmq {
  #define mi ((s+e)/2)
  int64 t[4*MAXN], lazy[4*MAXN];

  void prop(int p, int s, int e) {
    t[p] += lazy[p];
    if (s < e) lazy[2*p] += lazy[p], lazy[1+2*p] += lazy[p];
    lazy[p] = 0;
  }

  int64 query(int p, int s, int e, int l, int r) {
    prop(p,s,e);
    if (l > r) return 1LL<<60; // Elemento neutro.
    if (s == l && e == r) return t[p];
    return min(query(2*p, s, mi, l, min(mi,r)),
               query(1+2*p, 1+mi, e, max(1+mi,l), r));
  }
  
  void update(int p, int s, int e, int l, int r, int64 x) {
    prop(p,s,e);
    if (l > r) return;
    if (s == l && e == r) {
      lazy[p] += x;
      prop(p,s,e);
    } else {
      update(2*p, s, mi, l, min(mi,r), x);
      update(1+2*p, 1+mi, e, max(1+mi,l), r, x);
      t[p] = min(t[2*p], t[1+2*p]);
    }
  }
}
