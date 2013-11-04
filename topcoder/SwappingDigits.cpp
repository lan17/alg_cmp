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


class SwappingDigits
{
	public:
	string minNumber(string num)
	{

		for( int i = 0; i < num.size(); ++i )
		{
			char minC = num[i];
			int p = i;
			for( int j = num.size() - 1; j > i; --j )
			{
				if( minC > num[j] )
				{
					if( i == 0 && num[j] == '0' )continue;
					minC = num[j];
					p = j;
				}
			}
			if( p != i )
			{
				char c = num[i];
				num[i] = num[p];
				num[p] = c;
				return num;
			}
		}
		return num;
	}
};
