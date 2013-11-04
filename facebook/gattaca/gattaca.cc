#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef unsigned long long ull;

bool cmp( const vector<ull> & a, const vector<ull> & b )
{
	bool a1 = a[0] < b[0];
	bool a2 = a[0] > b[0];
	bool a3 = a[1] < b[1];
	return a1 ? true : a2 ? false : a3;
}

ull solve( const vector<vector<ull> > & preds, vector<ull> & mem, vector<ull> & maxs, int curr )
{
	if( mem[curr] != 0 ) return mem[curr];
	ull ret = preds[curr][2];
	ull maxj = 0;
	const ull & start = preds[curr][0];
	const ull & end = preds[curr][1];
	bool good = false;
	int j = 0;
	for( size_t i = curr + 1; i < preds.size(); ++i )
	{
		if( !good && ( preds[i][0] >= start && preds[i][0] <= end ) ) continue;
		if( good == false )
		{
			j = i;
			good = true;
		}
		if( maxs[i] != 0)
		{
			maxj = max( maxj, maxs[i] );
			ret = preds[curr][2] + maxj;
			break;
		}
		ull ns = solve( preds, mem, maxs, i );
		maxj = max( ns, maxj );
		ret = max( ret, preds[curr][2] + ns );
	}
	maxs[j] = maxj;
	mem[curr] = ret;
	return ret;
}

int main( int argc, char ** argv )
{
	int n,m;

	map<int,vector<int> > preds_map;
	
	ifstream ifs( argv[1] );
	ifs>>n;
	while( ifs.good() )
	{
		string t;
		getline( ifs, t );
		int t1 = atoi( t.c_str() );
		if( t1 > 0 )
		{
			m = t1;
			break;
		}
	}
	vector<vector<ull> > preds(m, vector<ull>(3));
	for( int i = 0; i < m; ++i )
	{
		int start, stop, score;
		ifs>>start>>stop>>score;
		preds[i][0] = start;
		preds[i][1] = stop;
		preds[i][2] = score;
	}
	sort( preds.begin(), preds.end(), cmp );
	//cout<<"number of preds "<<preds.size()<<endl;
	
	vector<ull> mem(preds.size(), 0 );
	vector<ull> maxs( preds.size(), 0 );
	for( int i = preds.size()-1; i >=0; --i )
	{
	//	if( i % 1000 == 0 ) cout<<i<<endl;
		solve( preds, mem, maxs, i );
	//	cout<<"======================="<<endl;
	}
	ull answer = 0;
	for( size_t i = 0; i < mem.size(); ++i )
		answer = max( answer, mem[i] );
	cout<<answer<<endl;
}
