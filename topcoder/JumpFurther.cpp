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

class JumpFurther
{
	public:
	int furthest(int N, int badStep)
	{
		int ret = 0;
		for( int j = 0; j <= N; ++j )
		{
			int curr = 0;
			bool good = true;
			for( int i = 1; i <= N; ++i )
			{
				if( i == j ) continue;
				int next = curr + i;
				if( next != badStep ) curr = next;
			}
			if( good )
				ret = max(ret, curr);
		}
		return ret;
	}
};
