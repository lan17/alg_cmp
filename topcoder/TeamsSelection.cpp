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


template <typename T>
ostream & operator <<(ostream & os, const vector<T> & v )
{
	os<<"[ ";
	for( int i = 0; i < v.size(); ++i ) os<<v[i]<<", ";
	os<<"]";
	return os; 
}

class TeamsSelection
{
	public:
	string simulate(vector <int> preference1, vector <int> preference2)
	{
		int n = preference1.size();
		set<int> picked;
		string ret;
		ret.insert(0,n,'x');
		int i,j,t;
		i=j=0;
		t = -1;
		while( i < n && j < n )
		{
			int & k = t == -1 ? i : j;
			vector<int> & p = t == -1 ? preference1 : preference2;	
			while( IN(picked,p[k] )) ++k;
			picked.insert(p[k] );
			ret[p[k]-1] = t == -1 ? '1' : '2';
			t *= -1;
		}
		return ret;
	}
};
