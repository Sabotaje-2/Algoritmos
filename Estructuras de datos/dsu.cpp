struct dsu {
  vector < int > parent, sz;
  dsu(int n) {
    sz.assign(n, 1);
    parent.assign(n, 0);
    foi(i, 1, n)
      parent[i] = i;
  }
  int find_parent(int k) {
    return parent[k] == k ? k : parent[k] = find_parent(parent[k]);
  }
  void join(int i, int j) {
    int p = find_parent(i),q = find_parent(j);
    if(p == q)  return;
    if(sz[q] > sz[p])   swap(p, q);
    sz[p] += sz[q];
    parent[q] = p;
  }
  bool connected(int i, int j) {
    return find_parent(i) == find_parent(j);
  }};
