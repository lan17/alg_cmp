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


class ReadingBooks 
{
	public:
	int countBooks(vector <string> readParts)
	{
		int a,b,c;
		a = b = c = 0;
		FOREACH( part, readParts )
		{
			if( *part == "introduction" ) a++;
			if( *part == "story" ) b++;
			if( *part == "edification" ) c++;
		}
		int ret = 0;
		while( a != 0 && b != 0 && c != 0 )
		{
			ret++;
			a--;
			b--;
			c--;
			

		}
		return ret;
		
	}
};

/* Lev A Neiman's coding here */


// Powered by FileEdit


// Powered by FileEdit
