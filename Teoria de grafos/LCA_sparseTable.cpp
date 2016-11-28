#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100010

#define foi( i , n , k )    for( int i = n ; i < k ; ++i )

vector < vector < int > > tree;
int parent[MAX_N];
int height[MAX_N];
int subTree_size[MAX_N];
int first_ocurrence[MAX_N];
vector < int > ocurrences;

int dfs( int u , int alt )
{
    first_ocurrence[u] = ocurrences.size();
    ocurrences.push_back(u);
    height[u] = alt;
    int v;
    subTree_size[u] = 1;
    for( int i = 0 ; i < tree[u].size() ; ++i )
    {
        v = tree[u][i];
        if( parent[u] == v )    continue;
        parent[v] = u;
        subTree_size[u] += dfs( v , alt + 1 );
        ocurrences.push_back(u);
    }
    return subTree_size[u];
}

vector < vector < int > > sparse_table_lca;

void build_sparse_lca( vector < int > &arr )
{
    int columns = floor( log2( arr.size() ) ) + 1;
    sparse_table_lca.assign( arr.size() , vector < int >( columns , -2 ) );
    for( int i = 0 ; i < arr.size() ; ++i ) sparse_table_lca[i][0] = arr[i];
    for( int j = 1 ; j < columns ; ++j )
        for( int i = 0 ; i < arr.size() && i + ( 1 << j ) - 1 < arr.size() ; ++i )
        {
            sparse_table_lca[i][j] = sparse_table_lca[i][j-1];
            if( height[ sparse_table_lca[i + ( 1 << ( j - 1 ) )][j-1] ] < height[ sparse_table_lca[i][j] ] )
                sparse_table_lca[i][j] = sparse_table_lca[i + ( 1 << ( j - 1 ) )][j-1];
        }
}

int query_sparse_lca( int i , int j )
{
    if( i > j ) swap( i , j );
    int len = j - i + 1;
    int k = floor( log2( len ) );
    int ans = sparse_table_lca[i][k];
    if( height[ sparse_table_lca[i + len - ( 1 << k )][k] ] < height[ans] )
        ans = sparse_table_lca[i + len - ( 1 << k )][k];
    return ans;
}

int query_lca( int u , int v )
{
    return query_sparse_lca( first_ocurrence[u] , first_ocurrence[v] );
}


int main()
{
    dfs( 0 , 0 );
    build_sparse_lca( ocurrences );
    return 0;
}

