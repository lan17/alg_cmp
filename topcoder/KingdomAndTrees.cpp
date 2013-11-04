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

class KingdomAndTrees
{
	public:
	int minLevel(vector <int> h)
	{
		int ret = 0;
		veci hh = h;
		while(true)
		{
			for(int i = 0; i < h.size(); ++i )
			{
				ret = max(ret, abs(hh[i]-h[i]));
			}
			bool done = true;
			for( int i = 0; i < h.size(); ++i )
			{
				int maxj = -1;
				int jj = -1;
				for( int j = i + 1; j < h.size(); ++j )
				{
					if( h[i] >= h[j] )
					{
						int dd = abs(h[i]-h[j]);
						if( dd > maxj )
						{
							jj = j;
							maxj = dd;
						}
						done = false;
					}
				}
				if(jj == -1)
					continue;
				//if( maxj < ret )
				{
				//	h[jj] = h[i] + 1;
				}
				//else
				{
					while(true)
					{
						if( h[i] < h[jj] )
							break;
						if( h[i] > 1 )
						{
							if( i > 0 && h[i-1] < h[i] - 1 )
							{
								--h[i];
							}
							else if( i == 0 )
							{
								--h[i];
							}
						}
						if( h[i] < h[jj] )
							break;
						++h[jj];
					}
				}
				for( int k = 0; k < h.size(); ++k )
				{
					cout<<h[k]<<", ";
				}
				cout<<endl<<"==============="<<endl;
			}
			if( done )
				break;
		}
		for(int i = 0; i < h.size(); ++i )
		{
			cout<<h[i]<<endl;
			ret = max(ret, abs(hh[i]-h[i]));
		}
		return ret;
	}
};
