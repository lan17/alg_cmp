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
#include <deque>

using namespace std;

int print_dbg = 1;

#define d_print(x) { if(print_dbg){  cout << __LINE__ << " " << #x << " = " << x << endl; cout.flush(); } }

typedef vector<string> vecs;
typedef vector<int> veci;
typedef unsigned long long ull;
typedef long long ll;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

int INF = 0;
int ZERO = 0;
int dx [] = {1,-1,0};
int dy [] = {0,0,1};

template <class T, class U>
ostream & operator <<( ostream & os, const pair<T,U> p )
{
	os<<"{"<<p.first<<", "<<p.second<<"}";
	return os;
}

template <class T>
ostream & operator <<(ostream & os,  vector<vector<T> > & v )
{
	FOREACH(i,v)
								{
									FOREACH(j,*i)
									{
										cout<<*j<<", ";
									}
									cout<<endl;
								}
	return os;

}

struct coordCompare
{
	vector<vector<int> > * dist;
	coordCompare(vector<vector<int> > * dist):dist(dist){}

	bool operator()(const pair<int,int> &a, const pair<int,int> &b)
	{
		return (*dist)[a.second][a.first] < (*dist)[b.second][b.first];
	}
};

class WallGameDiv2
{

	public:
	int play(vector <string> costs)
	{
		int N = costs[0].size();
		int M = costs.size();
		d_print(N);
		d_print(M);

		vector<vector<vector<int> > > sums(M,vector<vector<int> >(N,vector<int>(N,-1)));

		for( int j = 0; j < M; ++j )
		{
			for( int i = 0; i < N; ++i )
			{
				bool bad = costs[j][i] =='x';
				if(!bad)
				{
					d_print("fuck");
					int sum = costs[j][i] - '0';
					sums[j][i][i] = sum;
					d_print(sum);
					d_print("SHIT");
					for( int ii = i + 1; ii < N; ++ii)
					{
						char val = costs[j][ii];
						if( val != 'x')
						{
							sum += val -'0';
							sums[j][i][ii] = sum;
						}
						else
						{
							break;
						}
					}
				}
			}
		}

		vector<vector<int> > dp(M, vector<int>(N,-1));
		for( int i = 0; i < N; ++i )
		{
			char p = costs[M-1][i];
			if( p != 'x' )
			{
				dp[M-1][i] = p - '0';
			}
		}
		for( int j = M - 2; j >= 0; --j )
		{
			for( int i = 0; i < N; ++i )
			{
				//cout<<"========"<<endl;
				//d_print(j);
				//d_print(i);
				char val = costs[j][i];
				if( val == 'x' ) continue;
				val -= '0';
				//d_print(int(val));
				int maxCost = 0;
				for( int ii = 0; ii < N; ++ii )
				{
					if( dp[j+1][ii] == -1 ) continue;
					int cost =  sums[j][min(i,ii)][max(i,ii)];
					if( cost == -1 ) continue;
					//int iiVal = costs[j+1][ii]-'0';
					//d_print(ii);
					//d_print(cost);
					cost = cost + dp[j+1][ii];
					//d_print(iiVal);
					//d_print(dp[j+1][ii]);
					//d_print(cost);
					maxCost = max(maxCost,cost);
				}
				dp[j][i] = maxCost;


				cout<<dp<<endl;
			}
		}

		return dp[0][0];


		/// CRAP
		// COL / ROW
		pair<int,int> start = make_pair(0,0);
		vector<vector<int> > dist(M, vector<int>(N, INF));
		vector<vector<bool> > visited(M, vector<bool>(N,false));
		dist[0][0] = ZERO;
		vector<pair<int,int> > Q;
		for( int i = 0; i < N; ++ i )
		{
			for( int j = 0; j < M-1; ++j )
			{
				if( i == j ) continue;
				if( costs[j][i] != 'x' )
				{
					Q.push_back(make_pair(i,j));
				}
			}
		}
		//vector<bool> goodOnLastRow(N, true);
		//Q.push_back(start);
		coordCompare compare(&dist);
		sort(ALL(Q), compare);
		Q.push_back(start);
		while(!Q.empty())
		{
			pair<int,int> curr = Q.back();
			Q.pop_back();
			visited[curr.second][curr.first] = true;
			int i = curr.first;
			int j = curr.second;
			for( int d = 0; d < 3; ++d )
			{
				int ii = i + dx[d];
				int jj = j + dy[d];
				if( ii >= 0 && ii < N  && jj >= 0 && jj < M )
				{
					char p = costs[jj][ii];
					if(visited[jj][ii])continue;
					if( p == 'x') continue;

					int val = p - '0';
					//val *= -1;
					int d = val + dist[j][i];
					if( d > dist[jj][ii])
					{
						dist[jj][ii] = d;
					}
				}
			}
			cout<<"===="<<endl;
			FOREACH(i,dist)
							{
								FOREACH(j,*i)
								{
									cout<<*j<<", ";
								}
								cout<<endl;
							}

			sort(ALL(Q), compare);
		}


		int answer = 1;
		for( int i = 0; i < N; ++i )
		{
			answer = min(answer, dist[M-1][i]);
		}
		answer -= ZERO;
		return answer * -1;

	}
};
