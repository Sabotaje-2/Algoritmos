namespace spt {
const int MAXN = 5 + 100000;
const int MAXLOG = 18;
int pl[MAXN];
ll st[MAXN][MAXLOG];
void buildpot() { // Solo se llama una vez en todo el programa!
  int pot = 0;
  for (int i = 1; i < MAXN; ++i)
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
