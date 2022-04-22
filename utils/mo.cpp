// SPOJ COT2.
namespace mo {
  constexpr int CHK = 400;
  struct Query{int l,r,idx;};

  int L,R;
  vector<Query> queries;

  void solve(int nl, int nr, const vector<int>& v) {
    while (L < nl) rem(v[L++]);
    while (R < nr) add(v[++R]);
    while (L > nl) add(v[--L]);
    while (R > nr) rem(v[R--]);
  }
  
  vector<int> solve(const vector<int>& v) {
    sort(queries.begin(), queries.end(), [](const Query& p, const Query& q)->bool{
      int fb = p.l/CHK, sb = q.l/CHK;
      return fb == sb ? (fb&1 ? p.r > q.r : p.r < q.r) : fb < sb;
    });
    L = 0, R = 0; add(v[0]); // Find a way to remove this add function call.
    vector<int> ans(queries.size());
    for (const Query& q : queries) {
      solve(q.l, q.r, v);
      // ans[q.idx] = ?;
    }
    return ans;
  }
}
