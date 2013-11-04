#include <iostream>

using namespace std;

int solutions( int p )
{
	int ret = 0;
	for( int a = 1; a < p / 2; ++ p )
	{
		for( int b = 1; b < a; ++b )
		{
			for( int c = 1; c <= b; ++ c)
			{
				if( a + b + c == p && ( a*a == b*b+c*c ) )++ret
			}
		}
	}
	return ret;
}

int main( int argc, char ** argv )
{
	int m = 0;
	int pm;
	for( int p = 1; p <= 1000; ++p )
	{
		int t = solutions( p );
		if( m < t )
		{
			m = t;
			pm = p;
		}
	}
	cout<<pm<<endl;
	
}
