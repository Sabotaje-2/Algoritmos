struct suffarr {
    struct D {
        int idx, pos, posadd;
        bool operator<(const D& o) const {
            if(pos == o.pos) return posadd < o.posadd;
             return pos < o.pos;
        }};
    int len,lk;
    vector<int> sa, arr[MAXLOG];
    vector<D> v;
    suffarr() : v(MAXN), sa(MAXN) {
        foi(i,0,MAXLOG) arr[i].resize(MAXN);
    }
    void build(string s, int NL = -1) { //O(nlg^2n)
        int add; len = s.size();
        foi(i,0,len) arr[0][i] = s[i];
        for(int k = 1; (1 << k) <= len; ++k) {
            foi(i,0,len) {
                add = i + (1 << (k - 1));
                v[i].idx = i;
                v[i].pos = arr[k - 1][i];
                v[i].posadd = (add < len ? arr[k - 1][add] : NL);
            }
            sort(v.begin(), v.begin() + len);
            foi(i,0,len) arr[k][v[i].idx] = (i && v[i].pos == v[i - 1].pos && v[i].posadd == v[i - 1].posadd ? arr[k][v[i - 1].idx] : i);
            lk = k;
        }
        foi(i,0,len) sa[arr[lk][i]] = i;
    }
    int lcp(int i, int j) {
        int ans = 0;
        for(int k = lk; ~k && i < len && j < len; --k)
            if(arr[k][i] == arr[k][j])
                ans += (1 << k), i += (1 << k), j += (1 << k);
        return ans;
    }
    string lcs(const string& f, const string& s) {
        int x,y,maxi=0,start; string ans;
        build(f + "$" + s);
        foi(i,1,len) {
            x = sa[i - 1]; y = sa[i];
            if(x > y) swap(x,y);
            if(x < (int)f.size() && y >= 1 + (int)f.size() && lcp(x,y) > maxi) {
                maxi = lcp(x,y);
                start = x;
            }
        }
        foi(i,0,maxi) ans += f[start + i];
        return ans;
    }};
