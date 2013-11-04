#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

template <class T>
string toString( const T & a )
{
	stringstream s;
	s<<a;
	return s.str();
}

#define lim 1000000

bool primes[lim];

void make_primes()
{
	memset(primes, true, sizeof(bool) * lim );
	for( int i = 3; i < lim; ++i )
	{
		if( !primes[i] ) continue;
		for( int j = 2; j * i < lim; ++j )
		{
			primes[i*j] = false;
		}
	}
}

void rotateString(string & t)
{
	char t1 = t[0];
	for( int i = 0; i < t.size() - 1; ++i )
	{
		t[i] = t[i+1];
	}
	t[t.size()-1]=t1;
}

bool is_circular( int prime )
{
	string num = toString(prime);
	//sort(num.begin(), num.end() );
	for( int i = 0; i < num.size()+1; ++i )
	{
		rotateString( num );
		cout<<num<<endl;
		if(!primes[atoi(num.c_str())]) return false;
		
	}
	return true;
}

int main( int argc, char ** argv )
{
	int answer = 0;
	make_primes();
	is_circular( 197 );
	
	for( int i = 10; i < lim; ++i )
	{
		if( primes[i] && is_circular(i) )
		{
			++answer;
			cout<<i<<endl;
		}
	}		
	cout<<answer<<endl;
	
}
