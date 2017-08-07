int LEFT, RIGHT, lmatch[MAX_L], rmatch[MAX_L + MAX_R];
bitset<MAX_L + MAX_R> visited;
bool kuhn(int u) {
    if(visited[u]) return false;
    visited[u] = true;
    for(const auto& v: g[u])
        if(rmatch[v] == -1 || kuhn(rmatch[v])) {
            lmatch[u] = v;
            rmatch[v] = u;
            return true;
        }
    return false;
}
void kuhn() {
    memset(lmatch, -1, sizeof lmatch);
    memset(rmatch, -1, sizeof rmatch);
    for(int u = 0; u < LEFT; ++u)
        for(auto v: g[u])
            if(rmatch[v] == -1) {
                lmatch[u] = v;
                rmatch[v] = u;
                break;
            }
    for(int u = 0; u < LEFT; ++u)
        if(lmatch[u] == -1) {
            visited.reset();
            kuhn(u);
        }
}
void dfs(int u, bool r = false) {
    if(visited[u]) return;
    visited[u] = true;
    if(r) {
        if(rmatch[u] != -1) dfs(rmatch[u]);
        return;
    }
    for(auto v: g[u])
        if(lmatch[u] != v)
            dfs(v, true);
}
vector<int> mvc() {
    vector<int> ans;
    kuhn();
    visited.reset();
    for(int i = 0; i < LEFT; ++i)
        if(lmatch[i] == -1)
            dfs(i);
    for(int i = 0; i < LEFT; ++i)
        if(!visited[i])
            ans.push_back(i);
    for(int i = LEFT; i < LEFT + RIGHT; ++i)
        if(visited[i])
            ans.push_back(i);
    return ans;
}
