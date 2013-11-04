#line 2 "MarblesInABag.cpp"
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

double solve( int r, int b, vector< vector< double > > & dp, vector< vector< bool > > & done )
{
       if( done[r][b] ) return dp[r][b];
       double rd, bd;
       rd = (double) r;
       bd = (double ) b;
       dp[r][b] = ( rd / ( rd + bd ) ) * solve( r-1, b-1, dp, done );
       if( b > 1 ) dp[r][b] += (bd/(rd+bd))*solve( r, b-2, dp, done );
       done[r][b] = true;
       return dp[r][b];
}

class MarblesInABag 
{
	public:
	double getProbability(int redCount, int blueCount) 
	{
		try
		{
            vector< vector< double > > dp( redCount + 1, vector<double>( blueCount + 1, 0 ) );
            vector< vector< bool > > done( redCount + 1, vector< bool >( blueCount + 1, false ) );
            FOR( i, blueCount + 1 )
        {
             dp[0][i] = 1.0;
             done[0][i] = true;
        }
        FORR( i, 1, redCount )
        {
             dp[i][0] = 0.0;
             done[i][0] = true;
        }
        return solve( redCount, blueCount, dp, done );
        }
        catch( std::exception & exc )
        {
               return 0.0;
        }
        
	}
};
