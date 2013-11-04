#line 2 "TheBeauty.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <set>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

class TheBeauty 
{
	public:
	int find(int n) 
	{
		stringstream s;
		s<<n;
		string num = s.str();
		
		set<char> p;
		FOREACH( c, num )
		{
                 p.insert( * c);
                 }
                 return p.size();
		
	}
};


// Powered by FileEdit
