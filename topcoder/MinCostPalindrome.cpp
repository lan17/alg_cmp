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


class MinCostPalindrome {
	public:
	int getMinimum(string s, int oCost, int xCost) 
	{
		int res = 0;
		for( size_t i = 0; i < s.size()/2; ++i )
		{
			size_t j = s.size()-i-1;
			if( s[i] == s[j] )
				if( s[i] == '?' )
					res += 2*min(oCost,xCost);
			if( s[i] != s[j] )
			{
				if( s[i] != '?' && s[j] != '?' ) return -1;
				if( s[i] == '?' )
				{
					res += s[j] == 'x' ? xCost : oCost;
				}
				if( s[j] == '?' )
				{
					res += s[i] == 'x' ? xCost : oCost;
				}
			}

		}
		return res;
	}
};
