namespace mo { // PROBAR?
constexpr int CHK = 400;
int L,R;
struct Query{int l,r,idx;};
void add(int x){assert(false);} // Agregar x.
void rem(int x){assert(false);} // Remover x.
void solve(int newl, int newr, const vector<int>& arr) {
  while (L < newl) rem(arr[L++]);
  while (R < newr) add(arr[++R]);
  while (L > newl) add(arr[--L]);
  while (R > newr) rem(arr[R--]);
}
void solve(vector<Query>& queries, const vector<int>& arr) {
  vector<int> ans(queries.size());
  sort(queries.begin(), queries.end(), [](const Query& p, const Query& q)->bool{
    int fb = p.l / CHK, sb = q.l / CHK;
    return fb == sb ? (fb & 1 ? p.r > q.r : p.r < q.r) : fb < sb;
  });
  L = 0, R = 0; add(arr[0]);
  foi (i,0,queries.size()) {
    solve(queries[i].l, queries[i].r, arr);
    // ans[queries[i].idx] = ?;
  }
}}
