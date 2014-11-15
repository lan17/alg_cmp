// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
//
"Němec's quadratic law: how many minutes the teacher was late to the lesson, that many minutes squared he'll end the lesson earlier."



In other words, if the teacher is t minutes late (for some non-negative integer t), he should end the lesson t2 minutes early. Of course, this means the teacher can't be too late, because a lesson can't end before even starting. It is, however, possible for the teacher to arrive and end the lesson immediately (in fact, he then only arrives to tell the students that the lesson's cancelled).



You're given a long long d. The lesson was supposed to take d minutes. Compute and return the largest non-negative integer t such that the teacher can be t minutes late.


DEFINITION
Class:QuadraticLaw
Method:getTime
Parameters:long long
Returns:long long
Method signature:long long getTime(long long d)


CONSTRAINTS
-d will be between 1 and 1,000,000,000,000,000,000, inclusive.


EXAMPLES

0)
1

Returns: 0

The lesson was supposed to take 1 minute. The teacher can only be 0 minutes late, in which case he ends the lesson 0 minutes early (i.e. he arrives and ends the lecture on time).

1)
2

Returns: 1

It's possible for the teacher to be 1 minute late and end the lecture 1 minute early (so there's no lecture at all).

2)
5

Returns: 1



3)
6

Returns: 2



4)
7

Returns: 2



5)
1482

Returns: 38



6)
1000000000000000000

Returns: 999999999



7)
31958809614643170

Returns: 178770270



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

#define d_print(x) { if(print_dbg){  cerr << __LINE__ << " " << #x << " =\t" << x << endl; cerr.flush(); } }

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

class QuadraticLaw
{
	bool can(ull d, ull t)
	{
		ull tt = t + t*t;
		d_print(t);
		d_print(tt);
		d_print(d);
		return tt <= d;
	}

	public:
	long long getTime(long long d)
	{
		ull a = 0, b = sqrt(d)+1;
		while (a < b)
		{
			ull c = (a+b)/2;
			if (can(d,c))
			{
				if (c == a)
				{
					break;
				}
				a = c;
			}
			else
			{
				if (b == c)
				{
					break;
				}
				b = c;
			}
			d_print(a);
			d_print(b);
			d_print(c);
			d_print("<<<");
		}
		return a;
	}
};
