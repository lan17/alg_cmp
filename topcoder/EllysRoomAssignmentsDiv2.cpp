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

#define FOR(i,n) for(ull (i) = 0; (i) < (n); ++(i) )

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


class EllysRoomAssignmentsDiv2
{
	public:
	double getProbability(vector <string> ratings)
	{
		string r = "";
		FOR(i,ratings.size())
			r += ratings[i];
		vecs rr = expand(r," ");
		int N = rr.size();
		veci V(N, 0);
		FOR( i, N )
			V[i] = atoi(rr[i].c_str() );
		int R = N % 20 == 0 ? N / 20 : N / 20 + 1;
		int Rr = N % 20 == 0 ? 20 : 21;
		int elly = V[0];
		sort( ALL(V ));
		reverse( ALL(V) );
		if( N < 21 )
			return 1.0;
		int elly_i = -1;
		FOR( i, N )
		{
			if( elly == V[i] )
			{
				elly_i = i;
				break;
			}
 		}
		if( elly_i == 0 ) return 1.0;

		if( elly_i < R)
			return 0.0;
		return 1.0/(double)R;
	}
};

/*
int main(int argc, char**argv)
{
}
*/
