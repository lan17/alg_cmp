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

int spread(const string & a )
{
	int ret = 0;
	for( int i = 0; i < a.size(); ++i )
	{
		int j = i + 1;
		while( j < a.size() && a[i] == a[j] )
		{
			++j;
		}
		ret = max(ret, j-i);
		i=j;
	}
	return ret;
}

void swap( string & a, int i, int j )
{
	char c = a[i];
	a[i] = a[j];
	a[j] = c;
}

class ColorfulChocolates
{
	public:
	int maximumSpread(string c, int m)
	{
		int N = c.size();
		int ret = 0;
		for( int i = 0; i < N; ++i )
		{
			vector<int> rm;
			int q = 1;
			for( int j = i + 1; j < N; ++j )
			{
				if( c[i] == c[j] )
				{
					int reqmov = j-i-q;
					rm.push_back(reqmov);
					++q;
				}
			}
			q = 1;
			for( int j = i - 1; j >= 0; --j )
			{
				if( c[i] ==c[j] )
				{
					int reqmov = i-j-q;
					rm.push_back(reqmov);
					++q;
				}
			}
			int mm = m;
			sort(ALL(rm));
			int cnt=1;
			for( int j = 0; j < rm.size() && rm[j] <= mm; ++j )
			{
				mm -= rm[j];
				++cnt;
			}
			ret = max(ret,cnt);
		}
		return ret;
	}
};
