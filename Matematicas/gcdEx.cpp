// PROBAR
// <x,y,d> tal que a*x+b*y = d = gcd(a,b).
// Si d=1 se puede encontrar x, tal que a*x≡1(modN) llamando gcdex(a,N).
// x puede ser negativo, probar con gcdex(a=5,N=11).
tuple<int,int,int> gcdex(int a, int b) {
  if (b == 0) return {1, 0, a};
  int x,y,d; tie(x,y,d) = gcdex(b, a % b);
  return {y, x - (a/b)*y, d};
}
