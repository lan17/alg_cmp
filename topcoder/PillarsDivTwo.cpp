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

class PillarsDivTwo
{
	public:
	double maximalLength(vector <int> height, int w)
	{
		int N =  height.size();
		vector<vector<double> > lengths(101,vector<double>(101,0));
		for( int i = 1; i <= 100; ++i )
		{
			for( int j = 1; j <= 100; ++j )
			{
				lengths[i][j] = sqrt(pow(double(w),2)+pow(double(i-j),2));
			}
		}
		vector<vector<double> > mem(N,vector<double>(101,0));
		for( int i = 1; i < N; ++i )
		{
			for( int j = 1; j <= height[i]; ++j )
			{
				double m = 0;
				for( int k = 1; k <= height[i-1]; ++k )
				{
					m = max(m,mem[i-1][k] + lengths[j][k]);
				}
				mem[i][j] = m;
			}
		}
		double ret = 0;
		for( int i = 1; i <= height[N-1]; ++i )
		{
			ret = max(ret, mem[N-1][i]);
		}
		return ret;

	}
};
