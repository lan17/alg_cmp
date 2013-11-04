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
#include <queue>

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

#define INF 1000


template <typename T>
ostream & operator <<(ostream & os, const vector<T> & v )
{
	os<<"[ ";
	for( int i = 0; i < v.size(); ++i ) os<<v[i]<<", ";
	os<<"]";
	return os; 
}

class Egalitarianism
{
	public:
	int maxDifference(vector <string> isFriend, int d)
	{
		int n = isFriend.size();
		d_print(n);
		vector<int> dist(n,INF);
		queue<int> Q;
		vector<bool> vis(n,false);

		int max_path = 0;

		// dijkstra search from each possible friend.
		for( int i = 0; i < n; ++i ) 
		{
			d_print("searching for love for "<<i);
			dist.assign(n,INF);
			dist[i] = 0;
			vis.assign(n,false);
			Q.push(i);
			while(!Q.empty())
			{

				d_print(vis);
				int u = Q.front();
				Q.pop();
				d_print(u);
				if( vis[u] ) continue;
				vis[u] = true;
				d_print("popped "<<u<<" off of que");
				for( int v = 0; v < n; ++v )
				{
					if( v == u ) continue;
					if( isFriend[u][v] == 'N' ) continue;
					if( vis[v] ) continue;
					int d = dist[u] + 1;
					if( d < dist[v] )
					{
						dist[v] = d;
					}
					d_print("putting friend "<<v<<".  his new distance is "<<dist[v]);
					Q.push(v);
				}
			}
			for( int j = 0; j < n; ++j )
			{
				max_path = max(max_path,dist[j]);
			}
			d_print(dist);
			
		}
		if( max_path > n ) return -1;
		return max_path*d;
	}
};


// Powered by FileEdit
