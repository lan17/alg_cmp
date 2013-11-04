#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main( int argc, char ** argv )
{
	string t;
	getline(cin,t);
	int h = atoi( t.substr(0,2).c_str() );
	int m = atoi( t.substr( 3,2 ).c_str() );
	//cout<<h<<":"<<m<<endl;
	if( h == 12 ) h = 0;
	h *= 60;
	h += m;

	double hour = 360.0/((double)12*60);
	hour = h * hour;
	//cout<<hour<<endl;

	double min = 360.0/60.0;
	min = m * min;

	if( hour >= 360.0 ) hour -= 360.0;
	if( min >= 360.0 ) min -=360.0;

	cout<<hour<<" "<<min<<endl;
	
	
}
