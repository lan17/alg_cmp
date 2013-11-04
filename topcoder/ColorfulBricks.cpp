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

class ColorfulBricks
{
	public:
	int countLayouts(string bricks)
	{
		sort(ALL(bricks));
		map<char,int> nums;
		for( int i = 0; i < bricks.size(); ++i )
		{
			nums[bricks[i]] += 1;
		}
		if( nums.size() > 2 )
			return 0;
		if( nums.size() == 1 )
			return 1;
		return 2;
	}
};
