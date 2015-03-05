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
ostream & operator <<(ostream & os, const vector<vector<T> > & v)
{
	for (int i = 0; i < v.size(); ++i) {
		os<<v[i]<<endl;
	}
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
		sort(ALL(value));
		int sum = 0;
		for (const int & c:value) sum += c;
		int N = value.size();
		int M = sum/2;
		d_print(M);
		if (sum%2==0 && value.size()%2 == 0) {
			d_print(sum);
			d_print(value.size());
			vector<vector<int> > mem(N, vector<int>(M+1, 0));
			mem[0][value[0]] = 1;
			for (int i = 1; i < N; ++i) {
				for (int j = value[i]; j <= M; ++j) {
					int mm = M;
					for (int ii = 0; ii <i; ++ii) {
						int iimm = mem[ii][j-value[i]];
						if (iimm > 0 )mm = min(mm, iimm);
					}
					//if (mem[i-1][j-value[i]] > 0) {
					//	mem[i][j] = mem[i-1][j-value[i]] + 1;
					if (mm < M) {
						mem[i][j] = mm + 1;
					} else if ( j == value[i]) {
						if (mem[i][j] == 0) mem[i][j] =1 ;
					} else {
						mem[i][j] = mem[i-1][j];
					}
				}
			}
//{{3, 26, 28, 15, 15, 25}}
//			{{1, 2, 3, 5, 6, 7}}
			d_print(mem);
			//if (can(value, sum/2, 0, 1, value[0])) return "Possible";
			for (int i = 0; i < N; ++i) {
				if (mem[i][M] == N/2) return "Possible";
			}

		}
		return "Impossible";
	}
};


// Powered by FileEdit
