struct suffix_array {
    vector<vector<int> > mat;
    vector<int> order, suffix;
    int lastk, sz;
    struct data {
        int idx, tie, last;
        bool operator < (const data& o) const {
            if(this-> last == o.last)
                return this->tie < o.tie;
            return this->last < o.last;
        }
    };
    vector<data> temp;
    suffix_array(const string& s) { // O(nlg^2(n))
        temp.resize(sz = s.size());
        order.resize(s.size());
        suffix.resize(s.size());
        mat.assign(2 + floor(log2(s.size())), vector<int>(s.size()));
        foi(i,0,s.size())
            mat[0][i] = s[i];
        for(int k = 1, len = 1; len < (int)s.size(); ++k, len <<= 1) {
            foi(i,0,s.size()) {
                temp[i].last = mat[k - 1][i];
                temp[i].idx = i;
                temp[i].tie = i + len < (int)s.size() ? mat[k - 1][i + len] : -1;
            }
            sort(temp.begin(), temp.end());
            foi(i,0,s.size()) {
                suffix[i] = mat[k][temp[i].idx] = i && temp[i].tie == temp[i - 1].tie && temp[i].last == temp[i - 1].last ? mat[k][temp[i - 1].idx] : i;
                order[i] = temp[i].idx;
            }
            lastk = k;
        }
    }
    int lcp(int x, int y) {
        int ans = 0;
        if(x == y) return sz - x;
        for(int k = lastk - 1; k >= 0 && x < sz && y < sz; --k)
            if(mat[k][x] == mat[k][y])
                x += (1 << k), y += (1 << k), ans += (1 << k);
        return ans;
    }};
