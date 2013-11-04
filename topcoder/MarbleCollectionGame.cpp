#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <cstdio>
#include <valarray>      
#include <ext/hash_set> 
#include <ext/hash_map>
#include "float.h"

#define FMAX DBL_MAX
#define FMIN DBL_MIN

#define ld long double
#define ll long long
#define ull unsigned long long

#define vecs vector< string > 
#define veci vector< int >
#define vecsi vector<string>::iterator
#define vecii vector<int>::iterator
#define vec vector

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define pnt(x) cout<<#x<<" = "<<(x)<<endl;

using namespace std;

int ctoi( const char & c )
{
	if( c == 'U' ) return 0;
	if( c == 'L' ) return 0;
	if( c == '#' ) return 0;
	return c-48;
}

bool canMove( const vector< string > & board, int i, int j )
{
	//cout<<i<<"   "<<j<<endl;
	if ( i < 0 || j < 0 || i >= board.size( ) || j >= board[0].size() ) { return false; }
	if( board[i][j] == '#' ) { return false; }
	return true;
}

void  possibleNextMoves( const vector< string > & board, int i, int j, vec< pair< int, int > > & ret )
{
	if( !canMove( board, i, j ) ) return;
	if( canMove( board, i + 1, j ) ) ret.push_back( make_pair( i + 1, j ) );
	if( canMove( board, i, j + 1 ) ) ret.push_back( make_pair( i, j + 1 ) );
	char this_c = board[ i ][ j ];
	if( this_c == 'U' && canMove( board, i - 1, j ) ) ret.push_back( make_pair( i-1, j ) );
	if( this_c == 'L' && canMove( board, i, j - 1 ) ) ret.push_back( make_pair( i, j - 1 ) );
}

void possiblePrevMoves( const vector< string > & board, int i, int j, vec< pair< int, int > > & ret )
{ 
	if( !canMove( board, i, j ) ) return;
	if( canMove( board, i-1, j ) ) ret.push_back( make_pair( i-1, j ) );
	if( canMove( board, i, j - 1 ) ) ret.push_back( make_pair( i, j -1 ) );
	if( canMove( board, i, j + 1 )  && board[ i ][ j + 1 ] == 'L' ) ret.push_back( make_pair( i, j + 1 ) );
	if( canMove( board, i - 1, j )  && board[ i -1 ][ j ] == 'U' ) ret.push_back(  make_pair( i - 1, j ) );
}

struct Node
{
	int dp;
	bool dped;
	int val;
	int i, j, n;
	bool eliminated;
	set< Node * > next;
};

bool DFS( Node * root, const Node * node, map< Node *, bool > & visited )
{
	//cout<<"OMG DFS: "<<node->n<<", "<<root->n<<endl;
	if( visited[root] && root == node ) return true;
	if( visited[root] ) return false;
	
	visited[root] = true;
	bool ret = false;
	FOREACH( next, root->next )
	{
		bool n =  DFS( *next, node, visited );
		ret = ret || n;
	}
	return ret;
}

// replace all edges pointing to node a with node b
// that is eliminate node a;
void replaceNode( Node * a, Node * b, vec< vec< Node * > > & nodez )
{
	b->val += a->val;
	a->eliminated = true;
	FOREACH( n, a->next )
	{
		b->next.insert( *n );
	}
	FOREACH( l, nodez )
	{
		FOREACH( node, *l )
		{
			set< Node * > :: iterator loc = (*node)->next.find( a );
			if( loc == (*node)->next.end( ) ) continue;
			(*node)->next.erase( loc );
			(*node)->next.insert( b );
		}
	}
}

void printLoops( vec<vec<bool > > & loops )
{
	cout<<"   ";
	FOR( i, loops.size( ) ) cout<<i<<" ";
	cout<<endl;
	FOR( i, loops.size( ) )
	{
		cout<<i<<": ";
		FOR( j, loops.size( ) )
		{
			cout<<loops[i][j]<<" ";
		}
		cout<<endl;
	}
}

