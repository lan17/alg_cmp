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


template <typename T>
ostream & operator <<(ostream & os, const vector<T> & v )
{
	os<<"[ ";
	for( int i = 0; i < v.size(); ++i ) os<<v[i]<<", ";
	os<<"]";
	return os; 
} 

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



long long compute( int n, vector<long long> & mem )
{
	if( n == 1 || n == 0 ) return 1;
	if( mem[n] != -1 ) return mem[n];
	long long ret = compute(n-1,mem);
	if( n % 2 == 0 ) ret = ret * 2 + 1;
	else ret = 2 * ret - 1;
	mem[n] = ret;
	return ret;
}

class TrafficCongestionDivTwo
{
	public:
	long long theMinCars(int treeHeight)
	{
		vector<long long> mem(treeHeight+1,-1);
		return compute(treeHeight,mem);
	}
};


// Powered by FileEdit
