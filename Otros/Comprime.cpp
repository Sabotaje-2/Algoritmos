namespace COMP {
int v[MAXN];
// Comprime todos los numeros comenzando desde BEG en O(nlgn).
void compress(int arr[], int n, int BEG = 0) {
  copy(arr, arr + n, v); sort(v, v + n);
  int sz = unique(v, v + n) - v;
  foi (i,0,n) {
    arr[i] = BEG + lower_bound(v, v + sz, arr[i]) - v;
  }}}
