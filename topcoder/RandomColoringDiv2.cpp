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

#define d_print(x) { cerr << __LINE__ << " " << #x << " = " << x << endl; cerr.flush(); }

typedef vector<string> vecs;
typedef vector<int> veci;
typedef unsigned long long ull;
typedef long long ll;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

ull hash(ull R, ull G, ull B)
{
	return R + G * 100 + B * 100000;
}

class RandomColoringDiv2 
{
	public:
	int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) 
	{
		int rgb [3] ={0,0,0};
		int rgb2[3] ={startR,startG,startB};
		set<ull> nums;
		for( int R = 0; R < maxR; ++R )
		{
			for( int G = 0; G < maxG; ++G )
			{
				for( int B = 0; B < maxB; ++B )
				{
					rgb[0]=R;
					rgb[1]=G;
					rgb[2]=B;
					int diff = 0;
					bool good = true;
					for( int i = 0; i < 3; ++i )
					{
						if( abs(rgb[i]-rgb2[i]) > d2 )
						{
							good = false;
							break;
						}
						if( abs(rgb[i]-rgb2[i]) >= d1 )
						{
							++diff;
						}

					}
					if( good && diff > 0 )
					{
						nums.insert(hash(R,G,B));
					}
				}
			}
		}
		return nums.size();
	}
};
