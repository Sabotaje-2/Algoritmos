struct shash {
    int B,P;
    vector<int> h, pot;
    const int MIN = 1e9;
    bool prime(int k) {
        for(int i = 2; i * i <= k; ++i)
            if(!(k % i)) return false;
        return true;
    }
    shash(string& s) {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        P = uniform_int_distribution<>(2, (int)5e8)(rng) + MIN;
        while(!prime(P)) ++P;
        B = uniform_int_distribution<>(2, P - 2)(rng);
        build(s);
    }
    shash(string& s, const shash& o) {
        B = o.B;
        P = o.P;
        build(s);
    }
    int get(int i, int j) {
        if(!i) return h[j];
        int ans = h[j] - ((1LL * h[i - 1] * pot[1 + j - i]) % P);
        if(ans < 0) ans += P;
        return ans;
    }
    void build(string& s) {
        h.resize(s.size());
        pot.resize(s.size());
        h[0] = s[0];
        pot[0] = 1;
        foi(i,1,s.size()) {
            h[i] = (((1LL * h[i - 1] * B) % P) + s[i]) % P;
            pot[i] = (1LL * B * pot[i - 1]) % P;
        }
    }};
