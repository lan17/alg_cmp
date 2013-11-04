#line 2 "MegaCoolNumbersEasy.cpp"
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

bool mega_cool( int n )
{
     int prev = n % 10;
     n /= 10;
     if( n == 0 ) return true;     
     int curr_digg = n % 10;
     n /= 10;
     int diff = curr_digg - prev;
     prev = curr_digg;
     while( n > 0 )
     {
            curr_digg = n % 10;
            n/=10;
            if( curr_digg - prev != diff ) return false;
            prev = curr_digg;
     }
     return true;
     
 }

class MegaCoolNumbersEasy 
{
	public:
	int count(int N) 
	{
		int ret = 0;
		FORR( i, 1, N )
		{
              ret += mega_cool( i );
        }
        return ret;
	}
};
