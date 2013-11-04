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

template<class T>
ostream & operator <<(ostream & os, const vector<T> & v )
{
	os<<"[ ";
	for( int i = 0; i < v.size(); ++i )
	{
		os<<v[i]<<", ";
	}
	os<<"]";
	return os;
}

template<class T>
ostream & operator <<(ostream & os, const vector<T> * v )
{
	os<<*v;
	return os;
}

template<class K, class V>
ostream & operator <<(ostream & os, const map<K,V> & a )
{
	os<<"{ ";
	FOREACH(i,a)
	{
		os<<i->first<<": "<<i->second<<", ";
	}
	os<<"}";
	return os;
}

template<class K, class V>
ostream & operator <<(ostream & os, const pair<K,V> & a )
{
	os<<"[ "<<a.first<<", "<<a.second<<" ]";
	return os;
}

const int INF = 100000000;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

class GameOnABoard
{
	int N,M;
	vector<int> board;
	vector<vector<int > > Q;
	vector<bool> visited;
	vector<int> dist;

	int oD(int i, int j)
	{
		return i * M + j;
	}

	void tD( int x, int & i, int &j )
	{
		i = x / M;
		j = x % M;
	}

	int djk( int i, int j)
	{
		int q = oD(i,j);
		dist[q] = board[q];
		Q[0].push_back(q);
		int k = 0;
		while(true)
		{
			q = -1;
			while(k < Q.size() && Q[k].size() == 0 )++k;
			if( k == Q.size() )
				break;

			q = Q[k][Q[k].size()-1];
			Q[k].pop_back();

			if(visited[q])
				continue;
			visited[q] = true;

			for( int k = 0; k < 4; ++k )
			{
				int ii,jj,qq;
				tD(q,ii,jj);

				ii += dx[k];
				jj += dy[k];

				if( ii >= 0 && ii < N && jj >= 0 && jj < M)
				{
					qq = oD(ii,jj);
				//	if( visited[qq])
				//		continue;
					int nd = dist[q] + board[qq];
					if( dist[qq] > nd)
					{
						dist[qq] = nd;
						Q[nd].push_back(qq);
					}
				}
			}
		}

		int ret = 0;
		for( int k = 0; k < N*M; ++k )
		{
			ret = max(ret,dist[k]);
		}
		return ret;
	}

	public:
	int optimalChoice(vector <string> cost)
	{


		N = cost.size();
		M = cost[0].size();
		d_print(N);
		d_print(M);
		Q.resize(80,vector<int>(0));
		visited.resize(N*M,false);
		dist.resize(N*M,INF);

		for( int i = 0; i < N; ++i )
		{
			for( int j = 0; j < M; ++j )
			{
				board.push_back(cost[i][j]-'0');
			}
		}

		int ret = INF;
		for( int i = 0; i < N; ++i )
		{
			for( int j = 0; j < M; ++j )
			{
				for( int k = 0; k < Q.size(); ++k )
					Q[k].clear();
				fill(ALL(visited),false);
				fill(ALL(dist),INF);
				ret = min(ret, djk(i,j));
			}
		}
		return ret;

	}
};
