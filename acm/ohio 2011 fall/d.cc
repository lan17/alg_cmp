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




int main( int argc, char ** argv )
{
	int X, int Y;
	cin>>X>>Y;
	while( cin.peek() =='\n' || cin.peek() == '\r' ) cin.ignore();
	map<int,set<string> > prefs;
	map<string,set<int> > i_prefs;
	for( int i = 0; i < X; ++i )
	{
		string t;
		getline( cin, t );
		vecs tt = expand( t, " \t" );
		if( tt.size() == 0 ) continue;
		int jj = atoi( tt[0].c_str() );
		for ( int j = 2; j < tt.size(); ++j )
		{
			prefs[jj].insert( tt[j] );
			i_prefs[tt[j]].insert(i);
		}
	}

	int ci = 1;
	//vector<bool> taken( X, false );

	while( true )
	{
		bool done = true;

		bool found = false;
		FOREACH( i, i_prefs )
		{
			if( i->second.size() == ci )
			{
				//found = true;
				bool any_free = false;
				FOREACH( jj, i->second )
				{
					if( !taken[*jj] )
					{
						any_free = true;
						taken[*jj] = true;
						break;
					}
				}
				if( any_free)
			}
		}
		if( done ) break;
	}


}
