#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define foi( i , n , k ) for(int i = n ; i < k ; ++i )

class SegmentTree
{
  private:
    vector<int> st;
    string A;
    vector< pair<char,char> > lazy;
    int n;
    int left( int p ){ return p << 1 ; }
    int right( int p ){ return ( p << 1 ) + 1 ; }

    void build( int p , int L , int R )
    {
      if( L == R )
      {
        st[p]=A[L]-'0';
      }
      else
      {
        build(left(p),L,(L+R)/2);
        build(right(p),(L+R)/2+1,R);
        int p1=st[left(p)],p2=st[right(p)];
        st[p]=p1+p2;
      }
    }
    int rsq(int p , int L , int R , int i , int j )
    {
      if( i > R || j < L )
        return -1;
      if( L >= i && R <= j )
        return st[p];
      int p1=rsq( left(p) , L , (L+R)/2 , i , j );
      int p2=rsq( right(p) , (L+R)/2+1 , R , i, j);
      if( p1 == -1)
        return p2;
      if( p2 == -1)
        return p1;
      return p1+p2;
    }
    void cambio( int p ,char T, int L,int R)
    {
      if(T=='I')
      {
        st[p]=(R-L)+1-st[p];
      }
      else if( T == 'F' )
      {
        st[p]=(R-L)+1;
      }
      else if( T == 'E' )
      {
        st[p] = 0;
      }
    }

    void colocar( int p ,char T)
    {
      if(T=='I')
      {
        if( lazy[p].second == 'I' )
          lazy[p].second=' ';
        else
          lazy[p].second=T;
      }
      else
      {
        lazy[p].second=' ';
        lazy[p].first=T;
      }
    }
    void cambio(int p , int L , int R , char T)
    {

      cambio(p, T , L , R );
      if( left(p) < 4*n ){
        if(T=='I')
        {
          if( lazy[left(p)].second == 'I' )
            lazy[left(p)].second=' ';
          else
            lazy[left(p)].second=T;
        }
        else
        {
          lazy[left(p)].second=' ';

          lazy[left(p)].first=T;
        }
      }
      if( right(p) < 4*n ){
        if(T=='I')
        {
          if( lazy[right(p)].second == 'I' )
            lazy[right(p)].second=' ';
          else
            lazy[right(p)].second=T;
        }
        else
        {
          lazy[right(p)].second=' ';

          lazy[right(p)].first=T;
        }
      }

    }
    void cambio(int p , int L,int R)
    {
      if(lazy[p].first!=' ')
        cambio(p,L,R,lazy[p].first);
      if(lazy[p].second!=' ')
        cambio(p,L,R,lazy[p].second);
      lazy[p]= make_pair(' ',' ');
    }
    void lazyUpdate( int p , int L , int R , int i , int j ,char T)
    {
      if( lazy[p]!= make_pair(' ',' ') )
      {
        cambio(p,L,R);

      }
      if( i > R || j < L )
      {
        return ;
      }
      if( L >= i && R <= j )
      {
        colocar(p,T);
        cambio(p,L,R);

        return ;
      }

      lazyUpdate( left(p) , L , (L+R)/2 , i , j ,T);
      lazyUpdate( right(p) , (L+R)/2+1 , R , i, j,T);
      int p1=st[left(p)],p2=st[right(p)];
      st[p]=p1+p2;
    }
    int rsqLazy( int p , int L , int R , int i , int j)
    {
      // cout<<p<<" "<<L<<" "<<R<<" "<<i<<" "<<j<<endl;
      if( lazy[p]!= make_pair(' ',' ') )
      {
        cambio(p,L,R);

      }
      if( i > R || j < L )
      {
        return -1 ;
      }
      if( L >= i && R <= j )
      {

        return st[p];
      }
      int p1=rsqLazy( left(p) , L , (L+R)/2 , i , j );
      int p2=rsqLazy( right(p) , (L+R)/2+1 , R , i, j);
      if( p1 == -1)
        return p2;
      if( p2 == -1)
        return p1;
      return p1+p2;
    }
  public:
    SegmentTree(const string&_A)
    {
      A=_A;
      n=(int)A.size();
      st.assign(4*n,0);
      lazy.assign(4*n,make_pair(' ',' '));
      build(1,0,n-1);
    }
    int rsq(int i , int j )
    {
      return rsq(1,0,n-1,i,j);
    }
    int rsqLazy( int i , int j )
    {
      return rsqLazy( 1 ,0 , n-1 , i ,j );
    }
    void lazyUpdate( int i , int j , char T)
    {
      lazyUpdate(  1 , 0 , n-1 , i , j ,T );
    }
    void printST()
    {
      foi( i , 0 , st.size() )
        cout<<i<<" . "<<st[i]<<" | ";
      cout<<endl;
    }
    void printLa()
    {
      foi( i , 0 , lazy.size() )
        cout<<i<<" . "<<lazy[i].first <<" , "<<lazy[i].second<<" | ";
      cout<<endl;
    }
};

int main()
{
  int n;
  scanf("%d\n",&n );
  SegmentTree st(n);
  return 0;
}
