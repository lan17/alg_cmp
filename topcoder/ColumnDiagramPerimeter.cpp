#line 2 "ColumnDiagramPerimeter.cpp"
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

class ColumnDiagramPerimeter 
{
	public:
	int getPerimiter(vector <int> a) 
	{
		int ret = a.size();
		int prev = 0;
		FOR( i, a.size() )
		{
             ret += abs( a[i] - prev ) + 1;
             prev = a[i];
        }
        ret += a[a.size()-1];
        return ret;
	}
};
