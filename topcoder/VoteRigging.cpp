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

#define vecs vector< string > 
#define veci vector< int >
#define vecsi vector<string>::iterator
#define vecii vector<int>::iterator

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

void printV( veci & s )
{
	FOREACH( i, s )
	{
		cout<<*i<<" ";
	}
	cout<<endl;
}

struct levLess : public binary_function< int, int, bool >
{
	bool operator( )( int x, int y ) { return x <= y; }
};

class VoteRigging 
{
	public:
	int minimumVotes(veci votes)
	{
		if( votes.size( ) == 0 ) return 0;
		int swaps = 0;
		vecii i = max_element( votes.begin( ), votes.end( ), levLess( ) );
		while( i != votes.begin( ) )
		{
			(*i) -= 1;
			(*votes.begin( )) += 1;
			swaps++;
			i = max_element( votes.begin( ), votes.end( ), levLess() );
			printV( votes );

		}
		return swaps;
	}
};

/* Lev A Neiman's coding here */


// Powered by FileEdit
