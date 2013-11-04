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

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

int S( int n )
{
	int ret = 0;
	int t = n;
	while( t > 0 )
	{
		int digit = t % 10;
		ret += digit * digit;
		t /= 10;
	}
	return ret;
}

bool T( int x, int n )
{
	int t = S( x );
	if( t == n ) return true; 
	set<int> numbers;
	numbers.insert( t );
	while( 1 )
	{
		t = S( t );
		if( t ==  n ) return true; 
		pair< set<int>::iterator, bool > a = numbers.insert( t );
		if( !a.second ) return false;
	}
}

class SquareDigits 
{
	public:
	int smallestResult(int param0)
	{
		if( param0 == 0 ) { return 0; }
		int x = 0;
		while( 1 )
		{
			x++;
			if( T( x, param0 ) ) { return x; }
		}
		
	}
};

/* Lev A Neiman's coding here */
