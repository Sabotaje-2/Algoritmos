ll MOD =  1000000007;
// A(n,m) = (n-m)A(n-1,m-1) + (m+1)A(n-1,m) Formula 
// Da las permutaciones de 1 a n , de tal manera que hay exactamente m elementos mayores al elemento anterior 
int eulerian[MAX][MAX];
ll go( ll n , ll m )
{
  if( n == 1 || m == 0 || m == n-1 )
    return 1;
  if( ~eulerian[ n ][ m ] )
    return eulerian[ n ][ m ];
    return eulerian[ n ][ m ] = ((((n-m+MOD)%MOD)*go(n-1,m-1))%MOD + ((m+1)*go(n-1,m))%MOD)%MOD;
  // return eulerian[ n ][ m ] = (n-m)*go(n-1,m-1) + (m+1)*go(n-1,m);
}

