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

class SpeedRadar 
{
	public:
	double averageSpeed(int minLimit, int maxLimit, vector <int> readings)
	{
		double average = 0.0;
		int violators = 0;
		int good = 0;
		FOREACH( i, readings )
		{
			if( *i >= minLimit && *i <= maxLimit )
			{
				good++;
				average += *i;
			}
			else
			{
				violators++;
			}
		}
		if( (double)violators / (double)readings.size( )  >= .10 ) { return 0.0; }
		else
		{
			return average / (double) good;
		}

		
	}
};

/* Lev A Neiman's coding here */


// Powered by FileEdit


// Powered by FileEdit
