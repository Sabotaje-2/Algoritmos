const int INF =  1e9;
typedef struct Node * pNode ;
struct Node
{
	int key ,prior,cnt ;
  pNode left, right;
  Node()
  {
  	prior = rand() % INF;
    key = 0;
    left = right = NULL;
  	cnt = 1;
  }
  Node( int _val )
  {
  	cnt = 1;
  	prior = rand() % INF;
    key = _val;
    left = right = NULL;
  }
};
 
struct Treap
{
	pNode root;
	Treap()
	{
		root = NULL;
	}
	Treap( pNode n )
	{
		root = n;
	}
 	int cnt( pNode n )
  {
  	return (n)?n->cnt:0;
  }
  void upd_cnt( pNode n )
  {
  	if( n )
    	n->cnt = cnt( n->left ) + cnt( n->right ) + 1;
  }
  void merge( pNode& t , pNode l , pNode r )
  {
  	if( !l ) return void( t = r );
    if( !r ) return void( t = l );
    if( l->prior > r->prior )
    	merge( l->right , l->right , r ) , t = l;
    else
    	merge( r->left , l , r->left ) , t = r;
    upd_cnt( t );
  }
  void split( pNode t , pNode& l , pNode& r , int k  )
  {
  	if( !t ) return void( l = r = NULL );
    if( k < t->key )
			split( t->left  , l , t->left , k  ) ,r  = t ;
    else
    	split( t->right , t->right , r , k ) , l = t ;
   upd_cnt( t );
  }
 	void insert( pNode& t , pNode n )
  {
  	if( !t ) return void( t = n );
    if( n->prior > t->prior  )
    	split( t , n->left , n->right , n->key ), t = n  ;
    else
    	insert( n->key < t->key ? t->left : t->right , n );
    upd_cnt( t );
  }
	void erase( pNode& t , int k )
	{
		if( !t ) return;
		if( k == t->key )
			merge( t , t->left , t->right );
		else erase( t->key > k ? t->left : t->right , k );
		upd_cnt( t );
	}
	void erase( int value )
	{
		erase( root , value );
	}
	bool find( pNode t , int val )
	{
		if( !t ) return false;
		if( val == t->key )
			return true;
		return find( t->key > val ? t->left : t->right , val );
	}
  void insert( int val )
  {
		if( !find( root ,  val ) )
  		insert( root  , new Node( val ) );
  }
	pNode kth( pNode t , int k, int add = 0  )
	{
		if( !t ) return NULL;
		int curr_k = cnt( t->left ) + add +1;
		if( k == curr_k )
			return t;
		return  kth( curr_k > k ? t->left : t->right , k , curr_k > k ? add :  curr_k );
	}
	pNode kth( int k )
	{
		if( k <= 0 || k> cnt(root) ) return NULL;
		return kth( root , k );
	}
	int count( pNode t , int k )
	{
		if( !t ) return 0;
		if( t->key < k )
			return cnt( t->left ) +1 + count(t->right,k);
		return count( (t->key >= k) ? t->left : t->right , k );
	}
	int count( int k )
	{
		return count( root , k );
	}
};
 
