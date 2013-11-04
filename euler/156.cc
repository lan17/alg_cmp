#include <iostream>
#include <sstream>
#include <string>

typedef unsigned long long ull;

using namespace std;

template <class T>
string toString( const T & a )
{
	stringstream s;
	s<<a;
	return s.str();
}

ull f(ull n, char d)
{
	string num = toString( n );
	
}

int main( int argc, char ** argv )
{
	
}
