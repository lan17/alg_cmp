#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>

using namespace std;

//
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define VI vector<int>
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
//
#define rep(i,b) for(int i=(0);i<(b);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(__typeof((b).begin()) a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>
template<class T> inline void checkmin( T &a, T b )
{
	if( b < a )
		a = b;
}
template<class T> inline void checkmax( T &a, T b )
{
	if( b > a )
		a = b;
}

int cond = (ll) 1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

int maxlev;
char buf[ 40 ][ 40 ];
int choises[ 40 ];
int n;
ll ha[ 400 ];
set<ll> zb[ 40 ];
ll it;

void solve( int clev, vector<int> can, int digi, int last )
{
	if( clev == maxlev )
	{
		db(it);
		rep (i, n)
		{
			rep (j, 10)
				if( can[ i ] & (1 << j) )
					cout << j;
		}
		cout << endl;
		//    exit(0);
	}

	fo (j, last+1, n)
	{
		if( j == n && digi == 0 )
		{
			solve( clev + 1, can, choises[ clev + 1 ], -1 );
		}
		else if( j < n )
		{
			if( digi > 0 )
			{
				int canj = can[ j ];
				can[ j ] &= (1 << (buf[ clev ][ j ] - '0'));
				if( can[ j ] )
				{
					solve( clev, can, digi - 1, j );
				}
				can[ j ] = canj;
			}
			can[ j ] &= ~(1 << (buf[ clev ][ j ] - '0'));
			if( can[ j ] == 0 )
				break;
		}
	}
}

void _main()
{
	ha[ 0 ] = 1;
	fo (i, 1, 400-1)
		ha[ i ] = ha[ i - 1 ] * ((int) 2e9 + 11);
	n = 16;
	db(n);
	for( maxlev = 0;; maxlev++ )
	{
		gets( buf[ maxlev ] );
		if( buf[ maxlev ][ 0 ] == 0 )
			break;
		if( !isdigit( buf[ maxlev ][ 0 ] ) )
			break;
		sscanf( buf[ maxlev ] + n + 2, "%d", &choises[ maxlev ] );
	}
	vector<int> can( n, 0 );
	//rep (i, maxlev) rep (j, n) can[j] |= 1 << (buf[i][j] - '0');
	rep (j, n)
		can[ j ] |= (1 << 10) - 1;
	db("");
	solve( 0, can, choises[ 0 ], -1 );
	db("bug");

}

int main( int argc, char ** argv )
{
	string p = "../gcj/source/" + string( "" ) + argv[ 0 ][ strlen( argv[ 0 ] ) - 1 ];
	//    if (argc >= 2 && strcmp(argv[1], "q") != 0) { freopen(argv[1],"r",stdin);}

	rep (i, argc)
		if( strcmp( argv[ i ], "1n" ) == 0 )
		{
			freopen( "1.in", "r", stdin);
		}
	rep (i, argc)
		if( strcmp( argv[ i ], "2n" ) == 0 )
		{
			freopen( "2.in", "r", stdin);
		}
	rep (i, argc)
		if( strcmp( argv[ i ], "3n" ) == 0 )
		{
			freopen( "3.in", "r", stdin);
		}
	rep (i, argc)
		if( strcmp( argv[ i ], "4n" ) == 0 )
		{
			freopen( "4.in", "r", stdin);
		}
	rep (i, argc)
		if( strcmp( argv[ i ], "5n" ) == 0 )
		{
			freopen( "5.in", "r", stdin);
		}

	rep (i, argc)
		if( strcmp( argv[ i ], "s0" ) == 0 )
		{
			freopen( (p + "-small-0.in").c_str(), "r", stdin);
			freopen( (p + "-small-0.out").c_str(), "w", stdout);
		}
	rep (i, argc)
		if( strcmp( argv[ i ], "s1" ) == 0 )
		{
			freopen( (p + "-small-1.in").c_str(), "r", stdin);
			freopen( (p + "-small-1.out").c_str(), "w", stdout);
		}
	rep (i, argc)
		if( strcmp( argv[ i ], "s2" ) == 0 )
		{
			freopen( (p + "-small-2.in").c_str(), "r", stdin);
			freopen( (p + "-small-2.out").c_str(), "w", stdout);
		}
	rep (i, argc)
		if( strcmp( argv[ i ], "l0" ) == 0 )
		{
			freopen( (p + "-large-0.in").c_str(), "r", stdin);
			freopen( (p + "-large-0.out").c_str(), "w", stdout);
		}
	rep (i, argc)
		if( strcmp( argv[ i ], "q" ) == 0 )
			cond = 1 << 30;
	db(argc);
	_main();
	return 0;
}
