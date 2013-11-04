#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>

using namespace std;

int print_dbg = 1;

#define d_print(x) { if(print_dbg){  cerr << __LINE__ << " " << #x << " = " << x << endl; cerr.flush(); } }

typedef vector<string> vecs;
typedef vector<int> veci;
typedef unsigned long long ull;
typedef long long ll;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

class MagicNaming {
	public:
	int maxReindeers(string m )
	{
		int ans = 1;
		int n = m.size();
		vector<vector<int> > dp( n, vector<int>(n,-1e9));
		for( int i = 0; i < n; ++i )
		{
			for( int j = 0; j < n; ++j )
			{
				if( i == 0 ) dp[i][j] = 1;
				for( int k = 0; k < i; ++k )
				{
					string x,y;
					x = m.substr(k,i-k);
					y = m.substr(i,j-i+1);
					if( (x+y ) <= (y+x) )
					{
						dp[i][j] = max( dp[i][j], dp[k][i-1] + 1 );
					}
				}
				if( j == n - 1 ) ans = max( dp[i][j], ans );
			}
		}
		return ans;
	}
};
