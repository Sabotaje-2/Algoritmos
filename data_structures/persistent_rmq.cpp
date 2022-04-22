template<class T>
struct Node {
  #define mi ((s+e)/2)
  Node *ln = nullptr, *rn = nullptr;
  T val;

  Node() = default;
  Node(const Node* o) : ln{o->ln}, rn{o->rn} {}

  T query(int s, int e, int l, int r) {
    if (l > r) return 0; // Elemento neutro.
    if (s == l && e == r) return val;
    return ln->query(s, mi, l, min(mi,r)) +
           rn->query(1+mi, e, max(1+mi,l), r);
  }

  Node* update(int s, int e, int p, const T& x) {
    Node* n = new Node(this);
    if (s == e) {
      n->val = x;
    } else if (p <= mi) {
      n->ln = ln->update(s, mi, p, x);
      n->val = n->ln->val + rn->val;
    } else {
      n->rn = rn->update(1+mi, e, p, x);
      n->val = ln->val + n->rn->val;
    }
    return n;
  }
};
