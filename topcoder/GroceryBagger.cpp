#line 2 "GroceryBagger.cpp"
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

class GroceryBagger 
{
	public:
	int minimumBags(int strength, vector <string> itemType) 
	{
		map<string,int> itemz;
		FOREACH( item, itemType )
		{
                 if( !isMaped( itemz, *item ) ) itemz[*item] = 0;
                 itemz[*item]++;
        }
        int bags = 0;
        FOREACH( item, itemz )
        {
                 bags += item->second / strength;
                 if( item->second % strength != 0 ) bags++;
        }
        return bags;
	}
};
