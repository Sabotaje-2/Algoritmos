struct st {
  vector < int > tree;
  int tam;
  st(vector < int >& arr) {
    tree.resize(arr.size() << 2);
    tam = arr.size();
    build(0, tam - 1, 0, arr);
  }
  void build(int low, int high, int pos, vector < int >& arr) {
    if(low == high) {
      tree[pos] = arr[low];
      return;
    }
    int mid = (low + high) >> 1;
    int left = (pos << 1) | 1;
    int right = 1 + left;
    build(low, mid, left, arr);
    build(1 + mid, high, right, arr);
    tree[pos] = tree[left] + tree[right];
  }
  int query(int& qlow, int& qhigh, int low, int high, int pos) {
    if(qhigh < low || qlow > high)  return 0;
    if(low >= qlow && high <= qhigh)  return tree[pos];
    int mid = (low + high) >> 1;
    int left = (pos << 1) | 1;
    int right = 1 + left;
    return query(qlow, qhigh, low, mid, left) + query(qlow, qhigh, 1 + mid, high, right);
  }
  void update(int low, int high, int pos, int& x, int& val) {
    if(x >= low && x <= high) {
      if(low == high) {
        tree[pos] = val;
        return;
      }
      int mid = (low + high) >> 1;
      int left = (pos << 1) | 1;
      int right = 1 + left;
      update(low, mid, left, x, val);
      update(1 + mid, high, right, x, val);
      tree[pos] = tree[left] + tree[right];
    }
  }
  int query(int i, int j) {
    return query(i, j, 0, tam - 1, 0);
  }
  void update(int pos, int val) {
    update(0, tam - 1, 0, pos, val);
  }
};
