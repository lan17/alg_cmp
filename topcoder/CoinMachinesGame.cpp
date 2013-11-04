#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iostream>

using namespace std;

#define in(x,y) ((x).find((y)) != (x).end())

map<pair<int, int >, int> mem;

pair<int,int> with_one( vector<int> & need, vector<int> & give, int i, int curr_coins )
{
	int ret = 0;
	while( curr_coins >= need[i] )
	{

		int t = curr_coins / need[i];
		ret += t;
		curr_coins -= t * need[i];
		curr_coins += t * give[i];

	}
	return make_pair(ret, curr_coins );
}

bool cmp( const pair<int,double> & a, const pair<int,double> & b )
{
	return a.second < b.second;
}

class CoinMachinesGame 
{
	public:
	int maxGames(int coins, vector <int> need, vector <int> give) 
	{
		vector<pair<int,double> > grd;
		for( int i = 0; i < need.size(); ++i )
				grd.push_back(make_pair(i,double(need[i])-double(give[i])));
		sort( grd.begin(), grd.end(), cmp );

		int answer = 0;
		for( int i = 0; i < grd.size(); ++i )
		{
			int ind = grd[i].first;
			if( need[ind] > coins ) continue;
			pair<int,int> d = with_one( need, give, ind, coins );
			coins = d.second;
			answer += d.first;
			cout<<"coins = "<<coins<<endl;
			cout<<"times = "<<d.first<<endl;
		}
		return answer;
	}
};


// Powered by FileEdit
