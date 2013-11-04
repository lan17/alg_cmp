#line 2 "CorporationSalary.cpp"
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

map<int,unsigned long long> m;

long long s( int e, vector<string> & g )
{
    if( isMaped( m, e ) ) return m[e];
    long long  ret = 0;
    bool got_any_sub = false;
    FOR( i, g[e].size() )
    {         
         if( g[e][i] == 'Y' )
         {
             ret += s( i, g ); 
             got_any_sub = true;
         }
     }
     if( !got_any_sub ) ret = 1;
     m[e] = ret;
     return ret;
}
 
class CorporationSalary 
{
	public:
	long long totalSalary(vector <string> relations) 
	{
         int num_e = relations.size();
         FOR( i, num_e ) s( i, relations );
          
          long long ret = 0;
          FOREACH( el, m ) ret += el->second;
                   
		return ret;
	}
};
