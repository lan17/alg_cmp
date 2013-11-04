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

#define HAS(x,cont) ((cont).find((x)) != (cont).end())

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define print(x) cout<<#x<<" = "<<(x)<<endl;

using namespace std;
class Xosceles
{
	public:
		vector<string> draw( int xCount )
		{
			int i;
			int c = -1;
			int counter = 0;
			for( i = 1; i <= xCount; i += 2)
			{
				counter += i;
				if( xCount == counter )
				{
					c = 1;
					break;
				}
			}
			if( c == -1 )
			{
				counter = 0;
				for( i= 2; i <= xCount; i += 2 )
				{
					counter += i;
					if( xCount == counter)
					{
						c = 2;
						break;
					}
				}
			}
			vector<string> ret;
			if( c== -1 )
				return ret;


		}
};
