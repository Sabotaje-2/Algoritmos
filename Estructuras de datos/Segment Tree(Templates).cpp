#define left ((pos << 1) | 1)
#define right (1 + left)
#define mid ((low + high) >> 1)
template<class type>
struct node {
    type val;
    node(const node& a, const node& b) {
        val = max(a.val,b.val);
    }
    node(){}
    void build(type& k) {
        val = k;
    }};
template<class type, class node_type>
struct stree {
    vector<node_type> tree;
    int sz;
    stree(vector<type>& arr) {
        tree.resize((sz = arr.size()) << 2);
        build(0, sz - 1, 0, arr);
    }
    static bool overlap(int qlow, int qhigh, int i, int j) {return !(qhigh < i || qlow > j);}
    void build(int low, int high, int pos, vector<type>& arr) {
        if(low == high) {
            tree[pos].build(arr[low]);
            return;
        }
        build(low, mid, left, arr);
        build(1 + mid, high, right, arr);
        tree[pos] = node_type(tree[left], tree[right]);
    }
    node_type query(int& qlow, int& qhigh, int low, int high, int pos) {
        if(low >= qlow && high <= qhigh)  return tree[pos];
        if(overlap(qlow, qhigh, low, mid))
                return overlap(qlow, qhigh, 1 + mid, high) ? node_type(query(qlow, qhigh, low, mid, left), query(qlow, qhigh, 1 + mid, high, right)) : query(qlow, qhigh, low, mid, left);
        return query(qlow, qhigh, 1 + mid, high, right);
    }
    node_type query(int i, int j) {
        node<int> ans;
        ans.val = 0;
        if(i > j) return ans;
        return query(i, j, 0, sz - 1, 0);
    }
    node_type update(int low, int high, int pos, int& x, type& val) {
        if(x >= low && x <= high) {
            if(low == high) tree[pos].build(val);
            else tree[pos] = node_type(update(low, mid, left, x, val), update(1 + mid, high, right, x, val));
        }
        return tree[pos];
    }
    void update(int pos, type val) {
        update(0, sz - 1, 0, pos, val);
    }};
