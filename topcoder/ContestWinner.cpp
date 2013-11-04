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

typedef vector<string> vecs;
typedef vector<int> veci;
typedef unsigned long long ull;
typedef long long ll;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

class ContestWinner
{
	public:
	int getWinner(vector <int> events)
	{
		map<int,int> cnt;
		int ret = 0;
		int retm = 0;
		for(int i = 0; i < events.size(); ++i )
		{
			int p = events[i];
			cnt[events[i]] += 1;
			if( cnt[p] > retm )
			{
				ret = p;
				retm = cnt[p];
			}
		}
		return ret;
	}
};
