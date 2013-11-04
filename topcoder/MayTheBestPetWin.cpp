// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The pony Rainbow Dash wants to choose her pet.
There are N animals who want to be her pet.
Rainbow Dash numbered them 0 through N-1.

To help her make the decision, Rainbow Dash decided to organize a relay race for the animals.
The race track is already known, and for each animal we know how fast it is.
More precisely, you are given vector <int>s A and B with the following meaning:
For each i, the animal number i will take between A[i] and B[i] seconds (inclusive) to complete the track.

For the race the animals will be divided into two competing teams.
This is a relay race, so the team members of each team will all run the same track, one after another --
when the first team member finishes, the second one may start, and so on.
Thus the total time in which a team completes the race is the sum of the times of all team members.
Note that we can use the estimates given by A and B to estimate the total time for any team of animals.

Given two teams S and T, the value maxdiff(S,T) is defined as the largest possible difference in seconds
between the time in which team S finishes the course and the time in which team T finishes the course.

Rainbow Dash now needs to assign each of the animals to one of the two competing teams.
She wants to see a close competition, so she wants the teams to finish as close to each other as possible.
Formally, she wants to divide all animals into teams S and T in a way that minimizes maxdiff(S,T).
Return the smallest possible value of maxdiff(S,T).

DEFINITION
Class:MayTheBestPetWin
Method:calc
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int calc(vector <int> A, vector <int> B)


NOTES
-The teams are not required to contain the same number of animals.


CONSTRAINTS
-A will contain between 2 and 50 elements, inclusive.
-A and B will contain the same number of elements.
-Each element of A will be between 1 and 10,000, inclusive.
-Each element of B will be between 1 and 10,000, inclusive.
-For each i, B[i] will be greater than or equal to A[i].


EXAMPLES

0)
{3,4,4,7}
{3,4,4,7}

Returns: 2

In this test case we know the exact time in which each of the animals completes the track.
An optimal solution is to choose teams S={0,3} and T={1,2}.
Then team S will certainly complete the track in 3+7 = 10 seconds, and team T in 4+4 = 8 seconds.
Thus, maxdiff(S,T)=2.

1)
{1,3,5,4,5}
{2,5,6,8,7}

Returns: 5

Here one of the optimal solutions is S={2,3} and T={0,1,4}.
For these two teams we have maxdiff(S,T)=5.
For example, it is possible that S will complete the track in 6+8 = 14 seconds, and T will complete it in 1+3+5 = 9 seconds.
It is also possible that S will complete the track up to 5 seconds before T does.

2)
{2907,949,1674,6092,8608,5186,2630,970,1050,2415,1923,2697,5571,6941,8065,4710,716,756,5185,1341,993,5092,248,1895,4223,1783,3844,3531,2431,1755,2837,4015}
{7296,6954,4407,9724,8645,8065,9323,8433,1352,9618,6487,7309,9297,8999,9960,5653,4721,7623,6017,7320,3513,6642,6359,3145,7233,5077,6457,3605,2911,4679,5381,6574}

Returns: 52873



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


class MayTheBestPetWin
{
	public:
	int calc(vector <int> A, vector <int> B)
	{

	}
};
