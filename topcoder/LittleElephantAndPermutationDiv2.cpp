// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
This problem statement contains superscripts and/or subscripts. These may not display properly outside the applet.




Little Elephant from the Zoo of Lviv likes permutations.
A permutation of size N is a sequence (a1, ..., aN) that contains each of the numbers from 1 to N exactly once.
For example, (3,1,4,5,2) is a permutation of size 5.




Given two permutations A = (a1, ..., aN) and B = (b1, ..., bN), the value magic(A,B) is defined as follows:
magic(A,B) = max(a1,b1) + max(a2,b2) + ... + max(aN,bN).




You are given the int N.
You are also given another int K.
Return the number of pairs (A,B) such that both A and B are permutations of size N, and magic(A,B) is greater than or equal to K.
(Note that A and B are not required to be distinct.)


DEFINITION
Class:LittleElephantAndPermutationDiv2
Method:getNumber
Parameters:int, int
Returns:long long
Method signature:long long getNumber(int N, int K)


CONSTRAINTS
-N will be between 1 and 10, inclusive.
-K will be between 1 and 100, inclusive.


EXAMPLES

0)
1
1

Returns: 1

For N=1 the only pair of permutations is ( (1), (1) ).
The magic of this pair of permutations is 1, so we count it.

1)
2
1

Returns: 4

Now there are four possible pairs of permutations. They are shown below, along with their magic value.

magic( (1,2), (1,2) ) = 1+2 = 3
magic( (1,2), (2,1) ) = 2+2 = 4
magic( (2,1), (1,2) ) = 2+2 = 4
magic( (2,1), (2,1) ) = 2+1 = 3

In all four cases the magic value is greater than or equal to K.

2)
3
8

Returns: 18

When A = (1,2,3), there are 3 possibilities for B: (2,3,1), (3,1,2) and (3,2,1). For each of the other 5 values of A, it can be shown that there are 3 possibilities for B as well. Therefore the answer is 3*6 = 18.

3)
10
47

Returns: 13168189440000



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

ll fac(ll n)
{
	ll ret = 1;
	for( int i = 1; i <= n; ++i )ret *=i;
	return ret;
}


class LittleElephantAndPermutationDiv2
{
	public:
	long long getNumber(int N, int K)
	{
		vector<int> numbers;
		ll ways = 0;
		for( int i = 1; i <= N; ++i ) numbers.push_back(i);
		while(true)
		{
			int sum = 0;
			for( int i = 0; i < numbers.size(); ++i )
			{
				sum += max( i + 1, numbers[i] );
			}
			if( sum >= K )
			{
				ways += fac(N);
			}
			if(!next_permutation(ALL(numbers)))break;
		}
		return ways;
		
	}
};
