vector<vi> mul(vector<vi>& a, vector<vi>& b, int MOD) {
    int n = a.size(), m = b[0].size();
    vector<vi> ans(n, vi(m, 0));
    foi(i,0,n)foi(j,0,m)foi(k,0,b.size())
        ans[i][j] = (ans[i][j] + ((1LL * a[i][k] * b[k][j]) % MOD)) % MOD;
    return ans;
} 
vector<vi> mpow(vector<vi>& mat, int exp, int MOD) {
    vector<vi> ans(mat.size(), vi(mat.size(), 0)), power = mat;
    foi(i,0,ans.size()) ans[i][i] = 1;
    while(exp) {
        if(exp & 1)
            ans = mul(ans, power, MOD);
        power = mul(power, power, MOD);
        exp >>= 1;
    }
    return ans;
}
