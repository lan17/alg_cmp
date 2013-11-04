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


class WordAbbreviation 
{
	public:
	vector <string> getAbbreviations(vector <string> words)
	 {
		int i = 0;
		bool done = false;
		while ( !done )
		{
			done = true;
			FOR( j, words.size() )
			{
				char tmp = words[j][i];
				FORR( k, j + 1, words.size() - 1 )
				{
					if( words[k].size() <= i )
					{
						done = true;
						break;
					}
					if( tmp == words[k][i] ) done = false; 

				}
				if( done ) break;

			}
			if( done ) break;
			i++;

		}
		i++;

		vector<string> ret;
		FOREACH( word, words )
		{
			ret.push_back( word->substr( 0, i ) );
		}
		return ret;
		
	}
};

/* Lev A Neiman's coding here */
