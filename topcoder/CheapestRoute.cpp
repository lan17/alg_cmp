#line 2 "CheapestRoute.cpp"
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
#define has( m, x ) (find( ALL(m), (x) ) != (m).end())
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 


using namespace std;
 
int INF = 1<<29;

void print2DV( vector<vector<int> > & v )
{
     FOREACH( ve, v )
     {
              FOREACH( n, *ve)
              {
                       cout<<*n<<" ";
              }
              cout<<endl;
     }
 }

class CheapestRoute 
{
	public:
	vector <int> routePrice(vector <int> cellPrice, vector <int> enterCell, vector <int> exitCell, int teleportPrice) 
	{
        int n = cellPrice.size();
        int t_p = teleportPrice;
		vector< vector< int > > dp;
		FOR( i, n ) dp.push_back( vector<int>( 4, INF ) );
		FOR( i, n ) dp[i][2] = 0;
		dp[0][0] = dp[0][1] = dp[0][2] = 0;
		bool done = false;
	    while( !done ){
               done = true;
		FORR( i, 1,  n-1 )
		{
             if( cellPrice[i] == -1 )
             {
                 dp[i][0] = dp[i][1] = dp[i][2] = INF;
                 continue;
             }
             int min_c = dp[i-1][0] + cellPrice[i];
             int min_m = dp[i-1][1] + 1;
             int min_t = dp[i-1][2];
             int prev_t = -1;
             if( i < n - 1 )
             {
                 if( min_c >= dp[i+1][0] + cellPrice[i] )
                 {
                     min_c = dp[i+1][0] + cellPrice[i];
                     min_m = dp[i+1][1] + 1;
                     min_t = dp[i+1][2];
                 }
             }
             if( has( exitCell, i ) )
             {
                 FOR( t, exitCell.size() )
                 {
                      if( exitCell[t] == i )
                      {
                          if( min_c >=  dp[ enterCell[t] ][0] + t_p + dp[ enterCell[t] ][2] )
                          {
                              min_c = dp[ enterCell[t] ][0] + t_p + dp[ enterCell[t] ][2];
                              min_m = dp[ enterCell[t] ][1] + 1;
                              min_t = dp[ enterCell[t] ][2] + 1;
                              prev_t = enterCell[t];
                          }
                          
                      }
                 }
             }
             if( min_c != dp[i][0] || min_m != dp[i][1] || dp[i][2] != min_t ) done = false;
             dp[i][0] = min_c;
             dp[i][1] = min_m;
             dp[i][2] = min_t;
             dp[i][3] = prev_t;
        }
        
        }
        cout<<n<<endl;
        print2DV( dp );
        if( dp[n-1][0] >= INF ) return vector<int>(0,0);
        vector<int> ret(2,0);
        ret[0] = dp[n - 1 ][0];
        ret[1] = dp[n - 1 ][1];
        return ret;
		
	}
};
