#define le ((pos << 1) | 1)
#define ri (1 + le)
#define m ((s + e) >> 1)
template<typename T>
struct STree {
  vector<T> tree;
  function<T(T, T)> op;
  int sz;
  STree(int N, function<T(T,T)> f) : op{f}, sz{N} {
    assert(op); tree.resize(sz << 2);
  }
  void build(int arr[], int N) {
    sz = N; build(arr, 0, sz - 1, 0);
  }
  void build(int arr[], int s, int e, int pos) {
    if (s == e) {
      tree[pos] = arr[s];
      return;
    } else {
      build(arr, s, m, le);
      build(arr, 1 + m, e, ri);
      tree[pos] = op(tree[le], tree[ri]);
    }
  }
  bool overlap(int qs, int qe, int s, int e) {return !(qe < s || qs > e);}
  T query(int qs, int qe, int s, int e, int pos) {
    if (s >= qs && e <= qe)  return tree[pos];
    if (overlap(qs, qe, s, m))
      return overlap(qs, qe, 1 + m, e) ? op(query(qs, qe, s, m, le),
          query(qs, qe, 1 + m, e, ri)) : query(qs, qe, s, m, le);
    return query(qs, qe, 1 + m, e, ri);
  }
  void update(int s, int e, int pos, int x, const T& val) {
    if (x >= s && x <= e) {
      if (s == e) {
        tree[pos] = val;
      } else {
        update(s, m, le, x, val), update(1 + m, e, ri, x, val);
        tree[pos] = op(tree[le], tree[ri]);
      }
    }
  }
  T query(int i, int j) {return query(i, j, 0, sz - 1, 0);} // check i <= j?
  void update(int pos, const T& val) {update(0, sz - 1, 0, pos, val);}};
struct SegTreeNode {
  int min1, min2;
  const SegTreeNode& operator=(int x) {
    min1 = x;
    min2 = INF;
    return *this;
  }
};
vector<STree<SegTreeNode>> st(10, STree<SegTreeNode>(MAXN, [](const SegTreeNode& p, const SegTreeNode& q)->SegTreeNode{
  SegTreeNode s;
  if (p.min1 <= q.min1) {
    s.min1 = p.min1;
    s.min2 = min(p.min2, q.min1);
  } else {
    s.min1 = q.min1;
    s.min2 = min(q.min2, p.min1);
  }
  return s;
}));
