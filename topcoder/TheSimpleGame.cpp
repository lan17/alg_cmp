#line 2 "TheSimpleGame.cpp"
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

int moves( int n, int x, int y )
{
    int dist_x;
    int dist_y;
    if( x == 1 || x == n ) dist_x = 0;
    else dist_x = min( n - x, x - 1 );
    if( y == 1 || y == n ) dist_y = 0;
    else dist_y = min( n - y, y - 1 );
    return dist_x + dist_y;
}

class TheSimpleGame 
{
	public:
	int count(int n, vector <int> x, vector <int> y) 
	{
		int ret = 0;
		FOR( i, x.size() )
		{
             ret += moves( n, x[i], y[i] );
        }
        return ret;
	}
};
