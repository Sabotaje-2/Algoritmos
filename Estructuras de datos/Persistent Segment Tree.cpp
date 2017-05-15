int tam; // segment tree size
struct node {
    node *left, *right;
    int val;
    node(){left = right = NULL;}
    node(const node* other) {
        this->left = other->left;
        this->right = other->right;
    }};
struct pst {
    node* root;
    pst(){root = NULL;}
    pst(vector <int>& arr) {
        root = build(0, tam - 1, arr);
    }
    node* build(int low, int high, vector <int>& arr) {
        node* n = new node;
        if(low == high)
            n->val = arr[low];
        else {
            int mid = (low + high) >> 1;
            n->left = build(low, mid, arr);
            n->right = build(1 + mid, high, arr);
            n->val = n->left->val + n->right->val;
        }
        return n;
    }
    int query(int low, int high, node* current, int& qlow, int& qhigh) {
        if(qhigh < low || qlow > high)  return 0;
        if(low >= qlow && high <= qhigh)    return current->val;
        int mid = (low + high) >> 1;
        return query(low, mid, current->left, qlow, qhigh) + query(1 + mid, high, current->right, qlow, qhigh);
    }
    int query(int i, int j) {
        return query(0, tam - 1, root, i, j);
    }
    bool in(int& pos, int& low, int& high) {
        return pos >= low && pos <= high;
    }
    node* update(int& pos, int& val, int low, int high, node* current) {// return root of new version of segment tree
        node* n = new node(current);
        if(low == high)
            n->val = val;
        else {
            int mid = (low + high) >> 1;
            if(in(pos, low, mid))
                n->left = update(pos, val, low, mid, current->left);
            else
                n->right = update(pos, val, 1 + mid, high, current->right);
            n->val = n->left->val + n->right->val;
        }
        return n;
    }
    node* update(int pos, int val) {
        return update(pos, val, 0, tam - 1, root);
    }};
