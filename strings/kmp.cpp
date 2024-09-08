// SPOJ NHAY.
vector<int> pf(const string& s) {
  vector<int> pi(s.size(), 0);
  for (int i = 1, j = 0; i < (int)s.size(); ++i) {
    for (; j > 0 && s[i] != s[j]; j = pi[j-1]);
    j += (s[i] == s[j]);
    pi[i] = j;
  }
  return pi;
}
