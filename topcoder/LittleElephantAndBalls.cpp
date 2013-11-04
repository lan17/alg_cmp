// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Little Elephant from the Zoo of Lviv likes balls.
He has some balls that he wants to arrange into a row on the table.
Each of those balls has one of three possible colors: red, green, or blue.




You are given a string S.
This string represents all of the balls Little Elephant has, in the order in which he will be placing them onto the table.
Red, green, and blue balls are represented by the characters 'R', 'G', and 'B', respectively.
Each time Little Elephant places a new ball onto the table, he may add it anywhere into the row of already placed balls.




Additionally, each time Little Elephant adds a ball to the table, he scores some points (possibly zero).
The number of points is calculated as follows:

If this is the first ball being placed on the table, there are 0 points for it.
If he adds the current ball to one of the ends of the row, the number of points scored is equal to the number of different colors of the balls on the table, excluding the current ball.
If he adds the current ball between two other balls, the number of points scored is equal to the number of different colors of the balls before the current ball, plus the number of different colors of the balls after the current ball.





For example, suppose that the balls currently on the table form the row "GBBG". 
Little Elephant now wants to add a new red ball ('R').
One of the options is to add it to the beginning.
This scores 2 points and produces the row "RGBBG".
Another option is to add it between "GBB" and "G".
There are 2 distinct colors in "GBB" and 1 in "G", so this move is worth 2+1 = 3 points.
This move produces the row "GBBRG".




Return the maximum total number of points that Little Elephant can earn for placing the balls onto the table.


DEFINITION
Class:LittleElephantAndBalls
Method:getNumber
Parameters:string
Returns:int
Method signature:int getNumber(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-S will consist only of characters 'R', 'G' and 'B'.


EXAMPLES

0)
"RGB"

Returns: 3

Any strategy is optimal here. Each strategy scores 0+1+2 = 3 points.

1)
"RGGRBBB"

Returns: 21



2)
"RRRGBRR"

Returns: 16



3)
"RRRR"

Returns: 5



4)
"GGRRRGR"

Returns: 18



5)
"G"

Returns: 0



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


class LittleElephantAndBalls
{
	public:
	int getNumber(string S)
	{

	}
};
