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

class MonotoneSequence 
{
	public:
	int longestMonotoneSequence(vector <int> seq)
	{
		int md, mi;
		md=mi=1;
		int td,ti;
		td=ti=1;
		FOR( i, seq.size( ) - 1 )
		{
			if( seq[i] < seq[i+1] )
			{
				ti++;
				td = 1;
			}
			else if( seq[i] > seq[i+1] )
			{
				td++;
				ti = 1;
			}
			else if( seq[i] == seq[i+1] )
			{
				ti = 1;
				td = 1;
			}
			if( mi < ti ){ mi=ti; }
			if( md < td ){ md=td; }
		}
		return max( mi, md );
	}
};

/* Lev A Neiman's coding here */


// Powered by FileEdit
