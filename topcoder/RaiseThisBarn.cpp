// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The pony Applejack is going to raise a new barn.
The barn will consist of N sections in a row.
Some of the sections will be empty, others will contain a single cow each.
You are given a string str with N characters.
This string describes the desired layout of the barn:
the character 'c' represents a section with a cow, and the character '.' represents an empty section.

After she raises the barn, Applejack will build a wall that will divide the barn into two separate parts:
one containing the first k sections and the other containing the last N-k sections, for some integer k.
Each part must contain at least one section. (I.e., k must be between 1 and N-1, inclusive.)
Additionally, Applejack wants both parts to contain exactly the same number of cows.

Return the number of possible positions for the wall.
In other words, return the number of choices for the integer k such that all the conditions above are satisfied.

DEFINITION
Class:RaiseThisBarn
Method:calc
Parameters:string
Returns:int
Method signature:int calc(string str)


CONSTRAINTS
-str will contain between 2 and 50 characters, inclusive.
-Each character in str will be 'c' or '.'.


EXAMPLES

0)
"cc..c.c"

Returns: 3

Applejack can choose k=2, k=3, or k=4.
The three corresponding solutions are shown below, with '|' representing the wall between the two parts.

cc|..c.c
cc.|.c.c
cc..|c.c


1)
"c....c....c"

Returns: 0

There is an odd number of cows. It is impossible to divide them into two equal halves.

2)
"............"

Returns: 11

This is a barn with 12 empty sections. It can be divided in 11 different ways: into 1+11 sections, 2+10 sections, ..., or 11+1 sections.

3)
".c.c...c..ccc.c..c.c.cc..ccc"

Returns: 3



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


class RaiseThisBarn
{
	public:
	int calc(string str)
	{
		int cows = 0;
		for( int i = 0; i < str.size(); ++i ) if(str[i] =='c')++cows;
		if( cows % 2 ) return 0;
		int a,b;
		a = b = 0;
		for( ;b<cows/2;++a)
		{
			if( str[a] == 'c')++b;
		}
		int ret = 1;
		for( ; a < str.size() && str[a] != 'c';++a)
		{
			++ret;
		}
		if( cows == 0 ) ret -=2;
		return ret;
	}
};
