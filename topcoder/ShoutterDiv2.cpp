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



class ShoutterDiv2
{
	public:
	int count(vector <int> s, vector <int> t)
	{
		int ret = 0;
		for( int i = 0; i < s.size(); ++i )
		{
			int si = s[i];
			int ti = t[i];
			for( int j = i + 1; j < s.size(); ++j )
			{
				int sj = s[j];
				int tj = t[j];
				if( sj >= si && sj <= ti )
					++ret;
				else if( tj >= si && tj <= ti )
					++ret;
				else if( si >= sj && si <= tj )
					++ret;
				else if( ti >= sj && ti <= tj )
					++ret;
			}
		}
		return ret;

	}
};
