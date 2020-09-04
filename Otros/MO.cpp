// PROBAR
namespace mo {
constexpr int CHK = 400;
struct Query{int l,r,idx;};
int L,R;
vector<Query> queries;
void add(int x){assert(false);} // Agregar x.
void rem(int x){assert(false);} // Remover x.
void solve(int newl, int newr, const vector<int>& arr) {
  while (L < newl) rem(arr[L++]);
  while (R < newr) add(arr[++R]);
  while (L > newl) add(arr[--L]);
  while (R > newr) rem(arr[R--]);
}
void solve(const vector<int>& arr) {
  sort(queries.begin(), queries.end(), [](const Query& p, const Query& q)->bool{
    int fb = p.l/CHK, sb = q.l/CHK;
    return fb == sb ? (fb&1 ? p.r > q.r : p.r < q.r) : fb < sb;
  });
  L = 0, R = 0; add(arr[0]);
  for (auto q : queries) {
    solve(q.l, q.r, arr);
    // ans[q.idx] = ?;
  }
}}
