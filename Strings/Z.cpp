void z(const string& s) {
    vector<int> z(s.size());
    for(int i = 1, L = 0, R = 0, k; i < (int)s.size(); ++i)
        if(i <= R) {
            k = i - L;
            if(i + z[k] - 1 < R) z[i] = z[k];
            else {
                L = i;
                while(R < (int)s.size() && s[R] == s[R-L])++R;
                z[i] = R - L; --R;
            }
        } else {
            L = R = i;
            while(R < (int)s.size() && s[R] == s[R-L])++R;
            z[i] = R - L; --R;
        }
}
