// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel found two astronomical records.
They both describe the same solar system.
In this solar system each planet orbits the sun at some fixed distance, and those distances are distinct.
Each of the two records contains a comparison of some of those distances.



The first record is a vector <int> A with x elements.
These elements correspond to some x planets in the solar system.
The distances at which these planets orbit the sun have the ratio A[0] : A[1] : ... : A[x-1].
The planets described by A are ordered by their distance from the sun.

(That is, earlier elements of A correspond to planets that are closer to the sun.
Thus, the elements of A will always form a strictly increasing sequence.)



The second record is a vector <int> B with y elements.
These elements correspond to some y planets in the solar system.
The distances at which these planets orbit the sun have the ratio B[0] : B[1] : ... : B[y-1].
The planets described by B are also ordered by their distance from the sun.



Note that the planets mentioned in a record do not have to be consecutive.
For example, if a solar system contains the planets P, Q, R, S, T, and U, it is possible that the first record compares P, R, and S, and the second record compares Q, R, T, and U.



We assume that both records are correct.
Return the smallest possible total number of planets in the solar system.

DEFINITION
Class:AstronomicalRecordsEasy
Method:minimalPlanets
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minimalPlanets(vector <int> A, vector <int> B)


CONSTRAINTS
-A will contain between 2 and 50 elements, inclusive.
-B will contain between 2 and 50 elements, inclusive.
-Each element in A will be between 1 and 1,000, inclusive.
-Each element in B will be between 1 and 1,000, inclusive.
-Elements in A will be strictly increasing.
-Elements in B will be strictly increasing.


EXAMPLES

0)
{1,2,3,4}
{2,3,4,5}

Returns: 5

There have to be at least 4 planets, because each record compares 4 of them.
There cannot be exactly 4 planets, because 1:2:3:4 is not the same ratio as 2:3:4:5.
For example, the orbital radii of the two planets closest to the sun would have to have ratio 1:2 and at the same time ratio 2:3, which is impossible.
There can be exactly 5 planets with relative orbital radii 1,2,3,4,5.


1)
{1,2,3,4}
{2,4,6,8}

Returns: 4

In this case we can only have 4 stars, because 1:2:3:4 = 2:4:6:8.

2)
{1,2,3,5,6,8,9}
{2,4,5,6,7,8,9}

Returns: 9

One optimal solution: 1, 2, 3 ,4 ,5 ,6 ,7, 8, 9.

3)
{1,2,3,4}
{6,7,8,9}

Returns: 6

One optimal solution: 3, 6, 7, 8, 9, 12.


4)
{200,500}
{100,200,300,400,600,700,800,900}

Returns: 9



5)
{1,2,3,4,5,6,7,8,9,10,11,12}
{6,7,8,9,10,11,12,13,14,15}

Returns: 15



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

int gcd( int a, int b )
{
	if( b == 0) return a;
	return gcd(b,a%b);
}

class AstronomicalRecordsEasy
{
	public:
	int minimalPlanets(vector <int> A, vector <int> B)
	{
		int agcd = accumulate(ALL(A),A[0],gcd);
		int bgcd = accumulate(ALL(B),B[0],gcd);

		auto flatFunc = [](int d){
						return [&](int a){return a/d;};
					};

		transform(ALL(A),A.begin(),flatFunc(agcd));
		transform(ALL(B),B.begin(),flatFunc(bgcd));

		d_print(A<<" -- "<<B);

	}
};
