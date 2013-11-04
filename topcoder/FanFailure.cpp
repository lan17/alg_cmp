#line 2 "FanFailure.cpp"
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

class FanFailure 
{
	public:
	vector <int> getRange(vector <int> capacities, int minCooling) 
	{
        int total = 0;
        FOR( i, capacities.size() ) total += capacities[i];
		sort( ALL( capacities ) );
		int MFS = 0;
		int MFC = 0;
		int s = 0;
		FOR( i , capacities.size() )
		{
             s+= capacities[i];
             if( s > minCooling )
             {
                 MFC = capacities.size() - (i+1);
                 break;
             }
        }
       // reverse( ALL( capacities ) );
        s = total;
        FOR( i, capacities.size() )
        {
             s -= capacities[i];
             if( s < minCooling )
             {
                 MFS = i;
                 break;
             }
        }
        vector<int> ret;
        ret.push_back( MFS );
        ret.push_back ( MFC );
        return ret;
        
	}
};
