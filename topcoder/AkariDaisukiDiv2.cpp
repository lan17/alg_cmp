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

int nCr( int n, int r )
{
	//return fact(n)/(fact(r)*fact(n-r));
	if(r==0 || r==n) return 1;
	if(r<0 || r>n || n<0) return 0;
	return nCr(n-1, r) + nCr(n-1, r-1);
}

class AkariDaisukiDiv2
{
	public:
	int countTuples(string S)
	{
		map<string,int> c;
		map<string,vector<int> > p;
		int N = S.size();
		for( int i = 1; i < N; ++i )
		{
			for( int j = 1; j + i < N-1; ++j )
			{
				string t = S.substr(i,j);
				c[t]++;
				p[t].push_back(i);
			}
		}
		int res = 0;
		FOREACH(i,c)
		{
			if( i->second >= 2 )
			{
				//cout<<i->first<<" : "<<i->second<<endl;
				res += nCr(i->second,2);

			}
		}
		return res;
	}
};
