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
#include <bitset>

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

int N;

vector<pair<string, int> > guesses;

/**
 * DFS to solve using bitsets.
 *
 * guess_i is index into current guess
 * Possibilities is a set of bitsets for possible choices for each digit.
 */
void solve( int guess_i, vector<int> possibilities, int num_right, int last_digit_pos )
{
	// if last print it out and exit.
	if( guess_i == guesses.size() )
	{
		for( int i = 0; i < N; ++i )
			for( int j = 0; j < 10; ++j )
				if( possibilities[ i ] & (1 << j) )
					cout << j;
		cout << endl;
		exit( 0 );
	}

	for( int j = last_digit_pos + 1; j <= N; ++j )
	{
		if( j == N && num_right == 0 )
			solve( guess_i + 1, possibilities, guesses[ guess_i + 1 ].second, -1 );
		else if( j < N )
		{
			if( num_right > 0 )
			{
				int pos_j = possibilities[ j ];
				possibilities[ j ] &= (1 << (guesses[ guess_i ].first[ j ] - '0'));
				if( possibilities[ j ] )
					solve( guess_i, possibilities, num_right - 1, j );
				possibilities[ j ] = pos_j;
			}
			possibilities[ j ] &= ~(1 << (guesses[ guess_i ].first[ j ] - '0'));
			if( possibilities[ j ] == 0 )
				break;
		}
	}
}


bool cmp(const pair<string,int> & a, const pair<string,int> & b )
{
	return a.second < b.second;
}

int main( int argc, char ** argv )
{

	while(cin.good())
	{
		string t;
		getline(cin,t);
		//cout<<t<<endl;
		vecs line = expand(t, " ;");
		if(line.size() != 3 ) break;
		//d_print(line.size());
		N = line[0].size();
		guesses.push_back(make_pair(line[0],atoi(line[1].c_str())));
	}
	// sort by number of guesses in increasing order.
	sort( ALL( guesses ), cmp );

	vector<int> possibilities(N,(1<<10)-1);

	solve( 0, possibilities, 0, -1 );
}
