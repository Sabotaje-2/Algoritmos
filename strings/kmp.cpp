// SPOJ NHAY.
vector<int> pf(const string& s) {
  vector<int> pi(s.size(), 0);
  for (int i = 1, j = 0; i < (int)s.size(); ++i) {
    while (j > 0 && s[i] != s[j]) j = pi[j-1];
    if (s[i] == s[j]) ++j;
    pi[i] = j;
  }
  return pi;
}
