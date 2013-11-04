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

pair<double,double> var( vector<double> & poz, vector<int> & v, double t )
{
	double sm,lr;
	sm = 1e9;
	lr = sm * -1.0;
	double m = 0;
	for( size_t i = 0; i < v.size(); ++i )
	{
		double pozi = poz[i] + v[i] * t;
		m += pozi;
		sm = min( sm, pozi );
		lr = max( lr, pozi );
	}
	m /= (double)v.size();

	double vr = 0;
	for( size_t i = 0; i < v.size(); ++i )
	{
		double pozi = poz[i] + v[i] * t;
		vr += pow( pozi - m, 2 );
	}
	vr /= (double)v.size();
	return make_pair(vr,lr-sm);
}

class Mosquitoes {
	public:
	int getMaximum(vector <int> xInit, vector <int> v, int R) 
	{
		size_t N = v.size();
		double r = (double)R;
		vector<double> poz(N,0.0);
		for( size_t i = 0; i < N; ++i ) poz[i] = (double)xInit[i];
		
		double at = 0;
		double bt = 100;
		double dt = 0.5;

		pair<double,double> a = var( poz, v, at );
		pair<double,double> ap = var( poz, v, at + dt );

		bool inc = a.first < ap.first;
		double mvt = a.first;
		double mt = 0;

		for( double tt = at+dt; tt <= bt; tt += dt )
		{
			a = var( poz, v, tt );
			cout<<a.first<<"\t"<<a.second<<"\t"<<tt<<endl;
			if( a.first < mvt )
			{
				mvt = a.first;
				mt = tt;
			}
		}
		cout<<mt<<endl;

	}
};
