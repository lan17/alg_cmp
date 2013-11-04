// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// King Dengklek is the perfect king of Kingdom of Ducks, where slimes and ducks live together in peace and harmony.

Kingdom of Ducks has a pretty strange currency system. There are only two coin types: one with value A and one with value B, where A and B are different. This currency system is denoted by {A, B}. These two coin types are sufficient for daily transactions, because all prices in this kingdom are in the form of (A*p + B*q) for some non-negative integers p and q. Therefore, slimes and ducks can pay for any goods with a combination of the two coin types.

Bored with the current system, King Dengklek considered another currency system with two coin types: one with value X and one with value Y, where X and Y are different. Of course, with this new system, combinations of the two new coin types must make it possible to pay all the prices one could pay with currency system {A, B}. (Note that the new coin types may also make it possible to pay some additional prices.)

You are given ints A, B, and X. Return the number of different positive integers Y (other than X) such that the currency system {X, Y} can be used to replace the currency system {A, B}. If there is an infinite number of possible values for Y, return -1 instead.

DEFINITION
Class:KingXNewCurrency
Method:howMany
Parameters:int, int, int
Returns:int
Method signature:int howMany(int A, int B, int X)


CONSTRAINTS
-A, B, and X will each be between 1 and 200, inclusive.
-A and B will be different.


EXAMPLES

0)
5
8
5

Returns: 5

These are the 5 possible currency systems: {5, 1}, {5, 2}, {5, 3}, {5, 4}, and {5, 8}.

1)
8
4
2

Returns: -1

All prices are multiples of four. Since a coin type with value 2 alone can pay any price that is a multiple of four, there is an infinite number of possible values of Y.

2)
7
4
13

Returns: 1

The only possible currency system is {13, 1}.

3)
47
74
44

Returns: 2

The two possible currency systems are {44, 1} and {44, 3}.

4)
128
96
3

Returns: 65



*/
// END CUT HERE

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

template<class T>
ostream & operator <<(ostream & os, const vector<T> & v )
{
	os<<"[ ";
	for( int i = 0; i < v.size(); ++i )
	{
		os<<v[i]<<", ";
	}
	os<<"]";
	return os;
}

template<class T>
ostream & operator <<(ostream & os, const vector<T> * v )
{
	os<<*v;
	return os;
}

template<class K, class V>
ostream & operator <<(ostream & os, const map<K,V> & a )
{
	os<<"{ ";
	FOREACH(i,a)
	{
		os<<i->first<<": "<<i->second<<", ";
	}
	os<<"}";
	return os;
}

template<class K, class V>
ostream & operator <<(ostream & os, const pair<K,V> & a )
{
	os<<"[ "<<a.first<<", "<<a.second<<" ]";
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

int gcd(int a, int b )
{
	if( b == 0 ) return a;
	return gcd(b,a%b);
}


class KingXNewCurrency
{
	public:
	int howMany(int A, int B, int X)
	{
		int g = gcd(A,B);
		if( X == g ) return -1;
		int Xa = gcd(A,X), Xb = gcd(B,X);
		if( Xa == 1 && Xb == 1 ) return 1;
				
	}
};
