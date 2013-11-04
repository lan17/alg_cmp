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

int print_dbg = 0; 

#define d_print(x) { if(print_dbg){  cerr << __LINE__ << " " << #x << " = " << x << endl; cerr.flush(); } }

typedef vector<string> vecs;
typedef vector<int> veci;
typedef unsigned long long ull;
typedef long long ll;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

template <typename T>
ostream & operator <<(ostream & os, const vector<T> & v )
{
	os<<"[ ";
	for( int i = 0; i < v.size(); ++i ) os<<v[i]<<", ";
	os<<"]";
	return os; 
} 

ll fact(int n)
{
	d_print(n);
	if( n == 1 ) return 1;
	return n * fact(n-1);
}

vector<vector<ll> > mem( 100, vector<ll>(100,-1) );

ll choose( int n, int k ) 
{
	if( mem[n][k] != -1 ) return mem[n][k]; 
	if( k == 0 ) return 1;
	if( n == 0 ) return 0;
	ll ret = choose(n-1,k-1) + choose(n-1,k);
	mem[n][k] = ret;
	return ret;
}

ll compute( const vector<int> & counts, vector<int> & kp )
{
	d_print( kp);
	ll ret = 1;
	for( int i = 0; i < counts.size(); ++i )
	{
		ret *= choose( counts[i], kp[i] );
	}
	return ret;
}

vector<vector<ll> > dp( 100, vector<ll>(100,-1) );

ll compute( vector<int> & counts, int site, int K )
{
	if( site == counts.size() ) return K == 0;
	ll & ret = dp[site][K];
	if( ret != -1 ) return ret;
	ret = 0;
	for( int i = 1; i <= K; ++i )
	{
		ret += choose( counts[site], i ) * compute( counts, site + 1, K - i );
	}
	return ret;
}


class Excavations2
{
	public:
	long long count(vector <int> kind, vector <int> found, int K)
	{
		vector<int> counts(found.size(),0);
		for( int i = 0; i < found.size(); ++i )
			FOREACH( k, kind )
				if( found[i] == *k ) counts[i]++;
		d_print(counts);
		vector<int> kp;
		return compute( counts, 0, K );
	}
};
