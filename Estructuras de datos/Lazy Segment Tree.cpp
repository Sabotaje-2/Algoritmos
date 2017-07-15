struct st {
    int tam;
    vector<ii> tree;
    vector<int> lazy;
    st(int n) {
        tam = n;
        tree.assign(tam << 2, ii(0,0));
        lazy.assign(tam << 2, 0);
        // build(0, tam - 1, 0, ...);
    }
    void build(int low, int high, int pos, vector<int>& arr) {
        if(low == high) {
            tree[pos].first = tree[pos].second = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = left + 1;
        build(low, mid, left, arr);
        build(mid + 1, high, right, arr);
        tree[pos].first = max(tree[left].first, tree[right].first);
        tree[pos].second = min(tree[left].second, tree[right].second);
    }
    ii lazy_query(int low, int high, int pos, int& qlow, int& qhigh) {
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = left + 1;
        if(lazy[pos] != 0) {
            tree[pos].first += lazy[pos];
            tree[pos].second += lazy[pos];
            if(low != high) {
              lazy[left] += lazy[pos];
              lazy[right] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        if (qhigh < low || qlow > high)
            return ii(-INF, INF);
        if (low >= qlow && high <= qhigh)
            return tree[pos];
        ii l = lazy_query(low, mid, left, qlow, qhigh);
        ii r = lazy_query(mid + 1, high, right, qlow, qhigh);
        return ii(max(l.first, r.first), min(l.second, r.second));
    }
    ii query(int i, int j) {
        return lazy_query(0, tam - 1, 0, i, j);
    }
    void lazy_update(int low, int high, int pos, int& qlow, int& qhigh, int& cant) {
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = left + 1;
        if(lazy[pos] != 0) {
            tree[pos].first += lazy[pos];
            tree[pos].second += lazy[pos];
            if(low != high) {
              lazy[left] += lazy[pos];
              lazy[right] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        if(low > qhigh || high < qlow)    return;
        if(low >= qlow && high <= qhigh) {
            tree[pos].first += cant;
            tree[pos].second += cant;
            if(low != high) {
              lazy[left] += cant;
              lazy[right] += cant;
            }
            return;
        }
        lazy_update(low, mid, left, qlow, qhigh, cant);
        lazy_update(mid + 1, high, right, qlow, qhigh, cant);
        tree[pos].first = max(tree[left].first, tree[right].first);
        tree[pos].second = min(tree[left].second, tree[right].second);
    }
    void update(int i, int j, int x) {
        lazy_update(0, tam - 1, 0, i, j, x);
    }};
