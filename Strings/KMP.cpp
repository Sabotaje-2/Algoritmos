// SPOJ NHAY.
vector<int> pf(const string& s) {
  // pi[i] = longitud del PROPER suffix mas largo que termina en i, y que ademas es un prefix.
  vector<int> pi(s.size(), 0);
  for (int i = 1, j = 0; i < (int)s.size(); ++i) {
    while (j > 0 && s[i] != s[j]) j = pi[j-1];
    if (s[i] == s[j]) ++j;
    pi[i] = j;
  }
  return pi;
}
void kmp(const string& t, const string& p) {
  vector<int> pi = pf(p+"$"+t);
  for (int i = 2*(int)p.size(); i < (int)pi.size(); ++i) {
    if (pi[i] == (int)p.size())
      cout << "Match en " << i - 2*p.size() << endl;
  }
}
