#define left ((pos << 1) | 1)
#define right (1 + left)
#define mid ((low + high) >> 1)
static bool overlap(int qlow, int qhigh, int i, int j) {return !(qhigh < i || qlow > j);}
template<class type, class node_type>
struct st {
    vector<node_type> tree;
    int sz;
    st(vector<type>& arr) {
        tree.resize((sz = arr.size()) << 2);
        build(0, sz - 1, 0, arr);
    }
    st(){}
    void build(int low, int high, int pos, vector<type>& arr) {
        if(low == high) {
            tree[pos].build(arr[low]);
            return;
        }
        build(low, mid, left, arr);
        build(1 + mid, high, right, arr);
        tree[pos] = node_type(tree[left], tree[right]);
    }
    void build(int low, int high, int pos, st<type, node_type>& st1, st<type, node_type>& st2) {
        if(low == high) {
            tree[pos] = node_type(st1.tree[pos], st2.tree[pos]);
            return;
        }
        build(low, mid, left, st1, st2);
        build(1 + mid, high, right, st1, st2);
        tree[pos] = node_type(tree[left], tree[right]);
    }
    node_type query(int& qlow, int& qhigh, int low, int high, int pos) {
        if(low >= qlow && high <= qhigh)  return tree[pos];
        if(overlap(qlow, qhigh, low, mid))
                return overlap(qlow, qhigh, 1 + mid, high) ? node_type(query(qlow, qhigh, low, mid, left), query(qlow, qhigh, 1 + mid, high, right)) : query(qlow, qhigh, low, mid, left);
        return query(qlow, qhigh, 1 + mid, high, right);
    }
    node_type query(int i, int j) {
        return query(i, j, 0, sz - 1, 0);
    }
    node_type update(int low, int high, int pos, int& x, type& val) {
        if(x >= low && x <= high) {
            if(low == high) tree[pos].build(val);
            else tree[pos] = node_type(update(low, mid, left, x, val), update(1 + mid, high, right, x, val));
        }
        return tree[pos];
    }
    void update(int pos, int val) {
        update(0, sz - 1, 0, pos, val);
    }
    node_type update2(int low, int high, int pos, int& x, node_type& n) {
        if(x >= low && x <= high) {
            if(low == high) tree[pos] = n;
            else tree[pos] = node_type(update2(low, mid, left, x, n), update2(1 + mid, high, right, x, n));
        }
        return tree[pos];
    }
    void update2(int pos, node_type n) {
        update2(0, sz - 1, 0, pos, n);
    }
    st join(st<type, node_type>& a, st<type, node_type>& b, int n) {
        tree.resize((sz = n) << 2);
        build(0, sz - 1, 0, a, b);
        return *this;
    }};
template<class type>
struct node {
    type sum;
    node(const node& a, const node& b) {
        sum = a.sum + b.sum;
    }
    void build(type& k) {
        sum = k;
    }
    node(){}};
template<class type, class node_type>
struct st2d {
    vector<st<type,node_type>> tree;
    int sz;
    st2d(vector<vector<type>>& mat) {
        tree.resize((sz = mat.size()) << 2);
        build(0, sz - 1, 0, mat);
    }
    void build(int low, int high, int pos, vector<vector<type>>& mat) {
        if(low == high) {
            tree[pos] = st<type,node_type>(mat[low]);
            return;
        }
        build(low, mid, left, mat);
        build(1 + mid, high, right, mat);
        tree[pos].join(tree[left], tree[right], mat[0].size());
    }
    node_type query(int& x1, int& y1, int& x2, int& y2, int low, int high, int pos) {
        if(low >= x1 && high <= x2) return tree[pos].query(y1, y2);
        if(overlap(x1, x2, low, mid))
            return overlap(x1, x2, 1 + mid, high) ? node<type>(query(x1, y1, x2, y2, low, mid, left), query(x1, y1, x2, y2, 1 + mid, high, right)) : query(x1, y1, x2, y2, low, mid, left);
        return query(x1, y1, x2, y2, 1 + mid, high, right);
    }
    node_type query(int x1, int y1, int x2, int y2) {
        return query(x1, y1, x2, y2, 0, sz - 1, 0);
    }
    void update(int& x, int& y, type& val, int low, int high, int pos) {
        if(x >= low && x <= high) {
            if(low == high) {
                tree[pos].update(y, val);
                return;
            }
            update(x, y, val, low, mid, left);
            update(x, y, val, 1 + mid, high, right);
            tree[pos].update2(y, node<type>(tree[left].query(y,y), tree[right].query(y,y)));
        }
    }
    void update(int x, int y, type val) {
        update(x, y, val, 0, sz - 1, 0);
    }};
