// Codeforces GYM 102448A.
// Hash para queries en rangos (substrings).
// Para hash de S[i...j] -> get(i,j).
// Para construir hash de S usando una base random -> shash sh{S}.
// Para construir hash de S usando la base de qh -> shash sh{S,qh}.
struct shash {
int h[MAXN], pot[MAXN], B, P;
static constexpr int MIN = 1e9;
bool prime(int k) {
  for (int i = 2; i * i <= k; ++i) if ((k % i) == 0) return false;
  return true;
}
shash(string& s) {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  P = uniform_int_distribution<>(2, (int)5e8)(rng) + MIN;
  while (!prime(P)) ++P;
  B = uniform_int_distribution<>(2, P - 2)(rng);
  build(s);
}
shash(string& s, const shash& o) : B{o.B}, P{o.P} {
  build(s);
}
int get(int i, int j) {
  return sub(h[j], mul(i >= 1 ? h[i - 1] : 0, pot[1 + j - i], P), P);
}
void build(string& s) {
  h[0] = s[0];
  pot[0] = 1;
  foi (i,1,s.size()) {
    h[i] = add(mul(h[i - 1], B, P), s[i], P);
    pot[i] = mul(B, pot[i - 1], P);
  }
}};
