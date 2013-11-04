#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <bitset>
#include <set>
#include <algorithm>

//#include "RadixTree.cc"

using namespace std;

typedef unsigned long long ull;

#define N 5

template <class T>
string toString( const T & a )
{
	stringstream s;
	s<<a;
	return s.str();
}

bool good( const string & str, bool full = true )
{
	int n = str.size();
	for( int i = 0; i < n; ++i )
	{		
		for( int i1 = i+1; i1 < n; ++i1 )
		{
			if( !full && i1 > n - N )
				break;

			bool eq = true;
			for( int j = 0; j < N; ++j )
			{
				if( str[(i+j)%n] != str[(i1+j)%n] )
				{
					eq = false;
					break;
				}
			}
			if(eq)
			{
			//	cout<<str.substr( i, N )<<endl;
				return false;
			}
		}
		
	}
	return true;
}

ull rec_count = 0;

void solve( string & sol, int i, set<string> & accum )
{
	++rec_count;
	if( ( sol.size() == 1<<N ) && good( sol ) )
	{
		accum.insert( sol );
		return;
	}
	string n = sol + "0";
	if( good( n, false ) ) solve( n, i, accum );
	n = sol + "1";
	if( good( n, false ) ) solve( n, i, accum );

}

unsigned long long str2num( string str )
{
	reverse( str.begin(), str.end() );
	unsigned long long ret = 0;
	for( int i = 0; i < str.size(); ++i )
	{
		ret += (1<<i ) * ( (str[i]=='0')?0:1 );
	}
	return ret;
}

int main( int argc, char ** argv )
{
	string sol = "";
	for( int i = 0; i < N; ++i )
	{
		sol += "0";
	}
	set<string> sols;
	solve( sol, 0, sols );

	ull answer = 0;

	for( set<string>::iterator i = sols.begin(); i != sols.end(); ++i )
	{
		unsigned long long z = str2num( *i );
		//cout<<*i<<" = "<<z<<endl;
		answer += z;
	}
	cout<<rec_count<<endl;
	cout<<answer<<endl;
	
}
