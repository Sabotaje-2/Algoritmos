void counting(vector<int>& arr, int div) {
    vector<vector<int>> cnt(10, vector<int>());
    vector<int> temp(arr.size());
    for(int i = 0; i < (int)arr.size(); ++i)
        cnt[(arr[i] / div) % 10].push_back(i);
    for(int i = 0, idx = 0; i < (int)cnt.size(); ++i)
        for(int j = 0; j < (int)cnt[i].size(); ++j)
            temp[idx++] = arr[cnt[i][j]];
    arr.swap(temp);
}
void radix_sort(vector<int>& arr) {
    int maxi = *max_element(arr.begin(), arr.end()), div = 1;
    while(maxi) {
        counting(arr, div);
        div *= 10;
        maxi /= 10;
    }
}
