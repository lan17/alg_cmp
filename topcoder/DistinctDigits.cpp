#line 2 "DistinctDigits.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <set>
#include <cmath>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

template <class T >
inline string toString( T & a )
{
       stringstream s;
       s<<a;
       return s.str();
}

int powa( int b, int p )
{
    int ret = 1;
    while( p > 0 )
    {
           b *= b;
           p--;
    }
    return ret;
}

unsigned long long count2( int i )
{
       unsigned long long ret = 0;
      // int b = 10;
       while( i > 0 )
       {
              int c = i % 10;
              c += powa( 10, c );
              ret += c;
              i /= 10;
       }
       cout<<ret<<endl;
       return ret;
}

class DistinctDigits 
{
	public:
	int count(int low, int high) 
	{
        set<unsigned long long> numbaz;
		FORR( i, low, high )
		{
             numbaz.insert( count2( i ) );
        }
        return numbaz.size() ;
	}
};


// Powered by FileEdit
