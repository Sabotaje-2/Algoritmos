int lis(vector<int>& arr) {
    vector<int> ans;
    for(const auto& u: arr)
        if(ans.empty()) ans.push_back(u);
        else if(u < ans[0]) ans[0] = u;
        else if(u > ans.back()) ans.push_back(u);
        else ans[lower_bound(ans.begin(), ans.end(), u) - ans.begin()] = u;
    return ans.size();
}
