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
#include <iomanip>

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

int zero_count( int x )
{
	int ret = 0;
	while( x > 0 )
	{
		if( x % 10 == 0 )
			++ret;
		else
			break;
		x /= 10;
	}
	return ret;
}

ull Z(int N)
{
	ull ret = 1;
	ull p = 0;
	for(ull i = 2; i <= N; ++i )
	{

	}
}


int main( int argc, char ** argv )
{
	int T;
	cin>>T;
	for(int CASE = 1; CASE <=T; ++CASE )
	{
		ull N;
		cin>>N;

	}
}
