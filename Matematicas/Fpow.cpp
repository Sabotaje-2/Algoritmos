// UVa 374.
int fpow(int b, int e) {
  int ans = 1, p = b;
  for (; e; e >>= 1) {
    if(e & 1) ans = mul(ans, p);
    p = mul(p, p);
  }
  return ans;
}
