#line 2 "CircularLine.cpp"
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

int fastest_way( vector<int> & t, int a, int b )
{
    int p, q;
    int i = min( a, b );
    int j = max( a, b );
    p = q = 0;
    for( int k = i; k < j; ++k ) p += t[k];
    for( int k = i - 1; k >= 0; --k ) q += t[k];
    for( int k = t.size()-1; k >= j; --k ) q+= t[k];
    //cout<<i<<":"<<j<<" = "<<p<<":"<<q<<endl;
    return p < q ? p : q;
}

class CircularLine 
{
	public:
	int longestTravel(vector <int> t) 
	{
        int ret = 0;
		for( int i = 0; i < t.size(); ++i )
        {
             for( int j = 0; j < t.size(); ++j )
             {
                  if( i == j ) continue;
                  int q = fastest_way( t, i, j ) ;
                  cout<<q<<endl;
                  ret = max( ret, q );
             }
        }
        return ret;
	}
};
