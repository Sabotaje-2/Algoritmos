// UVa 374.
int fpow(int b, int e) {
  int ans = 1;
  for (; e; e >>= 1) {
    if (e&1) ans = mul(ans, b);
    b = mul(b, b);
  }
  return ans;
}
