// Codeforces 1295D.
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
  return (a / gcd(a,b)) * b;
}

// PROBAR
// <x,y,d> such that a*x+b*y = d = gcd(a,b).
// If d=1 one can find x, such that a*x≡1(modN) by calling gcdex(a,N).
// be careful, x may be negative, gcdex(a=5,N=11).
tuple<int,int,int> gcdex(int a, int b) {
  if (b == 0) return {1, 0, a};
  int x,y,d; tie(x,y,d) = gcdex(b, a % b);
  return {y, x - (a/b)*y, d};
}