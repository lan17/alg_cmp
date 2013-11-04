#line 2 "DeckRearranging.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <list>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

class DeckRearranging 
{
	public:
	string rearrange(string deck, vector <int> above) 
	{
           list<char> ret;
           ret.push_back( deck[0] );
           for( int i = 1; i < above.size(); ++i )
           {
                list<char>::iterator c = ret.begin();
                for( int k = 0; k < above[i]; ++k )
                {
                     c++;
                }
                ret.insert( c, deck[i] );
           }
           string ans;
           FOREACH( el, ret )
           {
                    ans.push_back( *el );
           }
           return ans;
           
		
	}
};
