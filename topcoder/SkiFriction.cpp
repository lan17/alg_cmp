#line 2 "SkiFriction.cpp"
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

class SkiFriction 
{
	public:
	int bestPosition(string skiFriction, string pathFriction) 
	{
		vector<int> ski(skiFriction.size(), 0 );
        vector<int> path(pathFriction.size(), 0 );
        for( int i = 0; i < skiFriction.size(); ++i ) ski[i] = skiFriction[i]-48;
        for( int i = 0; i < pathFriction.size(); ++i ) path[i] = pathFriction[i]-48;
        
        int sum = 0;
        for( int i = 0; i < path.size()-ski.size(); ++i )
        {
             int m = 0;
             for( int j = 0; j < ski.size(); ++j )
             {
                  m = max( ski[j] + path[i+j], m );
             }
             cout<<i<<" "<<m<<endl;
             sum += m;
        }
        return sum;
	}
};


// Powered by FileEdit
