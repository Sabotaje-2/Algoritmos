vector<int> pf(const string& s) {
    vector<int> pi(s.size()); pi[0] = 0; // pi[i] = longitud del PROPER suffix mas largo que termina en i, y que ademas es un prefix
    foi(i,1,s.size()) {
        int j = pi[i - 1];
        while(j && s[i] != s[j]) j = pi[j - 1];
        pi[i] = j + (s[i] == s[j]);
    }
    return pi;
}
void kmp(const string& t, const string& p) {
    vector<int> pi = pf(p + "$" + t);
    foi(i,2*p.size(),pi.size())
        if(pi[i] == (int)p.size())
            cout << "Match en " << i - 2*p.size() << endl;
}
