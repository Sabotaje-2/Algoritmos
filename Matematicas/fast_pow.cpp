int fast_pow(int base, int exp, int MOD) {
    int ans = 1ULL, power = base;
    while(exp) {
        if(exp & 1)
            ans = (1ULL * ans * power) % MOD;
        power = (1ULL * power * power) % MOD;
        exp >>= 1;
    }
    return ans;
}
