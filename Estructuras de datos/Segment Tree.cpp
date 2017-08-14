#define left ((pos << 1) | 1)
#define right (1 + left)
#define mid ((low + high) >> 1)
struct stree {
    vector<int> tree;
    int sz;
    stree(vector<int>& arr) {
        tree.resize((sz = arr.size()) << 2);
        build(0, sz - 1, 0, arr);
    }
    int op(int a, int b){return max(a,b);}
    bool overlap(int qlow, int qhigh, int i, int j) {return !(qhigh < i || qlow > j);}
    int build(int low, int high, int pos, vector<int>& arr) {
        return tree[pos] = (low == high ? arr[low] : op(build(low, mid, left, arr), build(1 + mid, high, right, arr)));
    }
    int query(int& qlow, int& qhigh, int low, int high, int pos) {
        if(low >= qlow && high <= qhigh)  return tree[pos];
        if(overlap(qlow, qhigh, low, mid))
                return overlap(qlow, qhigh, 1 + mid, high) ? op(query(qlow, qhigh, low, mid, left), query(qlow, qhigh, 1 + mid, high, right)) : query(qlow, qhigh, low, mid, left);
        return query(qlow, qhigh, 1 + mid, high, right);
    }
    int query(int i, int j) {
        return query(i, j, 0, sz - 1, 0);
    }
    int update(int low, int high, int pos, int& x, int& val) {
        if(x >= low && x <= high) {
            if(low == high) return tree[pos] = val;
            return tree[pos] = op(update(low, mid, left, x, val), update(1 + mid, high, right, x, val));
        }
        return tree[pos];
    }
    void update(int pos, int val) {
        update(0, sz - 1, 0, pos, val);
    }};
