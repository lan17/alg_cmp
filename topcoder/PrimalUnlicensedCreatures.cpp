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


class PrimalUnlicensedCreatures
{
	public:
	int maxWins(int initialLevel, vector <int> grezPower)
	{
		sort(ALL(grezPower));
		int x = initialLevel;
		int i;
		for( i = 0; i < grezPower.size(); ++i )
		{
			if( x <= grezPower[i])break;
			x += grezPower[i]/2;
		}
		return i;
	}
};
