#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

using namespace std;

int main( int arg, char ** argv )
{
	int n;
	cin>>n;
	int answer = 0;
	int cnt = 0;
	map<int,int> mis;
	vector<int> num(1e6,-1);
	for( int i = 0; i < n; ++i )
	{
		int t;
		cin>>t;
		if( t == i ) ++cnt;
		else
		{
			mis[i] = t;
		}
		num[i]=t;
	}
	//cout<<cnt<<endl;
	if( cnt == n ) answer = cnt;
	else
	{
		int bonus = 0;
		FOREACH( ii, mis )
		{
			int i = ii->first;
			int t = ii->second;
			int pbonus = 1;
			if( num[t] == i ) ++pbonus;
			bonus = max(bonus, pbonus);
		}
		answer = cnt + bonus;
	}
	cout<<answer<<endl;
}
