// PROBAR
struct matrix {
int m[MAXR][MAXC], r = MAXR, c = MAXC;
matrix() = default;
matrix(int _r, int _c, int x) : r{_r}, c{_c} {
  foi (i,0,r) foi (j,0,c) m[i][j] = x;
}
matrix(const matrix& o) : r{o.r}, c{o.c} {
  foi (i,0,r) foi (j,0,c) m[i][j] = o.m[i][j];
}
matrix& operator=(const vector<vector<int>>& v) {
  r = (int) v.size(); c = (int) v[0].size();
  foi (i,0,r) foi (j,0,c) m[i][j] = v[i][j];
  return *this;
}
matrix operator*(const matrix& o) const {
  matrix ans(r, o.c, 0);
  foi (i,0,ans.r) foi (j,0,ans.c) foi (k,0,o.r)
    ans.m[i][j] = (ans.m[i][j] + (1LL * m[i][k] * o.m[k][j])) % MOD;
  return ans;
}
matrix fpow(int e) const {
  assert(r == c);
  matrix ans(r,r,0), p(*this);
  foi (i,0,r) ans.m[i][i] = 1;
  for (; e; e >>= 1) {
    if (e & 1) ans = ans * p;
    p = p * p;
  }
  return ans;}};
