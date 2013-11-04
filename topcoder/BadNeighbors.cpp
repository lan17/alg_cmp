#line 2 "BadNeighbors.cpp"
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

int solve( const vector <int> & donations, int x)
{
    if( x == donations.size() - 1 ) return donations[x];
    if( x >= donations.size() ) return 0;
    
    int ret = max( solve( donations, x + 2 ) + donations[x], solve( donations, x + 3 ) + donations[x+1] );
    cout<<x<<":"<<donations[x]<<endl;
    cout<<"==========="<<ret<<endl;
    return ret;
}

class BadNeighbors 
{ 
	public:
	int maxDonations(vector <int> donations) 
	{
        int n = donations.size();
		vector<int> d1( donations );
		vector<int> d2( donations );
		d1.pop_back( );
		d2.erase( d2.begin() );
		return max( solve( d1, 0 ), solve( d2, 0 ) );
		
	}
};
