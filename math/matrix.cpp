struct Matrix {
  int m[MAXN][MAXN], r, c;

  Matrix(int _r, int _c, int x) : r{_r}, c{_c} {
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        m[i][j] = x;
  }

  Matrix operator*(const Matrix& o) const {
    Matrix ans(r, o.c, 0);
    for (int i = 0; i < ans.r; ++i)
      for (int j = 0; j < ans.c; ++j)
        for (int k = 0; k < o.r; ++k)
          ans.m[i][j] = (ans.m[i][j] + (1LL*m[i][k]*o.m[k][j])) % MOD;
    return ans;
  }

  Matrix fpow(int64 e) const {
    assert(r == c);
    Matrix ans(r,r,0), p(*this);
    for (int i = 0; i < r; ++i) ans.m[i][i] = 1;
    for (; e; e >>= 1, p = p*p) {
      if (e&1) ans = ans*p;
    }
    return ans;
  }
};
