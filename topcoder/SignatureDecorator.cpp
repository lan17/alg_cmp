#line 2 "SignatureDecorator.cpp"
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

string reverse( string & b )
{
       string ret ="";
       for( int i = b.size() - 1; i >= 0; --i )
       {
            ret.push_back( b[i] );
        }
        return ret;
}

class SignatureDecorator 
{
	public:
	string applyDecoration(string name, vector <string> commands, vector <string> decorations) 
	{
           FOR( i, commands.size() )
           {
                if( commands[i] == "surround" ) 
                {
                    name = decorations[i] + name + reverse( decorations[i] );
                }
                if( commands[i] == "append" )
                {
                    name += decorations[i];
                }
                if( commands[i] == "prepend" )
                {
                    name = decorations[i] + name;
                }
           }
           return name;
		
	}
};
