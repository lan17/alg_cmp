// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Little Elephant from the Zoo of Lviv likes sequences of integers.




You are given a long long A and an int N.
Little Elephant has the sequence S = (A, A+1, ..., A+N).
Little Elephant now wants to erase some digits from some of the numbers.
He may erase multiple digits from the same number, but he will not erase any of the numbers completely.
After erasing some digits from a number the gaps disappear.
For example, by erasing the middle digit of the number 147 Little Elephant obtains the number 17 (and not two separate numbers 1 and 7).




It is allowed for some number to contain leading zeroes after erasings.
For example, from the number 1047 Little Elephant may create, among other possibilities, the number 047 or the number 47.
These are two different ways of erasing. 
They are both allowed and the numbers they produce have the same value.




Two ways of erasing the digits are considered different if there is some position in some element of S that was erased in one of the cases and was not erased in the other one.
For example, if S = (11, 12), there are two different ways to change it to (1, 2).
(In one of them we erase the first and in the other we erase the second digit of the number 11.)




After erasing the digits, Little Elephant wants to obtain a non-decreasing sequence.
Let R be the number of different ways to do that.
Return R modulo 1,000,000,007.


DEFINITION
Class:LittleElephantAndArray
Method:getNumber
Parameters:long long, int
Returns:int
Method signature:int getNumber(long long A, int N)


CONSTRAINTS
-A will be between 1 and 1,000,000,000,000,000 (10^15), inclusive.
-N will be between 0 and 100, inclusive.


EXAMPLES

0)
1
9

Returns: 1



1)
10
2

Returns: 15



2)
4747774
1

Returns: 8369



3)
6878542150015
74

Returns: 977836619



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

const ll MOD = 1000000007;


class LittleElephantAndArray
{
	public:
	int getNumber(long long A, int N)
	{

	}
};
