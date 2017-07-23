struct wt {
    struct node {
        int l,r;
        node* left, *right;
        vector<int> mapl, mapr;
        node(int _l, int _r, int sz) : l(_l), r(_r), left(NULL), right(NULL) {
            mapl.resize(sz);
            mapr.resize(sz);
        }
    };
    node* root;
    wt(vector<int> arr) {
        root = build(arr, *min_element(arr.begin(), arr.end()), *max_element(arr.begin(), arr.end()), arr.begin(), arr.end());
    }
    ii map_it(const int& i, const int& j, const vector<int>& mapl) {
        return ii(i ? mapl[i - 1] : 0, mapl[j] - 1);
    }
    int kth(int i, int j, int k) {
        int c;
        node* curr = root;
        ii l, r;
        for(;;) {
            if(!curr->left) return curr->l;
            l = map_it(i, j, curr->mapl);
            r = map_it(i, j, curr->mapr);
            c = curr->mapl[j] - (i ? curr->mapl[i - 1] : 0);
            if(k <= c) i = l.first, j = l.second, curr = curr->left;
            else i = r.first, j = r.second, curr = curr->right, k -= c;
        }
    }
    node* build(const vector<int>& arr, int mini, int maxi, it s, it e) {
        node *n = new node(mini, maxi, e - s);
        if(mini == maxi) return n;
        int mid = (mini + maxi) >> 1, i = 0;
        for(it u = s; u != e; ++u, ++i)
            if(*u <= mid) {
                n->mapl[i] = i ? 1 + n->mapl[i - 1] : 1;
                n->mapr[i] = i ? n->mapr[i - 1] : 0;
            } else {
                n->mapr[i] = i ? 1 + n->mapr[i - 1] : 1;
                n->mapl[i] = i ? n->mapl[i - 1] : 0;
            }
        it m = stable_partition(s, e, [=](int k){return k<=mid;});
        n->left = build(arr, mini, mid, s, m);
        n->right = build(arr, 1 + mid, maxi, m, e);
        return n;
    }
};
