// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Prince Gogo is the charming prince of the Kingdom of Ducks, where slimes and ducks live in peace and harmony.

Today, Prince Gogo purchased N toastbooks, numbered 0 through N-1. Each toastbook contains some knowledge and grants it to the person who eats it. It is known that no two toastbooks contain the same knowledge.

Initially, Gogo doesn't know any of the knowledge inside the toastbooks. He intends to eat them all and gain as many pieces of knowledge as possible. Furthermore, some of the books require a specific piece of knowledge in order to understand its knowledge. This will be given as a vector <int> prerequisite. If there is no required knowledge to understand the toastbook number i, prerequisite[i] will be -1.
Otherwise, prerequisite[i] will be the number of the toastbook that contains the knowledge necessary to understand book i. If Gogo eats some book x without having the required knowledge, he will not gain the knowledge inside the book, even if he later gains the knowledge from the book prerequisite[x].

Unfortunately, Gogo forgot to number the toastbooks when he purchased them. Hence, he is forced to eat all N toastbooks in a random order. Return the expected number of toastbooks that Gogo will understand.

DEFINITION
Class:PrinceXToastbook
Method:eat
Parameters:vector <int>
Returns:double
Method signature:double eat(vector <int> prerequisite)


NOTES
-The expected value of a random variable can be imagined as the average value of very many independent experiments.
-The returned value must have an absolute or relative error less than 10^-9.


CONSTRAINTS
-prerequisite will contain between 2 and 50 elements, inclusive.
-Each element of prerequisite will be between -1 and N-1, inclusive, where N is the number of elements in prerequisite.
-For all i, prerequisite[i] will not be i.


EXAMPLES

0)
{-1, 0}

Returns: 1.5

There are only two possible orders. If Gogo eats book 0 first, he
gains the knowledge in both books. If Gogo eats book 1 first, he
lacks the required knowledge to understand the book 1 when he read it. Hence, he will
only gain the knowledge in book 0. Therefore, the expected number
of books that Gogo will understand is the average of the two, which
is 1.5.

1)
{-1, 0, 1}

Returns: 1.6666666666666667

There are 6 possible orders. The number of books understood is as follows:
0, 1, 2: 3
0, 2, 1: 2
1, 0, 2: 1
1, 2, 0: 1
2, 0, 1: 2
2, 1, 0: 1

Hence, the expected number of books that Gogo will understand is their average, which is (3+2+1+1+2+1)/6 = 10/6.

2)
{1, -1, 1}

Returns: 2.0



3)
{1, 0}

Returns: 0.0

Each book has the other book as a prerequisite. Gogo will not be able to understand either one, regardless of the order in which he eats them.

4)
{-1, -1}

Returns: 2.0



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

int computeDepth( const vector<int> & P, vector<bool> & vis, vector<int> & depth, int i )
{
	d_print(P<<" "<<" "<<vis<<" "<<depth<<" "<<i);
	int ret = 1;
	if( vis[i] ) ret = -1;
	else
	{		
		vis[i] = true;
		if( depth[i] > -1 ) return depth[i];
		if( P[i] != -1 )
		{
			int a = computeDepth(P,vis,depth,P[i]);
			if( a != -1 ) ret = 1 + a;
			else ret = a;
		}
	}
	depth[i] = ret;
	return ret;
}

class PrinceXToastbook
{
	public:
	double eat(vector <int> P)
	{
		auto rootCnt = 0; 
		auto N = P.size();
		vector<int> depth(N,-1);
		FOREACH(i,P)if(*i==-1)++rootCnt;
		for( int i = 0; i < N; ++i )
		{
			vector<bool> vis(N,false);
			computeDepth(P,vis,depth,i);
		}

		if(rootCnt==0)return 0;
		if(rootCnt==P.size()) return (double)P.size();

		double answer = 0;
		d_print( answer<< " " << depth );
		FOREACH(i,depth)
		{
			if( *i != -1 )
			{
				int ii = *i;
				double tt = 1;
				while( ii > 1 )
				{
					tt /= ii;
					--ii;
				}
				answer += tt;
			}
		}
		return answer;
	}
};
