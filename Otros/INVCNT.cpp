// SPOJ INVCNT.
ll inversions(int arr[], int n) {
  ll ans = 0, t = 0; ordered_set s;
  for (int i = n - 1; i >= 0; --i) {
    ans += (1LL * s.order_of_key(ii(arr[i], 0)));
    s.insert(ii(arr[i], t++));
  }
  return ans;
}
