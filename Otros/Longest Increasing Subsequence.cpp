vector <int> parent,ind;
void path(int i, vector <int>& ans) {
    if(i == -1) return;
    path(parent[i], ans);
    ans.push_back(i);
}
vector <int> lis(vector <int>& arr) {
    int pos;
    vector <int> l;
    parent.assign(arr.size(), -1);
    ind.clear();
    foi(i,0,arr.size()) {
        if(l.empty()) {
            l.push_back(arr[i]);
            ind.push_back(i);
        }
        else if(arr[i] > l.back()) {
            parent[i] = ind.back();
            l.push_back(arr[i]);
            ind.push_back(i);
        }
        else if(arr[i] < *l.begin()) {
            l[0] = arr[i];
            ind[0] = i;
        }
        else {
            pos = lower_bound(l.begin(), l.end(), arr[i]) - l.begin();
            l[pos] = arr[i];
            ind[pos] = i;
            if(pos)
                parent[i] = ind[pos - 1];
        }
    }
    vector <int> ans;
    path(ind.back(), ans);
    return ans; // retorna los indices de la lis
}
