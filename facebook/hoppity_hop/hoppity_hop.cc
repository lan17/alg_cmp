#include <iostream>
#include <fstream>

using namespace std;

int main( int argc, char ** argv )
{
	ifstream ifs( argv[1] );
	int n;
	ifs>>n;
	ifs.close();
	for( int i = 1; i <=n; ++i )
	{
		if( i % 5 == 0 && i % 3 == 0 ) cout<<"Hop"<<endl;
		else if( i % 5 == 0 ) cout<<"Hophop"<<endl;
		else if( i % 3 == 0 ) cout<<"Hoppity"<<endl;		
	}
}
