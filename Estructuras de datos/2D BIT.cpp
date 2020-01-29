// BIT 2D para updates y queries en puntos de una matriz (1-BASED).
// Para updates (sumar x a un punto (r, c)) -> update(r, c, x).
// Para consultas -> query(x1,y1,x2,y2) (x1 <= x2, y1 <= y2).
// (x1,y1) = esquina superior izquierda.
// (x2,y2) = esquina inferior derecha.
// SPOJ MATSUM.
namespace bit2d {
int n = -1; // BUG: n sin asignar.
ll bit[MAXN][MAXN];
void upd(int x, int y, ll val) {
  for (; x <= n; x += (x & -x))
    for (int y1 = y; y1 <= n; y1 += (y1 & -y1))
      bit[x][y1] += val;
}
ll query(int x, int y) {
  ll ans = 0LL;
  for (; x; x -= (x & -x))
    for (int y1 = y; y1; y1 -= (y1 & -y1))
      ans += bit[x][y1];
  return ans;
}
ll query(int x1, int y1, int x2, int y2) {
  return query(x2, y2) - query(x2, y1 - 1) -
  query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}}
