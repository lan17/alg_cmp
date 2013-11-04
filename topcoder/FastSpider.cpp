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

#define vecs vector< string > 
#define veci vector< int >
#define vecsi vector<string>::iterator
#define vecii vector<int>::iterator

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define pnt(x) cout<<#x<<" = "<<(x)<<endl;

using namespace std;

class FastSpider 
{
	public:
	int findTime(double spiderSpeed, double manSpeed)
	{
		int t = (int)floor((exp(manSpeed/spiderSpeed)-1)/manSpeed);
		return t;
		
	}
};

/* Lev A Neiman's coding here */
