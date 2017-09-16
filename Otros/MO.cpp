int block_sz;
struct query {
    int l,r,idx;
    bool operator < (const query& o) const {
        int fb = l / block_sz, sb = o.l / block_sz;
        if(fb == sb) return r < o.r;
        return fb < sb;
    }};
void add(int& newone, int& ans) {}
void rem(int& delone, int& ans) {}
void solve(int& newl, int& newr, int& L, int& R, int& ans, vector<int>& arr) {
    while(L < newl)
        rem(arr[L++], ans);
    while(R < newr)
        add(arr[++R], ans);
    while(L > newl)
        add(arr[--L], ans);
    while(R > newr)
        rem(arr[R--], ans);
}
void solve(vector<query>& queries, vector<int>& arr) {
    vector<int> ans(queries.size());
    int res,L,R;
    res = L = R = 0;
    block_sz = sqrt(arr.size());
    sort(queries.begin(), queries.end());
    add(arr[0], res);
    foi(i,0,queries.size()) {
        solve(queries[i].l, queries[i].r, L, R, res, arr);
        ans[queries[i].idx] = res;
    }
    foi(i,0,queries.size())
        cout << ans[i] << '\n';
}
