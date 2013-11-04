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

map<int,map<int,int> > getDists( const vector <int> & x, const vector <int> & y )
{
	int N = x.size();
	map<int,map<int,int> > dists;
	for( int i = 0; i < N; ++i )
	{
		for( int j = i + 1; j < N; ++j )
		{
			dists[i][j] = dists[j][i] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
		}
	}
	return dists;
}

map<char,pair<int,int> > D;

bool op( char a, char b )
{
	int x, y;
	x = D[a].first + D[b].first;
	y = D[a].second + D[b].second;
	if( x == 0 && y == 0 ) return true;
	return false;
}

class AntsMeet
{
	public:
	int countAnts(vector <int> x, vector <int> y, string direction)
	{
		D['N'] = make_pair(0,1);
		D['S'] = make_pair(0,-1);
		D['E'] = make_pair(1,0);
		D['W'] = make_pair(-1,0);

		int N = x.size();
		map<int,map<int,int> > dists = getDists( x, y );
		vector<bool> active(N,true);
		while(true)
		{
			for( int i = 0; i < N; ++i )
			{
				cout<<i<<": "<<x[i]<<","<<y[i]<<endl;

				if( ! active[i] )
					continue;
				x[i] += D[direction[i]].first;
				y[i] += D[direction[i]].second;
				for( int j = i + 1; j < N; ++j )
				{
					if( !active[j] ) continue;
					if( x[i] == x[j] && y[i] == y[j] )
					{
						active[i] = active[j] = false;
					}
				}
			}
			for( int i = 0; i < N; ++i )
			{
				for( int j = i + 1; j < N; ++j )
				{
					if( !( active[i] && active[j] ))
						continue;
					if( x[i]==x[j] && y[i]==y[j])
						active[i]=active[j]=false;
				}
			}

			map<int,map<int,int> > new_dists = getDists(x,y);
			bool done = true;
			for( int i = 0; i < N; ++i )
			{
				for( int j = i + 1; j < N; ++j )
				{
					if( active[i] && active[j] )
					{
						int d = new_dists[i][j] - dists[i][j];
						if( d < 0 )
						{
							done = false;
							break;
						}
					}
				}
				if( !done ) break;
			}
			if( done )
				break;
			dists = new_dists;

		}

		int ret = 0;
		for( int i = 0; i <N ; ++i )
		{
			ret += active[i] ? 1 : 0;
		}
		return ret;
	}
};
