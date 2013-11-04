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

class BlackAndWhiteSolitaire
{
	int count( string & c, char s )
	{
		int ret = 0;
		for( int i = 0; i < c.size(); ++i )
		{
			if( c[i] != s )
				++ret;
			s = s == 'B' ? 'W':'B';
		}
		return ret;
	}

	public:
	int minimumTurns(string cardFront)
	{
		return min( count(cardFront,'B'), count(cardFront,'W'));
	}
};
