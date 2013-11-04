#line 2 "ProductOfDigits.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

int max_dp = 1e7;
int max_rec = 0;

class ProductOfDigits 
{
    int solve( unsigned long long i, int N, vector<int> & dp, int rec = 0 )
    {
        max_rec = max( rec, max_rec );
        if( i > N ) return 1<<29;
        if( i == N ) return 1;
        if( i < max_dp && dp[i] != -1 ) return dp[i];
                //cout<<i<<endl;
        int ret = 1<<29;
        FORR( k, 2, 9 )
        {
              ret = min( ret, solve( i * k, N, dp, rec + 1 ) );
        }
        //cout<<"==================="<<ret<<endl;
        if( i < max_dp ) dp[i] = 1 + ret;
        else return 1 + ret;
        return dp[i];
    } 
      
	public:
	int smallestNumber(int N) 
	{
        if( N == 1 ) return 1;
        int ret = 1<<29;
        vector<int> dp( max_dp, -1 );
        FORR( i, 2, 9 ) ret = min( ret, solve( i, N, dp ) );
        cout<<max_rec<<endl;
        if( ret >= 1<<29 ) return -1;
        return ret;
		
	}
};
