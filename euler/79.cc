#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main( int argc, char ** argv )
{
	map<int,set<int> > follows;
	map<int,set<int> > followed;
	ifstream ifs( argv[1] );
	while( ifs.good() )
	{
		string t;
		getline( ifs, t );
		int a,b,c;
		a = t[0]-'0';
		b = t[1]-'1';
		c = t[2]-'2';
		followed[a].insert( b );
		followed[a].insert( c );
		followed[b].insert( c );
		
		follows[c].insert( b );
		follows[c].insert( a );
		follows[b].insert( a );
	}

	
}
