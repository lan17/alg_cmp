// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are given a string s consisting of lower case letters.
We assign the letters 'a' to 'z' values of 1 to 26, respectively.
We will denote the value assigned to the letter X by val[X].
For example, val['a'] = 1 and val['e'] = 5.



We define the value of the string s as follows.
For each letter s[i], let k[i] be the number of letters in s that are less than or equal to s[i], including s[i] itself.
Then, the value of s is defined to be the sum of k[i] * val[s[i]] for all valid i.



Given the string, compute and return the value of the string.


DEFINITION
Class:ValueOfString
Method:findValue
Parameters:string
Returns:int
Method signature:int findValue(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-s will consist of lowercase letters ('a'-'z').


EXAMPLES

0)
"babca"

Returns: 35


The value of this string is 2*4 + 1*2 + 2*4 + 3*5 + 1*2 = 35.



We can get the value as follows. The first character is a 'b' which has value 2, and has 4 characters that are less than or equal to it in the string (i.e. the first, second, third and fifth character of the string). Thus, this first character contributes 2*4 to the sum. We can derive a similar expression for each of the other characters. 


1)
"zz"

Returns: 104



2)
"y"

Returns: 25



3)
"aaabbc"

Returns: 47



4)
"topcoder"

Returns: 558



5)
"thequickbrownfoxjumpsoverthelazydog"

Returns: 11187



6)
"zyxwvutsrqponmlkjihgfedcba"

Returns: 6201



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
#define FOR(i,n) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR(i,s,e) for( int (i) = (s); (i) <= (e); ++(i))

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

vector<string> expand( const string & input, string delimiters = " 	")
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


class ValueOfString
{
	public:
	int findValue(string s)
	{

	}
};