void simplifyGraph( vec<Node*> & linear, vec<vec< Node * > > & nodez )
{
	vec< vec<bool> > loops( linear.size(), vec<bool> ( linear.size( ), false ) );  // if i, j is true then node i connects to node j.
	FOR( i, linear.size( ) )
	{
		map<Node*, bool > visited;
		if( DFS( linear[ i ], linear[ i ], visited ) ) loops[ i ][ i ] = true;
		visited.erase( visited.find( linear[i] ) );
		FOREACH( node, visited )
		{
			loops[ i ][ node->first->n ] = true;
		}
	}
	//printLoops( loops );
	FOR( i, linear.size( ) )
	{
		if( linear[i]->eliminated ) continue;
		if( loops[ i ][ i ] ) // if this is true then node i connects to node i and is in a loop
		{
			FORR( j, 1, linear.size( )-1 )
			{
				if( j != i && loops[ i ][ j ] && loops[ j ][ j ] && loops[ j ][ i ] && ! linear[ j ]->eliminated ) // if this is true then node j is part of node i's loop
				{
					//cout<<"FUSING: "<<j<<" WITH: "<<i<<endl;
					replaceNode( linear[ j ], linear[ i ], nodez ); 
				}
			}
		}
	}
	FOREACH( node, linear )
	{
		(*node)->next.erase( *node );
	}

}


void printGraph( const vec< Node * > & linear )
{
	FOREACH( node, linear )
	{
		cout<<(*node)->n<<": ";
		FOREACH( next, (*node)->next )
		{
			cout<<(*next)->n<<" ";
		}
		cout<<endl;
	}
}

class MarbleCollectionGame 
{
	private:

		int DP2( Node * cell )
		{
			if( cell->dped ) return cell->dp;
			if( cell->next.size( ) == 0 ) return cell->val;
			cell->dped = true;
			int m = -1;
			FOREACH( next, cell->next )
			{
				m = max( m, DP2( *next ) );
			}
			cell->dp = m + cell->val;
			return cell->dp;
		}

	public:
	int collectMarble(vector <string> board)
	{
		int n = board.size( );
		int m = board[0].size( );
		vec< vec< Node * > > nodez( n, vec<Node*> ( m, new Node )  );
		vec< Node * > linear( n * m, new Node  );
		int counter = 0;
		FOR( i, n ) FOR( j, m ) 
		{
			nodez[ i ][ j ] = new Node( );
			nodez[ i ][ j ]->n = counter;
			nodez[ i ][ j ]->dped= false;
			nodez[ i ][ j ]->eliminated = false;
			linear[ counter ] = nodez[ i ][ j ];
			counter++;
		}
		FOR( i, n )
		{
			FOR( j, m )
			{
				if( canMove( board, i, j ) )
				{
					nodez[ i ][ j ]->val =  nodez[ i ][ j ]->dp = ctoi( board[ i ][ j ] );
					nodez[ i ][ j ]->i = i;
					nodez[ i ][ j ]->j = j;
					vec< pair<int,int> > next_moves;
					possibleNextMoves( board, i, j, next_moves );
					FOREACH( next, next_moves )
					{
						nodez[ i ][ j ]->next.insert( nodez[ next->first ][ next->second ] );
					}
				}
			}
		}
		//printGraph(linear);
	   simplifyGraph( linear, nodez );
	   /*
		DP2( linear[0] );
		int ret = -1;
		FOREACH( n, linear )
		{
			if( !(*n)->eliminated && (*n)->val > ret ) ret = (*n)->val;
		}

		return ret;
		*/
		return DP2( linear[0] );
		//return 0;
	}
};

/* Lev A Neiman's coding here */


// Powered by FileEdit


// Powered by FileEdit


// Powered by FileEdit


// Powered by FileEdit


// Powered by FileEdit
