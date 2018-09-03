#define left ((pos << 1) | 1)
#define right (1 + left)
#define mid ((low + high) >> 1)
struct lazy_st {
    vector<ll> tree, lazy;
    int sz;
    lazy_st(int n) {
        tree.resize((sz = n) << 2);
        lazy.resize(n << 2);
    }
    void push(int pos, int l, int r) {
        tree[pos] += (1LL * (1 + r - l) * lazy[pos]);
        if(l != r) {
            lazy[left] += lazy[pos];
            lazy[right] += lazy[pos];
        }
        lazy[pos] = 0LL;
    }
    ll query(const int& ql, const int& qr, int low, int high, int pos) {
        push(pos, low, high);
        if(qr < low || ql > high) return 0LL;
        if(low >= ql && high <= qr) return tree[pos];
        return query(ql, qr, low, mid, left) + query(ql, qr, 1 + mid, high, right);
    }
    ll query(int l, int r){return query(l, r, 0, sz - 1, 0);}
    ll update(const int& ql, const int& qr, ll& qu, int low, int high, int pos) {
        push(pos, low, high);
        if(qr < low || ql > high) return tree[pos];
        if(low >= ql && high <= qr) {
            if(low != high) {
                lazy[left] += qu;
                lazy[right] += qu;
            }
            return tree[pos] += (1LL * (1 + high - low) * qu);
        }
        return tree[pos] = update(ql, qr, qu, low, mid, left) + update(ql, qr, qu, 1 + mid, high, right);
    }
    void update(int l, int r, ll qu){update(l, r, qu, 0, sz - 1, 0);}};
