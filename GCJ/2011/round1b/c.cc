#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

#define d_print(x) cout<<#x<<(x)<<endl;

typedef vector<string> vecs;
typedef unsigned long long ull;

#define in(x,y) ((x).find((y)) != (x).end())

vector<string> expand( const string & input, string delimiters = " \t")
{
	#define string_find(del,k) ((del).find((k)) != string::npos)
	vector<string> out;
	size_t begin = 0;
	size_t i;
	for( i = 0; i < input.length( ); i++ )
	{
		if( i > 0 && string_find( delimiters, input[i] ) && !string_find( delimiters, input[i-1] ) )
		{
			out.push_back( input.substr( begin, i - begin ) );
			begin = i+1 ;
		}
		else
		{
			if( string_find( delimiters, input[i] ) ){ begin = i+1; }
		}
	}
	if( begin < i )
	{
		out.push_back( input.substr( begin ) );
	}
	return out;
	#undef string_find
}

int main( int argc, char ** argv )
{
	int T;
	cin>>T;
	for( int CASE = 1; CASE <= T; ++ CASE )
	{
		int N,M;
		cin>>N>>M;

	}
}
