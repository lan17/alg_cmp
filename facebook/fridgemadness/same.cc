#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main( int argc, char ** argv )
{
	ifstream if1( argv[1] );
	ifstream if2( argv[2] );

	while( if1.good() && if2.good() )
	 {
		 int a,b;
		 int a1, b1;
		 if1>>a>>b;
		 if2>>a1>>b1;
		 if( a1 != a || b1 != b )
		  {
			  cout<<"NOT SAME"<<endl;
			  return 0;
		  }
	
		 
	 }
	 cout<<"same"<<endl;
}

