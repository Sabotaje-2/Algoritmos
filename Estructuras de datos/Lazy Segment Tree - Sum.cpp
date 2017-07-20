struct lazy_tree {
    vector<ll> tree, lazy;
    int sz;
    lazy_tree(int n) {
        tree.assign(n << 2, 0LL);
        lazy.assign(n << 2, 0LL);
        sz = n;
    }
    void push(int pos, int low, int high) {
        tree[pos] += ((1LL + high - low) * lazy[pos]);
        if(low != high) {
            int l = (pos << 1) | 1, r = 1 + l;
            lazy[l] += lazy[pos];
            lazy[r] += lazy[pos];
        }
        lazy[pos] = 0LL;
    }
    ll query(int& qlow, int& qhigh, int low, int high, int pos) {
        push(pos, low, high);
        int left = (pos << 1) | 1, mid = (low + high) >> 1, right = 1 + left;
        if(qhigh < low || qlow > high) return 0LL;
        if(low >= qlow && high <= qhigh) return tree[pos];
        return query(qlow, qhigh, low, mid, left) + query(qlow, qhigh, 1 + mid, high, right);
    }
    ll query(int i, int j) {
        return query(--i, --j, 0, sz - 1, 0);
    }
    ll range(int low, int high, int i, int j) {
        int ans = 1 + (j - i);
        if(i >= low && j <= high) return ans;
        if(i >= low)
            ans -= (j - high);
        else
            ans -= (low - i);
        return ans;
    }
    void update(int& qlow, int& qhigh, ll& val, int low, int high, int pos) {
        push(pos, low, high);
        int left = (pos << 1) | 1, mid = (low + high) >> 1, right = 1 + left;
        if(qhigh < low || qlow > high) return;
        if(low >= qlow && high <= qhigh) {
            tree[pos] += ((1LL + high - low) * val);
            if(low != high) {
                lazy[left] += val;
                lazy[right] += val;
            }
        }
        else {
            tree[pos] += (range(low, high, qlow, qhigh) * val);
            update(qlow, qhigh, val, low, mid, left);
            update(qlow, qhigh, val, 1 + mid, high, right);
        }
    }
    void update(int i, int j, ll val) {
        update(--i, --j, val, 0, sz - 1, 0);
    }};
