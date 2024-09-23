// CF 2014H
namespace mo {
constexpr int CHK = 400;
struct Query{int l,r,idx;};
vector<Query> queries;
int L,R;
void solve(int nl, int nr, const vector<int>& v) {
  while (L < nl) add(v[L++], -1);
  while (R < nr) add(v[R++], 1);
  while (L > nl) add(v[--L], 1);
  while (R > nr) add(v[--R], -1);
}
void solve(const vector<int>& v) {
  sort(queries.begin(), queries.end(), [](const Query& p, const Query& q)->bool{
    int fb = p.l/CHK, sb = q.l/CHK;
    return fb == sb ? (fb&1 ? p.r > q.r : p.r < q.r) : fb < sb;
  });
  L = 0, R = 0;
  for (auto q : queries) {
    solve(q.l, q.r, v);
  }
}}
