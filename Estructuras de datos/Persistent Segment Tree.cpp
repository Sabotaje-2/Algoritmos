int tam;
template<class T>
struct PST {
  struct Node {
    Node *left, *right;
    T val;
    Node() : left{nullptr}, right{nullptr} {}
    Node(const Node* o) : left{o->left}, right{o->right} {}};
  Node* root;
  PST() : root{nullptr} {}
  Node* build(int low, int high) {
    Node* n = new Node;
    if (low == high) {
      n->val = 0;
    } else {
      int mid = (low + high) >> 1;
      n->left = build(low, mid);
      n->right = build(1 + mid, high);
      n->val = n->left->val + n->right->val;
    }
    return n;
  }
  T query(int low, int high, Node* current, int qlow, int qhigh) {
    if (qhigh < low || qlow > high) return 0;
    if (low >= qlow && high <= qhigh) return current->val;
    int mid = (low + high) >> 1;
    return query(low, mid, current->left, qlow, qhigh) + query(1 + mid, high, current->right, qlow, qhigh);
  }
  T query(int i, int j) {
    return query(0, tam - 1, root, i, j);
  }
  Node* update(int pos, const T& val, int low, int high, Node* current) {
    Node* n = new Node(current);
    if (low == high) {
      n->val = val;
    } else {
      int mid = (low + high) >> 1;
      if (pos <= mid) {
        n->left = update(pos, val, low, mid, current->left);
      } else {
        n->right = update(pos, val, 1 + mid, high, current->right);
      }
      n->val = n->left->val + n->right->val;
    }
    return n;
  }
  Node* update(int pos, const T& val) {
    return update(pos, val, 0, tam - 1, root);
  }};
