#line 2 "KnockoutTourney.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <set>
#include <list>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

int findV( vector<bool> & v, int i )
{
    FORR( j, i, v.size() - 1 ) if( v[j] ) return j;
    return -1;
}

class KnockoutTourney 
{
	public:
	int meetRival(int N, int you, int rival) 
	{
		int ret = 1;
		vector<bool> win( N + 1, true );
		while( true )
		{
               int i = 1;
               while( findV(win, i ) != -1 )
               {
                      int p = findV( win, i );
                      int r = findV( win, p +1 );
                      if( r == -1 ) break;
                      if( (p == you && r == rival ) || (p == rival && r == you ) ) return ret;
                      if( p == you || p == rival ) win[r] = false;
                      else if( r == you || r == rival ) win[p] = false;
                      else win[p] = false;
                      
                      i = r + 1; 
               }      
               ret ++;
        }
        return ret;
	}
};
