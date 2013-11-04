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

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))


struct cmp
{
	bool operator()(int a, int b)
	{
		if( a % 10 == 0 && b % 10 == 0 )
			return a < b;
		return a % 10 == 0;
	}
};

class Cut {
	public:
	int getMaximum(vector <int> e, int maxCuts)
	{
		cmp c;
		sort(ALL(e),c);
		while(true)
		{
			bool ok = true;
			size_t ss = e.size();
			sort(ALL(e),c);
			for(size_t i = 0; i < ss; ++i )
			{
				if( e[i] <= 10 ) continue;
				if( maxCuts >  0 )
				{
					int nv = e[i]-10;
					e[i] = 10;
					e.push_back(nv);
					--maxCuts;
					ok = false;
					break;
				}
			}
			if( ok ) break;
		}
		int ret = 0;
		for(size_t i = 0; i < e.size(); ++i )
			if( e[i] == 10 ) ++ret;
		return ret;
	}
};
