int tam;
template<class T>
struct pst {
    struct node {
        node *left, *right;
        T val;
        node(){left = right = NULL;}
        node(const node* other) {
            this->left = other->left;
            this->right = other->right;
        }};
    node* root;
    pst(){root = NULL;}
    node* build(int low, int high) {
        node* n = new node;
        if(low == high)
            n->val = 0;
        else {
            int mid = (low + high) >> 1;
            n->left = build(low, mid);
            n->right = build(1 + mid, high);
            n->val = n->left->val + n->right->val;
        }
        return n;
    }
    T query(int low, int high, node* current, int& qlow, int& qhigh) {
        if(qhigh < low || qlow > high) return 0;
        if(low >= qlow && high <= qhigh) return current->val;
        int mid = (low + high) >> 1;
        return query(low, mid, current->left, qlow, qhigh) + query(1 + mid, high, current->right, qlow, qhigh);
    }
    T query(int i, int j) {
        return query(0, tam - 1, root, i, j);
    }
    node* update(int& pos, T& val, int low, int high, node* current) {
        node* n = new node(current);
        if(low == high)
            n->val = val;
        else {
            int mid = (low + high) >> 1;
            if(pos <= mid)
                n->left = update(pos, val, low, mid, current->left);
            else
                n->right = update(pos, val, 1 + mid, high, current->right);
            n->val = n->left->val + n->right->val;
        }
        return n;
    }
    node* update(int pos, T val) {
        return update(pos, val, 0, tam - 1, root);
    }};
