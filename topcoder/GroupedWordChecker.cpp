#line 2 "GroupedWordChecker.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <set>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

class GroupedWordChecker 
{
	public:
	int howMany(vector <string> words) 
	{
        int ret = 0;
		FOR( i, words.size() )
		{
                 set<char> c;
                 c.insert( words[i][0] );
                 bool bad = false;
                 FORR( j, 1, words[i].size() - 1 )
                 {
                       if( c.count( words[i][j] ) == 1 && words[i][j-1] != words[i][j] )
                       {
                           bad = true;
                           break;
                       }
                       c.insert( words[i][j] );
                 }
                 if( !bad ) ret++;
                 
         }
         return ret;
	}
};
