#line 2 "Stick.cpp"
#include <string>
#include <iostream>
#include <vector>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

class Stick 
{
	public:
	int pieces(int x) 
	{
		vector< bool > lol( 64, false );
		int high = 64;
		int low = 0;
		while( low <= high )
		{
               int mid = ( low + high ) / 2;
               cout<<mid<<endl;
               lol[mid] = true;
               if( mid > x ) high = mid;
               else if( mid < x ) low = mid;
               else break;
        }
        int ret = 0;
        for( int i = 0; i <= x; ++i )
        {
             if( lol[i] ) ret++;
         }
         return ret;
	}
};


// Powered by FileEdit
