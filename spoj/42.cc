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

int numDig( int x )
{
	int ret = 0;
	while( x > 0 )
	{
		x /= 10;
		++ret;
	}
	return ret;
}

int reverse( int x )
{
	int ret = 0;
	while( x > 0 )
	{
		ret *= 10;
		ret += x%10;
		x /= 10;
	}
	return ret;
}


int main( int argc, char ** argv )
{
	int N;
	cin>>N;
	for(int CASE = 1; CASE <=N; ++CASE )
	{
		int a,b;
		cin>>a>>b;
		cout<<reverse(reverse(a)+reverse(b))<<endl;
	}
}
