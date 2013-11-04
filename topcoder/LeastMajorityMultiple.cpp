#line 2 "LeastMajorityMultiple.cpp"
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

class LeastMajorityMultiple 
{
	public:
	int leastMajorityMultiple(int a, int b, int c, int d, int e) 
	{
        int m = max( a, max( b, max( c, max( d, e ) ) ) );
        int count = 0;
		for( int i = 2; i < 1e6; ++i )
		{
             count = 0;
             count += i % a == 0;
             count += i % b == 0;
             count += i % c == 0;
             count += i % d == 0;
             count += i % e == 0;
             if( count >= 3 ) return i;
         }
	}
};


// Powered by FileEdit
