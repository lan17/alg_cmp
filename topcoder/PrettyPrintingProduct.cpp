#line 2 "PrettyPrintingProduct.cpp"
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

template <class T>
string toString( T & a )
{
       stringstream s;
       s<<a;
       return s.str();
}

class PrettyPrintingProduct 
{
	public:
	string prettyPrint(int A, int B) 
	{
		unsigned long long c = 1;
		FORR( i, A, B ) c*= i;
		string c_str = toString( c );
		int exp = 0;
		int t = c_str.size()-1;
        while( c_str[t] == '0' )
        {
               t--;
               exp++;
        }
        string ans = c_str.substr( 0, t + 1 );
        if( ans.size() > 10 )
        {
            string tmp = ans;
            ans = "";
            ans += tmp.substr( 0, 5 );
            ans += "...";
            ans += tmp.substr( t -4, 5 );
        }
        //else ans = c_str.substr( 0, t+1 );
        return ans + " * 10^" + toString( exp );
        
	}
};
