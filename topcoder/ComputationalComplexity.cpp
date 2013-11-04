#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <cstdio>
#include <valarray>      
#include <ext/hash_set> 
#include <ext/hash_map>
#include "float.h"

#define vecs vector< string > 
#define veci vector< int >
#define vecsi vector<string>::iterator
#define vecii vector<int>::iterator

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define pnt(x) cout<<#x<<" = "<<(x)<<endl;

#define FMAX DBL_MAX
#define FMIN DBL_MIN

using namespace std;


class ComputationalComplexity 
{
	public:

	double func( veci & constant, veci & power, veci & logPower, int N, int i )
	{
		return constant[i]*pow(((double)N),(double)power[i])*pow(log((double)N),(double)logPower[i]);
	}
	
	int fastestAlgo(vector <int> constant, vector <int> power, vector <int> logPower, int N)
	 {
		double z = FMAX;
		int ret = 0;
		FORR( i, 0, constant.size( ) - 1 )
		 {
			double v = func( constant, power, logPower, N, i );
			if( z > v ) 
			 {
				z = v;
				ret = i;
			 }
		 }
		 return ret;
		
	}
};

/* Lev A Neiman's coding here */
