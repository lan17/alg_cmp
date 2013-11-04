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
typedef unsigned int ui;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

const int lim = 1e6+1;
map<int,ui> mem;

ui maxN = 0;

ui count(ui n)
{
	if( n == 1 ) return 1;
	maxN = max(maxN,n);
	map<int,ui>::iterator retI = mem.find(n);
	if( retI != mem.end() ) return retI->second;
	ui ret = 0;
	ret = n % 2 != 0 ? count(3*n+1) : count(n/2);
	ret += 1;
	mem[n] = ret;
	return ret;
}

int main( int argc, char ** argv )
{
	for( int i = 1; i < lim; ++i )
	{
		ui c = count(i);
	}
	while(cin.good())
	{
		int a,b;
		cin>>a>>b;
		ui answer = 0;
		for( int i = a; i <= b; ++i )
		{
			answer = max(answer,count(i));
		}
		cout<<a<<" "<<b<<" "<<answer<<endl;
	}
}
