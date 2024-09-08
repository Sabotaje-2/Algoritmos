// Codeforces GYM 102028H.
namespace sa {
struct sfx {int idx, pos, posadd;};
sfx v[MAXN];
int arr[MAXLOG][MAXN], lk = 0;
void build(const vector<int>& a, int n) {
  for (int i = 0; i < n; ++i) arr[0][i] = a[i];
  for (int k = 1; (1 << (k-1)) <= n; lk = k++) {
    for (int i = 0; i < n; ++i) {
      int add = i + (1 << (k-1));
      v[i] = sfx{i, arr[k-1][i], add < n ? arr[k-1][add] : -1};
    }
    sort(v, v+n, [](const sfx& p, const sfx& q)->bool{
      return p.pos == q.pos ? p.posadd < q.posadd : p.pos < q.pos;
    });
    for (int i = 0; i < n; ++i) {
      arr[k][v[i].idx] = i;
      if (i > 0 && v[i].pos == v[i-1].pos && v[i].posadd == v[i-1].posadd)
        arr[k][v[i].idx] = arr[k][v[i-1].idx];
    }
  }
}};
