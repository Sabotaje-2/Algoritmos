struct DisjointSets
{
  vector < int > parent , rank;

  DisjointSets( int n )
  {
    rank.assign( n , 1 );
    parent.assign( n , 0 );
    for( int i = 1 ; i < n ; ++i )
      parent[i] = i;
  }

  int find_parent( int k )
  {
    return parent[k] == k ? k : parent[k] = find_parent( parent[k] );
  }

  void unir( int i , int j )
  {
    int p = find_parent(i) , q = find_parent(j);
    if( p == q )  return;
    if( rank[p] > rank[q] )
    {
      rank[p] += rank[q];
      parent[q] = p;
    }
    else
    {
      rank[q] += rank[p];
      parent[p] = q;
    }
  }

  bool connected( int i , int j )
  {
    return find_parent(i) == find_parent(j);
  }

};
