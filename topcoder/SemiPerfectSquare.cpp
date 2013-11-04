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

class SemiPerfectSquare
{
	public:
	string check(int N)
	{
		for( int a = 1; a < N; ++a )
		{
			for( int b  = a + 1; b <=N; ++b )
				if( a * b * b == N ) return "Yes";
		}
		return "No";
	}
};


// Powered by FileEdit
