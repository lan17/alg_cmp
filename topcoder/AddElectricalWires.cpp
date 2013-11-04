#line 2 "AddElectricalWires.cpp"
#include <string>
#include <vector>
#include <map>
#include <iostream>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

int GraphSize( int n )
{
    return (n*(n-1))/2;
} 

int GridC( int wired_c, int n )
{ 
    int ret = 0;
    for( int i = n - 1; i > n - wired_c; --i )
    {
         ret += i;
    }
    return ret;
}

class AddElectricalWires 
{
	public:
	int maxNewWires(vector <string> wires, vector <int> gridConnections) 
	{
        map<pair<int,int>, int > connections;
        int c = 0;
        FOREACH( str, wires )
        {
                 FOREACH( ch, *str )
                 {
                          if( *ch == '1' ) c++;
                 }
        }
        c /= 2;
        cout<<GraphSize( 8 )<<endl;
        int total_connections = GraphSize( wires.size() );
        int need_connected = total_connections - c;
        cout<<c<<" "<<GridC( gridConnections.size(), wires.size() )<<" "<<need_connected<<" "<<total_connections<<endl;
        //if( gridConnections.size() == 1 ) return need_connected;
        return need_connected - GridC( gridConnections.size(), wires.size() );
		
	}
};
