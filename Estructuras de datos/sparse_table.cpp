#include <bits/stdc++.h>

using namespace std;

// RMQ Sparse table
vector < vector < int > > sparse_table;

// Build sparse table using array arr, O( nlog(n) )
void build_sparse( vector < int > &arr )
{
  int columns = floor( log2( arr.size() ) ) + 1;
  sparse_table.assign( arr.size() , vector < int > ( columns , - 2 ) );
  for( int i = 0 ; i < sparse_table.size() ; ++i )  sparse_table[i][0] = i;
  for( int j = 1 ; j < columns ; ++j )
    for( int i = 0 ; i + ( 1 << j ) <= sparse_table.size() ; ++i )
    {
      sparse_table[i][j] = sparse_table[i][j-1];
      if( arr[ sparse_table[ i + ( 1 << ( j - 1 ) ) ][j-1] ] < arr[ sparse_table[i][j] ] )
        sparse_table[i][j] = sparse_table[ i + ( 1 << ( j - 1 ) ) ][j-1];
    }
}

// Make queries on sparse table from i to j, inclusive , O(1)
// Use only once you build sparse_table
int query( vector < int > &arr , int i , int j )
{
  int len = j - i + 1;
  int k = floor( log2(len) );
  int min1 = sparse_table[i][k];
  int min2 = sparse_table[i + len - ( 1 << k )][k];
  return min( arr[min1] , arr[min2] );
}

int main()
{
  return 0;
}
