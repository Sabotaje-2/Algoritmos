// Sparse Table para min, max, gcd (0-BASED).
// Para calcular sumas modificar querymin() y build().
// PROBAR?
namespace spt {
int pl[MAXN];
ll st[MAXN][MAXLG];
void buildpot() { // BUG: Nunca se invoca buildpot().
  for (int i = 1, pot = 0; i < MAXN; ++i)
    if ((1 << pot) == i) pl[i] = pot++;
    else pl[i] = pl[i - 1];
}
void build(ll arr[], int n) {
  foi (i,0,n) st[i][0] = arr[i];
  for (int len = 1; (1 << len) <= n; ++len)
    for (int i = 0; i + (1 << len) <= n; ++i)
      st[i][len] = min(st[i][len - 1], st[i + (1 << (len - 1))][len - 1]);
}
ll querymin(int l, int r) {
  int pot = pl[1 + r - l];
  return min(st[l][pot], st[1 + r - (1 << pot)][pot]);
}}
