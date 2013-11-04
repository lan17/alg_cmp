#line 2 "FallingFactorialPower.cpp"
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

double pK( int n, int k )
{
       double ret = 1;
       FOR( i, k  )
       {
            ret *= (double)n-(double)i;
        }
        return ret;
}

double nK( int n, int k )
{
       k *= -1;
       double ret = (double)n;
       FOR( i, k + 1 )
       {
            ret /= (double)n + (double)i;
        }
        return ret;
       }

class FallingFactorialPower 
{
	public:
	double compute(int n, int k) 
	{
		if( k == 0 ) return 1;
		if( k > 0 ) return pK( n, k );
		else return nK( n, k );
	}
};
