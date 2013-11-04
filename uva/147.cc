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

const int N = 12;
int LIM = 30001/5;

int main( int argc, char ** argv )
{
	int coins[N]= {10000,5000,2000,1000,500,200,100,50,20,10,5,0};
	ull mem[N+1][LIM];

	reverse(coins,coins+N);
	for( int i = 0; i < N; ++i )coins[i] /=5;
	memset(mem,0,sizeof(mem));
	for( int t = 0; t <= LIM; ++t )
	{
		for( int i = 1; i < N; ++i )
		{
			if( t == 0) mem[i][t] = 1;
			else if( i == 0 ) mem[i][t] = 0;
			else if( coins[i] > t ) mem[i][t] = mem[i-1][t];
			else mem[i][t] = mem[i-1][t] + mem[i][t-coins[i]];
		}
	}
	double t;
	while(true)
	{
		cin>>t;
		if( t == 0.0 ) break;

		int T = (int)(t*100);
		T /=5;

		/*
		d_print(T);

		for( int i = 0; i <= N; ++i )
		{
			for( int j = 0; j <= T; ++j )
			{
				cout<<mem[i][j]<<" ";
			}
			cout<<endl;
		}
	*/
		printf ("%6.2lf%17.lld\n", t, mem[N-1][T]);
		//cout<<t<<"\t"<<mem[N-1][T]<<endl;
		//cout<<"===="<<endl;
	}

}
