#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <iostream>

#define in(x,y) ((x).find((y)) != (x).end())
#define d_print(x) cout<<#x<<"="<<x<<endl

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct cmp
{

bool operator()( const pair<int,int> & a, const pair<int,int> & b )
{
	int ah = a.first + a.second *10000;
	int bh = b.first + b.second *10000;
	return ah< bh;
	//if( a.first < b.first ) return true;
	//return a.second < b.second;
}
};

void solve( int i, int j, int R, set<pair<int,int>, cmp > & accum)
{
/*
	pair<int,int> k = make_pair( i, j );
//	if( in(accum,k) ) return;
	accum.insert( k );

	if( R == 0 ) return;

	for( int d = 0; d < 4; ++ d )
	{
		int ii,jj;
		ii = i + dx[d];
		jj = j + dy[d];
		solve( ii, jj, R - 1, accum );
	}
	*/

	for( int ii = i - R; ii <= i + R; ++ii )
	{
		for( int jj = j - R; jj <= j + R; ++jj )
		{
			int dist = abs(i-ii) + abs(j-jj);
			if( dist <= R )
				accum.insert(make_pair(ii,jj));
		}
	}
}



class CandyShop 
{
	public:
	int countProbablePlaces(vector <int> X, vector <int> Y, vector <int> R) 
	{
		int n = X.size();
		//vector<vector<bool> > good( n, vector<int>(n,true));
		set<pair<int,int>, cmp > res;
		for( int i = 0; i < n; ++i )
		{
			for( int ii = X[i] - R[i]; ii <= X[i] + R[i]; ++ii )
			{
				for( int jj = Y[i] - R[i]; jj <= Y[i] + R[i]; ++jj )
				{
					int d = abs(ii-X[i])+abs(jj-Y[i]);
					if( d > R[i] ) continue;
					bool good = true;
					for( int j = 0; j < n; ++j )
					{
						if( i == j ) continue;
						int d2 = abs(X[j]-ii) + abs( Y[j] -jj );
						if( d2 > R[j] )
						{
							good = false;
							break;
						}

					}
					if( good ) res.insert(make_pair(ii,jj));
				}
			}
		}




		for( set<pair<int,int>, cmp >::iterator i = res.begin(); i != res.end(); ++i  )
		{
			cout<<i->first<<", "<<i->second<<endl;
		}

		return res.size();
	}
};


// Powered by FileEdit


// Powered by FileEdit
