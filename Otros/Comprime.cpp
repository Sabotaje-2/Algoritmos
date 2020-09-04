namespace comp {
int v[MAXN], sz;
void compress(int arr[], int n, int BEG = 0) {
  copy(arr, arr+n, v); sort(v, v+n);
  sz = unique(v, v+n) - v;
  for (int i = 0; i < n; ++i) {
    arr[i] = BEG + lower_bound(v, v+sz, arr[i]) - v;
  }
}}
