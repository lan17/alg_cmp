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


#define PI 3.1415926535897932384626433832795028

class MinimalTriangle
{
	public:
	double maximalArea(int length)
	{
		double l = (double)length;
		double x = sin(PI/6)*l;
		double y = cos(PI/6)*l;
		return y*x;
	}
};
