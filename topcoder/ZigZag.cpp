#line 2 "ZigZag.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std; 

int solve( const vector <int> & sequence, vector<int> & dp, int i, bool p_n = true )
{
    if( dp[i] != -1 ) return dp[i];
    if( i == sequence.size() - 1 ) return 1;
    int ret = 0;
    FORR( j, i + 1, dp.size() - 1 )
    {
          if( ( p_n && sequence[j] - sequence[i] > 0 ) || (!p_n && sequence[j]-sequence[i] < 0 )  ) 
              ret = max( ret, solve( sequence, dp, j, !p_n ) );
          
    }
    dp[i] = 1 + ret;
    return dp[i];
}

class ZigZag 
{
	public:
	int longestZigZag(vector <int> sequence) 
	{
        int n = sequence.size();
		vector<int> dp( n, -1 );
		vector<int> dp2(n, -1 );
		int ret = 0;
		FOR( i, n )
		{
             ret = max( ret, solve( sequence, dp, i, true ) );
             ret = max( ret, solve( sequence, dp2, i, false ) );
        }
        return ret;
	}
};
