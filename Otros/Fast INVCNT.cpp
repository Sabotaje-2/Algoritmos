// SPOJ INVCNT.
namespace INV {
int bit[MAXN], v[MAXN], sz;
void add(int x, int val) {
  for (; x <= sz; x += x&-x) bit[x] += val;
}
int query(int x) {
  int ans = 0;
  for (; x; x -= x&-x) ans += bit[x];
  return ans;
}
ll solve(int arr[], int n) {
  copy(arr, arr + n, v); sort(v, v + n);
  ll ans = 0;
  sz = unique(v, v + n) - v;
  fill(bit + 1, bit + sz + 1, 0); // memset ?
  for (int i = n - 1; i >= 0; --i) {
    int num = 1 + lower_bound(v, v + sz, arr[i]) - v;
    ans += (1LL * query(num - 1));
    add(num, 1);
  }
  return ans;
}}
