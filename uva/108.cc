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
#include <iomanip>

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

template <class T>
ostream & operator <<(ostream & os, const vector<T> & a )
{
	os<<"{ ";
	for( int i = 0; i < a.size(); ++i )
	{
		os<<a[i]<<", ";
	}
	os<<"}";
	return os;
}

inline void tD( int x, int N, int &  i, int & j)
{
	i = x / N;
	j = x % N;
}

inline int oD( int N, int i, int j )
{
	return i * N + j;
}


int main( int argc, char ** argv )
{
	int N;
	cin>>N;
	vector<int> G(N*N,0);
	vector<int> S(N*N,0);
	for( int i = 0; i < N*N;++i)
	{
		cin>>G[i];
		if( i % N == 0 && i > 0) S[i] = G[i];
		else S[i] += G[i] + S[i-1];
	}

	int ret = -10000;
	for( int i = 0; i < N*N; ++i )
	{
		for( int j = i + 1; j < N*N; ++j )
		{
			d_print("COCK");
			d_print(i);
			d_print(j);
			int sum = 0;
			int dd = (j%N)-(i%N);
			for( int k = i/N; k <= j/N; ++k )
			{
				sum += S[i+k*N+dd] - S[i+k*N];
			}

			d_print(sum);
			ret = max(sum,ret);
		}
	}
	d_print(G);
	d_print(S);
	cout<<ret<<endl;
}
