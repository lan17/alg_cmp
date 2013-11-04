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

#define vecs vector< string > 
#define veci vector< int >
#define vecsi vector<string>::iterator
#define vecii vector<int>::iterator

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define pnt(x) cout<<#x<<" = "<<(x)<<endl;

using namespace std;

class PrimeSums 
{
	
	public:
	long long getCount(vector <int> bag)
	{
		int maxSum = 10000001;
		vector< bool > isPrime( maxSum, true );
		isPrime[0]=isPrime[1]=false;
		int i = 2;
		while( (i += 2) <= sqrt( maxSum ) ) isPrime[i] = false;
		for ( i = 3; i <= sqrt(maxSum); i += 2 )
		{
			if( isPrime[i] )
			{
				int k = i;
				while( (k+=i) <= maxSum ) isPrime[k]=false;
			}
		}
		int sum = 0;
		FOREACH( element, bag ) sum += *element; 
		vector<vector< int > > dp( 2, vector< int >( sum+1, 0 ) );
		dp[0][0] = 1;
		int last, next;
		last = 0;
		next = 1;
		FOR( j, bag.size( ) )
		{
			if( j > 0 && bag[j] == bag[j-1] ) continue;
			int cnt = 1;
			while( j+cnt < bag.size( ) ) if( bag[ j+cnt ] == bag[j] ) cnt++; else break;
			FORR( s, 0, sum )
			{
				dp[next][s] = dp[last][s];
				FORR( t, 1, cnt ) if ( s-t*bag[j] >= 0 ) dp[next][s] += dp[last][s-t*bag[j]];
			}
			last = 1-last;
			next = 1-next;
		}

		long long result = 0;
		FORR( j, 0, sum ) if (isPrime[j]) result += dp[last][j];
		return result;


		
	}
};

/* Lev A Neiman's coding here */


// Powered by FileEdit
