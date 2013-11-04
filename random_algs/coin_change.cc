#include <vector>
#include <iostream>
#include "common.h"

using namespace std;

long long mHit = 0;

 long long numWays( int D, int i, const vector<int> & coins, vector<vector< long long> > & mem, vector<vector< long long> > & hit )
{
	 hit[i][D]++;
	 mHit = max(hit[i][D], mHit);
	if( mem[i][D] > -1 ) return mem[i][D];

	if( i == 0 ) return 1;
	if( D == 0 ) return 1;

	long long ret = 0;
	//if( D == coins[i] ) ret -=1;
	if( D < coins[i] ) ret = numWays(D,i-1,coins,mem,hit);
	else
	{
		ret = numWays( D, i-1,coins,mem, hit)+numWays(D-coins[i],i,coins,mem,hit);
	}
	//d_print(D<<" "<<coins[i]<<" "<<ret);
	mem[i][D]=ret;
	return ret;
}

 long long numWays( int D, const vector<int> & coins )
{
	vector<vector< long long> > mem( coins.size(), vector< long long>(D+1,-1) );
	vector<vector< long long> > hit( coins.size(), vector< long long>(D+1,0) );
	long long ret = numWays(D,coins.size()-1,coins,mem,hit);
	//cout<<hit<<endl;
	cout<<mHit<<endl;
	return ret;

}

#define coinNum 3
int coinsArr[coinNum] = {1,2,5};

int main(int argc, char **argv)
{
	vector<int> coins;
	for( int i = 0; i < coinNum; ++i ) coins.push_back(coinsArr[i]);
	int D;
	cin>>D;
	cout<<numWays(D,coins)<<endl;
}
