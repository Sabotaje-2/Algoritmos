#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 210
#define EPS 1e-9
#define INF 1e9

struct TPoint{
  double x,y;
  TPoint() : x(0.0) , y(0.0) {}
  TPoint( double x , double y ) : x(x) , y(y) {}

  TPoint operator- (const TPoint& o) const {
    return TPoint( this->x - o.x , this->y - o.y );
  }
  TPoint operator+ (const TPoint& o) const {
    return TPoint( this->x + o.x , this->y + o.y );
  }
  double operator% (const TPoint& o) const {
    return this->x * o.y - this->y * o.x;
  }
  double operator* (const TPoint& o) const {
    return this->x * o.x + this->y * o.y;
  }
  TPoint operator* (const double& o) const {
    return TPoint(this->x * o , this->y * o);
  }
  TPoint operator/ (const double& o) const {
    return TPoint(this->x / o , this->y / o);
  }
  // La distancia a o
  double operator& (const TPoint& o) const {
    TPoint real = (*this) - o;
    return sqrt(real.x * real.x + real.y * real.y);
  }
};

int n;
TPoint polygon[ MAX ];

void  intersect ( TPoint& a,  TPoint& b,  TPoint& p,  TPoint& q , vector<TPoint>& inter )
{
  TPoint ab  = b-a , pq = q-p , aq = q-a , ap = p-a;
  // No se intersectan segmentos
  if( (aq % ab) * ( ap % ab ) > EPS ) return ;
  if( fabs(ab % pq) < EPS )  return;
  double t = (-( p % ab ) + ( a % ab ) ) / ( pq % ab );
  inter.push_back(p + (pq*t));
}

bool inside ( TPoint p )
{
  TPoint a , b;
  for( int i = 0 ; i < n ; ++i )
  {
    a = polygon[i] , b = polygon[ i + 1 ];
    if( fabs((p-a)%(b-a)) <= EPS && (p-a)*(b-a) >= -EPS && (p-b)*(a-b) >= -EPS )
      return true;
  }
  int fl = 0;
  double product;
  for( int i = 0 ; i < n ; ++i )
  {
    a = polygon[i] , b = polygon[ i + 1 ];
    if( fabs(a.y - b.y) < EPS )  continue;
    if( b.y < a.y ) swap( a , b );
    if( p.y > b.y - EPS || p.y < a.y  -EPS  )  continue;
    product = (p-a) % (b-a);
    if( product < -EPS  )  fl ^= 1 ;
  }
  return fl;
}

struct TComp{
  TPoint a, b;
  TComp( TPoint a , TPoint b ) : a(a) , b(b) {}
  bool operator() ( const TPoint& p , const TPoint& q ) const {
    return (p-a)*(b-a) < (q-a)*(b-a);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(6);
  cout << fixed ;
  while( cin >> n )
  {
    for( int i = 0 ; i < n ; ++i ) cin >> polygon[i].x >> polygon[i].y;
    polygon[n] = polygon[0];
    TPoint a , b , mid;
    double may , cont , dist;
    may = -INF;
    for( int i = 0 ; i < n ; ++i )
    {
      a = polygon[i] ;
      for( int j = i+1 ; j < n+1 ; ++j )
      {
        b = polygon[ j ];
        vector< TPoint > inter;
        for( int k = 0 ; k < n ; ++k )
           intersect( a, b, polygon[k], polygon[ k+1 ] , inter) ;
        sort( inter.begin(), inter.end(), TComp(a,b) );
        cont = 0.0;
        for( int k = 0 ; k <(int) inter.size()-1 ; ++k )
        {
          mid = (inter[ k ] + inter[ k+1 ]) / 2.0 ;
          if( inside(mid) )
          {
            dist = inter[k]&inter[ k+1 ];
            cont += dist;
          }
          else
          {
            may = max( cont , may );
            cont = 0.0;
          }
        }
        may = max( cont , may );
      }
    }
    cout << may << "\n";
  }
  return 0;
}
