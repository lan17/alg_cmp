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

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define print(x) cout<<#x<<" = "<<(x)<<endl;



using namespace std;

void printv(vector<int> & v)
{
	FOREACH( i,v)cout<<*i<<" ";
	cout<<endl;
}

class TheTournamentDivTwo {
	public:
	int find(vector <int> points) 
	{
		int ret = 0;
		FOR(i,points.size())
		{
			ret += points[i]/2;
			points[i]=points[i]%2;
		}
		cout<<ret<<endl;
		printv(points);
		while(true)
		{
			bool ok = true;
			FOR(i,points.size())
			{
				if( points[i]>0)
				{
					ok = false;
					bool bad = true;
					FORR(j,i+1,points.size()-1)
					{
						if( points[j]>0)
						{
							bad = false;
							--points[j];
							++ret;
							break;
						}
					}
					if( bad ) return -1;
					points[i]=0;
				}
			}
			if(ok)break;
		}
		return ret;
		
	}
};


// Powered by FileEdit
