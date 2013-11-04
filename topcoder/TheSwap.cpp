#line 2 "TheSwap.cpp"
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

void swap_s( string & s, int i, int j )
{
     char t = s[i];
     s[i]=s[j];
     s[j] = t;
 }

void find_next( string & s)
{ 
     if( s == "-1" ) return;
     bool mod = false;
    for( int i = 0 ; i < s.size(); ++i )
    {
         int t = i;
         for( int j = i + 1; j < s.size(); ++j )
         {
              t = s[j] > s[i] && s[t] <= s[j] ? j : t;
         }
         if( t != i )
         {
             cout<<t<<endl;
             swap_s( s, i, t );
             mod = true;
             break;
         }
    }
    if(!mod) prev_permutation( ALL( s ) );
    if( s[0] == '0' ) s = "-1";
    
} 
 
class TheSwap 
{
	public:
	int findMax(int n, int k) 
	{
		stringstream s;
		s<<n;
		string num = s.str();
		if( num.size() == 1 && k > 0 ) return -1;
		cout<<"Original = "<<num<<endl;
		FOR( i, k )
		{
             find_next( num );
             cout<<num<<endl;
         }
         if( num[0] == '0' ) return -1;
         return atoi( num.c_str() );
	}
};
