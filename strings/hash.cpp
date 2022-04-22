// Codeforces GYM 102448A.
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct shash {
  int h[MAXN], pot[MAXN], B, P;
  static constexpr int MIN = 4e8;

  static pair<int,int> gen() {
    int P = uniform_int_distribution<>(2, (int)5e8)(rng) + MIN;
    while (!prime(P)) ++P;
    int B = uniform_int_distribution<>(500, P-2)(rng);
    return {B,P};
  }

  int get(int i, int j) {
    return sub(h[j], mul(i >= 1 ? h[i-1] : 0, pot[1+j-i], P), P);
  }
  
  void build(const string& s) {
    h[0] = s[0];
    pot[0] = 1;
    for (int i = 1; i < (int)s.size(); ++i) {
      h[i] = add(mul(h[i-1], B, P), s[i], P);
      pot[i] = mul(B, pot[i-1], P);
    }
  }
};
