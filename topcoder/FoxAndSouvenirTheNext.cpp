// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel just returned home from her trip to New Fox City.
She has brought a bunch of souvenirs.
You are given their values in a vector <int> value.


Now she wants to give each souvenir either to her mother or to her father.
She would like to divide the souvenirs in a fair way.
More precisely:

The total number of souvenirs given to her mother must be the same as the total number of souvenirs given to her father.
At the same time, the total value of souvenirs given to her mother must be the same as the total value of souvenirs given to her father.



Return "Possible" if she can reach her goal, and "Impossible" otherwise.

DEFINITION
Class:FoxAndSouvenirTheNext
Method:ableToSplit
Parameters:vector <int>
Returns:string
Method signature:string ableToSplit(vector <int> value)


CONSTRAINTS
-value will contain between 1 and 50 elements, inclusive.
-Each element in value will be between 1 and 50, inclusive.


EXAMPLES

0)
{1,2,3,4}

Returns: "Possible"

One valid solution is to give the souvenirs with values 1 and 4 to her mother and the other two to her father. Each parent receives two souvenirs, and as 1+4 = 2+3, the total value is also the same for both parents.

1)
{1,1,1,3}

Returns: "Impossible"

There is no valid solution. Note that {1,1,1} and {3} is not a valid way to split the souvenirs: even though the total value is the same, the number of souvenirs is not.

2)
{1,1,2,3,5,8}

Returns: "Possible"

We have 1+1+8 = 2+3+5.

3)
{2,3,5,7,11,13}

Returns: "Impossible"

The sum of values is an odd number, so it is impossible.

4)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48}

Returns: "Possible"



5)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}

Returns: "Impossible"



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

class FoxAndSouvenirTheNext
{

	bool can(const vector<int> & value, const int S, int i, int c, int s) {
		if (c == value.size()/2 && S == s) return true;
		if (c > value.size()/2 || s > S) return false;
		bool ret = false;
		for (int j = i + 1; j < value.size(); ++j) {
			ret |= can(value, S, j, c + 1, s + value[j]);
		}
		return ret;
	}

	public:
	string ableToSplit(vector <int> value)
	{
		int sum = 0;
		for (const int & c:value) sum += c;
		int N = value.size();
		int M = sum/2;
		if (sum%2==0 && value.size()%2 == 0) {
			d_print(sum);
			d_print(value.size());
			vector<vector<int> > mem(N, vector<int>(M+1, 0));
			mem[0][value[0]] = 1;
			for (int i = 1; i < N; ++i) {
				for (int j = value[i]; j <= M; ++j) {
					if (mem[i-1][j-value] > 0) {
						mem[i][j] = mem[i-1][j-value] + 1;
					} else if ( j == value[i]) {
						if (mem[i][j] == 0) mem[i][j] =1 ;
					} else {
						mem[i][j] = mem[i-1][j];
					}
				}
			}

			//if (can(value, sum/2, 0, 1, value[0])) return "Possible";
			for (int i = 0; i < N; ++i) {
				if (mem[i][M] == N/2) return "Possible";
			}

		}
		return "Impossible";
	}
};
