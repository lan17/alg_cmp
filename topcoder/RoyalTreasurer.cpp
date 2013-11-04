#line 2 "RoyalTreasurer.cpp"
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

class RoyalTreasurer 
{
	public:
	int minimalArrangement(vector <int> A, vector <int> B) 
	{
        sort( ALL( B ) );
        sort( ALL( A ) );
        reverse( ALL( A ) );
        int ret = 0;
        FOR( i, A.size() )
        {
             ret += A[i]*B[i];
         }	
         return ret;
	}
};
