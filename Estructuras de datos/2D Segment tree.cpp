typedef pair<int,int> ii; // max, min
const int MAXNODES = 1023;
const ii NEUTRO = ii(numeric_limits<int>::min(), numeric_limits<int>::max());
#define l ((p << 1) | 1)
#define r (1 + l)
#define m ((s + e) >> 1)
ii op(ii a, ii b) {return ii(max(a.first, b.first), min(a.second, b.second));}
struct st {
    vector<ii> t;
    int sz;
    st(){}
    st(int N) {
        sz = N;
        t.assign(MAXNODES, NEUTRO);
    }
    st(st& st1, st& st2, int tam) {
        sz = tam;
        t.resize(MAXNODES);
        build(0, sz - 1, 0, st1, st2);
    }
    void build(int s, int e, int p, st& st1, st& st2) {
        if(s == e) {
            t[p] = op(st1.query(s,s), st2.query(s,s));
            return;
        }
        build(s, m, l, st1, st2);
        build(1 + m, e, r, st1, st2);
        t[p] = op(t[l], t[r]);
    }
    st(vector<int>& arr) {
        sz = arr.size();
        t.resize(MAXNODES);
        build(0, sz - 1, 0, arr);
    }
    void build(int s, int e, int p, vector<int>& arr) {
        if(s == e) {
            t[p] = {arr[s], arr[s]};
            return;
        }
        build(s, m, l, arr);
        build(1 + m, e, r, arr);
        t[p] = op(t[l], t[r]);
    }
    ii query(int& qs, int& qe, int s, int e, int p) {
        if(s > qe || e < qs) return NEUTRO;
        if(s >= qs && e <= qe)  return t[p];
        return op(query(qs, qe, s, m, l), query(qs, qe, 1 + m, e, r));
    }
    ii query(int i, int j) {
        return query(i, j, 0, sz - 1, 0);
    }
    void set(const int& up, const ii& uv, int s, int e, int p) {
        if(up >= s && up <= e) {
            if(s == e)
                t[p] = uv;
            else {
                set(up, uv, s, m, l);
                set(up, uv, 1 + m, e, r);
                t[p] = op(t[l], t[r]);
            }
        }
    }
    void set(int idx, ii val) {
        set(idx, val, 0, sz - 1, 0);
    }};

struct st2d {
    int N,M;
    vector<st> t;
    st2d(int a, int b) { // matriz de axb con elementos neutros
        N = a; M = b;
        t.resize(MAXNODES);
        build(0, N - 1, 0);
    }
    st2d(vector<vector<int>>& mat) { // construye a partir de mat
        N = mat.size(); M = mat[0].size();
        t.resize(MAXNODES);
        build(0, N - 1, 0, mat);
    }
    void build(int s, int e, int p, vector<vector<int>>& mat) {
        if(s == e) {
            t[p] = st(mat[s]);
            return;
        }
        build(s, m, l, mat);
        build(1 + m, e, r, mat);
        t[p] = st(t[l], t[r], M);
    }
    void build(int s, int e, int p) {
        t[p] = st(M);
        if(s == e)
            return;
        build(s, m, l);
        build(1 + m, e, r);
    }
    void upd(int& upx, int& upy, ii& uv, int s, int e, int p) {
        if(upx >= s && upx <= e) {
            if(s == e) t[p].set(upy, uv);
            else {
                upd(upx, upy, uv, s, m, l);
                upd(upx, upy, uv, 1 + m, e, r);
                t[p].set(upy, op(t[l].query(upy, upy), t[r].query(upy, upy)));
            }
        }
    }
    void upd(int x, int y, ii val) {
        upd(x, y, val, 0, N - 1, 0);
    }
    ii query(int& qx1, int& qx2, int& qy1, int& qy2, int s, int e, int p) {
        if(s >= qx1 && e <= qx2)  return t[p].query(qy1, qy2);
        if(s > qx2 || e < qx1) return NEUTRO;
        return op(query(qx1, qx2, qy1, qy2, s, m, l), query(qx1, qx2, qy1, qy2, 1 + m, e, r));
    }
    ii query(int x1, int y1, int x2, int y2) {
        return query(x1, x2, y1, y2, 0, N - 1, 0);
    }};
