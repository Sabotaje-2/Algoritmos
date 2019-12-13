namespace bit2d {
const int MAXN = 5 + 2000;
ll bit[1 + MAXN][1 + MAXN];
void upd(int x, int y, ll val) { // 1-BASED, al inicio la matriz esta llena de ceros
  for (; x <= MAXN; x += (x & -x)) {
    for (int y1 = y; y1 <= MAXN; y1 += (y1 & -y1))
      bit[x][y1] += val;
  }
}
ll query(int x, int y) {
  ll ans = 0LL;
  for (; x > 0; x -= (x & -x)) {
    for (int y1 = y; y1 > 0; y1 -= (y1 & -y1))
      ans += bit[x][y1];
  }
  return ans;
}
ll query(int x1, int y1, int x2, int y2) {
  // 1-BASED, suma de esquina superior izquierda(x1,y1) hasta esquina inferior derecha(x2,y2)
  return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}}
