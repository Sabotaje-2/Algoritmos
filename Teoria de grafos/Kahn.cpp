int in[MAX_NODOS]; //hacer memset antes de leer
vector < vector < int > > g;
vector < int > kahn() {// return toposort
  vector < int > ans;
  queue < int > kahn;
  int u;
  foi(i, 0, g.size())
    if(!in[i])  kahn.push(i);
  while(!kahn.empty()) {
    u = kahn.front();
    ans.push_back(u);
    kahn.pop();
    foi(i, 0, g[u].size())
      if(!--in[g[u][i]])
        kahn.push(g[u][i]);
  }
  return ans;
}
