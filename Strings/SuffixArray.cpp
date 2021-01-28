// Codeforces GYM 102028H.
namespace suff {
struct D {int idx, pos, posadd;};
D v[MAXN];
int sa[MAXN], arr[MAXLOG][MAXN], len, lk;
void init(const string& a, int n, int NL = -1) {
  for (int i = 0; i < (len = n); ++i) arr[0][i] = a[i];
  // TO DO: Arreglar el limite del ciclo y probar en lcp cuando x=y.
  for (int k = 1; (1 << (k-1)) <= len; ++k) {
    for (int i = 0; i < len; ++i) {
      int add = i + (1 << (k-1));
      v[i] = D{i, arr[k-1][i], add < len ? arr[k-1][add] : NL};
    }
    sort(v, v+len, [](const D& p, const D& q)->bool{
      return p.pos == q.pos ? p.posadd < q.posadd : p.pos < q.pos;
    });
    for (int i = 0; i < len; ++i) {
      arr[k][v[i].idx] = i;
      if (i > 0 && v[i].pos == v[i-1].pos && v[i].posadd == v[i-1].posadd)
        arr[k][v[i].idx] = arr[k][v[i-1].idx];
    }
    lk = k;
  }
  for (int i = 0; i < len; ++i) sa[arr[lk][i]] = i;
}}
