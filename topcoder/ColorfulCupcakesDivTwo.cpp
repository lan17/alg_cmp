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

int print_dbg = 1;

#define d_print(x) { if(print_dbg){  cerr << __LINE__ << " " << #x << " = " << x << endl; cerr.flush(); } }

typedef vector<string> vecs;
typedef vector<int> veci;
typedef unsigned long long ull;
typedef long long ll;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

#define MOD 1000000007
#define MAXC 50

ull mem[MAXC][MAXC][MAXC][3][3];

ull dfs( int A, int B, int C, int start, int end )
{
	ull memk = mem[A][B][C][start][end];
	if(memk!=-1)
		return memk;
	memk = 0;
	if( A < 0 || B < 0 || C < 0 )
		return 0;
	bool onlyone = (A + B + C == 1) && ( start == end );
	if( A && end == 0 )
	{
		if( onlyone ) return 1;
		memk = ( memk + ( dfs(A-1,B,C,start,1) % MOD + dfs(A-1,B,C,start,2) % MOD ) ) % MOD;
	}
	if( B && end == 1 )
	{
		if( onlyone ) return 1;
		memk = ( memk + ( dfs(A,B-1,C,start,0) % MOD + dfs(A,B-1,C,start,2) % MOD ) ) % MOD;
	}
	if( C && end == 2 )
	{
		if( onlyone ) return 1;
		memk = ( memk + ( dfs(A,B,C-1,start,0) % MOD + dfs(A,B,C-1,start,1) % MOD ) ) % MOD;
	}
	mem[A][B][C][start][end] = memk;
	return memk;
}

class ColorfulCupcakesDivTwo
{
	public:
	int countArrangements(string cupcakes)
	{
		memset(mem,-1,sizeof(mem));
		int A,B,C;
		A = B = C = 0;
		A = count(ALL(cupcakes),'A');
		B = count(ALL(cupcakes),'B');
		C = count(ALL(cupcakes),'C');
		ull ret = 0;
		for( int start = 0; start < 3; ++start )
		{
			for( int end = 0; end < 3; ++ end )
			{
				if( start == end ) continue;
				ret += dfs( A,B,C,start,end) % MOD;
				ret %= MOD;
			}
		}
		return ret;
	}
};


// Powered by FileEdit
