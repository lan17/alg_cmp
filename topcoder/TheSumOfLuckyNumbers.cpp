#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <cstdio>
#include <valarray>      
#include <ext/hash_set> 
#include <ext/hash_map>
#include "float.h"

#define FMAX DBL_MAX
#define FMIN DBL_MIN

#define IMAX 1e6
#define IMIN -1e6

#define ld long double
#define ll long long
#define ull unsigned long long

#define vecs vector< string > 
#define veci vector< int >
#define vecsi vector<string>::iterator
#define vecii vector<int>::iterator
#define vec vector

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define pnt(x) cout<<#x<<" = "<<(x)<<endl;

using namespace std;

int binary2lucky( int binary, int digitz )
{
	int l = 0x00000001;
	int i = binary;
	string r;
	int countz = digitz;
	while( countz > 0 )
	{
		int z = i & l;
		if( z == 1 ) r.push_back( '7' );
		if( z == 0 ) r.push_back( '4' );
		i = i >> 1;
		countz--;
	}
	return atoi( r.c_str() );
}

int findLargestLucky( int lim, const vector<int> & lucky, int i = 0, int j = 0 )
{
	/*
	FOR( i, lucky.size() )
	{
		if( lucky[i] >= lim ) return i - 1;
	}
	return -1;
	*/



	int low = 0;
	int high = lucky.size() - 1;
	while( low <= high )
	{
		int mid = ( low + high ) / 2;
		if( lucky[mid] < lim && lucky[mid+1] >= lim ) return mid;
		else if( lucky[mid] > lim )
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}


}

vector<int> lucky;
// previous_solution, lucky_number, number of numbers in this solution.
vector< pair< pair<int,int>, int > > dp;

class TheSumOfLuckyNumbers 
{
	public:
	vector <int> sum(int n)
	{
		FORR( i, 1, 10 )
		{
			int pow = 0x01;
			pow = pow << i;
			FOR( j, pow )
			{
				lucky.push_back( binary2lucky( j, i ) );
			}
		}
		//cout<<lucky.size();
		sort( lucky.begin(), lucky.end() );

		FOR( i, n + 1 ) dp.push_back( pair< pair<int,int>, int > ( pair<int,int>(-1, 0 ), IMAX ) );

		int luck;
		for( int i = 0; ( luck = lucky[i] ) <= n; ++i )
		{
			dp[luck].first.first = 0;
			dp[luck].first.second = luck;
			dp[luck].second = 1;
		}

		FORR( i, 8, n )
		{
			if(dp[i].first.second==i ) continue;
			int j = 0;
			int max_l = findLargestLucky( i, lucky );
			//cout<<lucky[j]<<endl;
			int min_solution = i-lucky[j];
			int min_solution_num = dp[min_solution].second;
			if( min_solution_num == IMAX ) continue;
			int min_solution_lucky = lucky[j];
			for( int z = 0; z <= max_l; ++z )
			{
				int s = dp[i-lucky[z]].second;
				//if( s == IMAX ) break;
				//cout<<"numba = "<<i-lucky[z]<<" - "<<s<<endl;
				if( min_solution_num >= s ) 
				{
					min_solution_num = s;
					min_solution = i-lucky[z];
				}
				

			}
			if( min_solution_num != IMAX )
			{
				dp[i].first.first = min_solution;
				dp[i].first.second = i - min_solution;
				dp[i].second = dp[min_solution].second + 1;
				
			}

		}
		vector<int> ret;
		if( dp[n].second == IMAX ) return ret;
		int travela = n;
		while ( travela != 0 )
		{
			ret.push_back( dp[travela].first.second );
			travela = dp[travela].first.first;
		}
		sort( ret.begin(), ret.end() );
		return ret;



		
	}
};

/* Lev A Neiman's coding here */


// Powered by FileEdit


// Powered by FileEdit
