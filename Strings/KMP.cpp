vector<int> prefix_function(string& s) {
    vector<int> b(1 + s.size());
    int j;
    b[0] = b[1] = 0;
    for(int i = 2; i <= (int)s.size(); ++i) {
        j = b[i - 1];
        for(;;) {
            if(s[j] == s[i - 1]) {
                b[i] = 1 + j;
                break;
            }
            if(!j) {
                b[i] = 0;
                break;
            }
            j = b[j];
        }
    }
    return b;
}
int kmp(string& t, string& p, vector<int> b) {
    int i = 0, j = 0, ans = 0;
    for(;;) {
        if(i >= (int)t.size()) break;
        if(t[i] != p[j]) {
            if(!j) ++i;
            else j = b[j];
        } else
            ++i,++j;
        if(j == (int)p.size()) {
            ++ans; // match at t[i - p.size()]
            j = b[j];
        }
    }
    return ans;
}