#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>

using namespace std;

int print_dbg = 1;

#define d_print(x) { if(print_dbg){  cerr << __LINE__ << " " << #x << " = " << x << endl; cerr.flush(); } }

typedef vector<string> vecs;
typedef vector<int> veci;
typedef unsigned long long ull;
typedef long long ll;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))


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
}

bool isGood( const string & str )
{
	long long  div[7] = { 2, 3, 5, 7, 11, 13, 17 };
	for( size_t i = 1; i < str.size() - 2; ++i )
	{
		string t = str.substr( i, 3 );
	//	cout<<t<<endl;
		long long j = atol( t.c_str() );
		if( j % div[i-1] != 0 ) return false;
	}
	return true;
}


int main( int argc, char ** argv )
{
	cout<<isGood( "1406357289" )<<endl;
	string num="0123456789";
	long long answer = 0;
	while( true )
	{
		if( isGood( num ) ) answer += atol( num.c_str() );
		if( ! next_permutation( ALL(num ) ) ) break;
	}
	cout<<answer<<endl;
	
}
