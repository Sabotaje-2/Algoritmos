vector<vi> mul(vector<vi>& a, vector<vi>& b) {
    int n = a.size(), m = b[0].size();
    vector<vi> ans(n, vi(m, 0));
    foi(i,0,n)foi(j,0,m)foi(k,0,b.size())
        ans[i][j] += (a[i][k] * b[k][j]);
    return ans;
}
vector<vi> mpow(vector<vi>& mat, int exp) {
    vector<vi> ans(mat.size(), vi(mat.size(), 0)), power = mat;
    foi(i,0,ans.size()) ans[i][i] = 1;
    while(exp) {
        if(exp & 1)
            ans = mul(ans, power);
        power = mul(power, power);
        exp >>= 1;
    }
    return ans;
}
