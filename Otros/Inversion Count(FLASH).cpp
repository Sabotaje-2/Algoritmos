namespace INVERSIONS {
    int bit[MAXN], sz;
    void add(int x, int val) {
        while(x <= sz) {
            bit[x] += val;
            x += x&-x;
        }
    }
    int query(int x) {
        int ans = 0;
        while(x) {
            ans += bit[x];
            x -= x&-x;
        }
        return ans;
    }
    int query(int i, int j) {
        assert(i >= 1 && j >= 1 && i < MAXN && j < MAXN && i <= j); // #define NDEBUG?
        return query(j) - (i == 1 ? 0 : query(i - 1));
    }
    int v[MAXN];
    const int BEG = 1;
    ll solve(int* arr, int N) {
        copy(arr, arr + N, v); sort(v, v + N);
        ll ans = 0LL; int num;
        sz = unique(v, v + N) - v;
        fill(bit + 1, bit + sz + 1, 0); // memset ?
        for(int i = N - 1; ~i; --i) {
            num = BEG + lower_bound(v, v + sz, arr[i]) - v;
            if(num > 1) ans += (1LL * query(1, num - 1));
            add(num, 1);
        }
        return ans;
    }}
