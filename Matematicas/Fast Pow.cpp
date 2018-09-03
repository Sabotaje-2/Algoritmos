ll fpow(ll base, ll exp) {
    ll ans = 1LL, power = base;
    while(exp) {
        if(exp & 1) ans = (ans * power) % MOD;
        power = (power * power) % MOD;
        exp >>= 1;
    }
    return ans;
}
