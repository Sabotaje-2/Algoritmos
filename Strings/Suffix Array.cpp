// Codeforces GYM 102028H.
namespace suff {
struct D {int idx, pos, posadd;};
D v[MAXN];
int sa[MAXN], len, lk;
vector<int> arr[MAXLOG];
void init(int a[], int n, int NL = -1) {
  len = n;
  for (int i = 0; i < MAXLOG; ++i) arr[i].assign(n, 0);
  for (int i = 0; i < len; ++i) arr[0][i] = a[i];
  for (int k = 1; (1 << (k-1)) < len; ++k) {
    for (int i = 0; i < len; ++i) {
      int add = i + (1 << (k-1));
      v[i].idx = i;
      v[i].pos = arr[k-1][i];
      v[i].posadd = (add < len ? arr[k-1][add] : NL);
    }
    sort(v, v+len, [](const D& p, const D& q)->bool{
      return p.pos == q.pos ? p.posadd < q.posadd : p.pos < q.pos;
    });
    for (int i = 0; i < len; ++i) {
      arr[k][v[i].idx] = i;
      if (i > 0 && v[i].pos == v[i-1].pos && v[i].posadd == v[i-1].posadd) {
        arr[k][v[i].idx] = arr[k][v[i-1].idx];
      }
    }
    lk = k;
  }
  for (int i = 0; i < len; ++i) sa[arr[lk][i]] = i;
}
int lcp(int i, int j) {
  int ans = 0;
  for (int k = lk; ~k && i < len && j < len; --k) {
    if (arr[k][i] == arr[k][j]) {
      ans += (1 << k); i += (1 << k); j += (1 << k);
    }
  }
  return ans;
}}
