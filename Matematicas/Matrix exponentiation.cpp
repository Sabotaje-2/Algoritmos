const int MAXR = 3;
const int MAXC = 3;
const int MOD = 1e9 + 7;
struct matrix {
    int m[MAXR][MAXC];
    int r,c;
    matrix(const matrix& o) {
        r = o.r; c = o.c;
        assert(r <= MAXR && c <= MAXC);
        foi(i,0,r) foi(j,0,c) m[i][j] = o.m[i][j];
    }
    matrix(int _r, int _c, int def) {
        r = _r; c = _c;
        assert(r <= MAXR && c <= MAXC);
        foi(i,0,r) foi(j,0,c) m[i][j] = def;
    }
    matrix(vector<vector<int>> v) {
        r = v.size(); c = v[0].size();
        assert(r <= MAXR && c <= MAXC);
        foi(i,0,r) foi(j,0,c) m[i][j] = v[i][j];
    }
    matrix operator*(const matrix& o) const {
        matrix ans(r, o.c, 0);
        foi(i,0,ans.r)foi(j,0,ans.c)foi(k,0,o.r)
            ans.m[i][j] = (ans.m[i][j] + ((1LL * m[i][k] * o.m[k][j]) % MOD)) % MOD;
        return ans;
    }
    matrix fpow(ll exp) {
        assert(r == c);
        matrix ans(r,r,0), power(*this);
        foi(i,0,r) ans.m[i][i] = 1;
        while(exp) {
            if(exp & 1)
                ans = ans * power;
            power = power * power;
            exp >>= 1;
        }
        return ans;
    }
    friend ostream& operator << (ostream& s, matrix m) {
        foi(i,0,m.r) {
            foi(j,0,m.c)
                s << m.m[i][j] << ' ';
            s << endl;
        }
        return s;
    }};
