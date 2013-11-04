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

ull lim = 1e6+1;

vector<ull> squares(lim,0);

bool solve( ull n )
{
	bool yes = false;
	for( ull i = 0; i <= sqrt(n); ++i )
	{
		ull bs = n - squares[i];
		double bsd = sqrt(bs);
		if( abs(bsd-round(bsd)) < 1e-9 )
		{
			d_print(n<<":"<<i<<":"<<bsd);
			yes = true;
			break;
		}
	}
	return yes;
}

int main( int argc, char ** argv )
{
	int c;
	cin>>c;


	//set<ull> squares_set;
	for( ull i = 0; i < lim; ++i )
	{
		ull ii = i*i;
		squares[i] = ii;
		//squares_set.insert(ii);
	}

	for( int CASE = 1; CASE <= c; ++CASE )
	{
		ull n;
		cin>>n;
		d_print(n<<"======");

		printf(solve(n)?"Yes\n":"No\n");
	}
	for( int i = 0; i < 1000; ++i )
	{
		solve(i);
	}
}
