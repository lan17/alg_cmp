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

int main( int argc, char ** argv )
{
	while(true)
	{
		int X[4] ={-1,-1,-1,-1};
		int Xp[4] = {-1,-1,-1,-1};
		int B[4] = {0,0,0,0};
		for( int i = 0; i < 4; ++i )
			cin>>X[i];
		for(int i = 0; i < 4; ++i )
			cin>>Xp[i];
		if( X[0] == -1 ) break;

		while(true)
		{
			bool done = true;
			for( int i = 0; i < 4; ++i )
			{
				if( X[i] != 0 )
					done = false;
			}
			if( done ) break;

			for( int i = 0; i < 4; ++i )
			{
				if( Xp[i] > X[i] )
				{
					B[i] += Xp[i] -X[i];
				}
				X[i] -= Xp[i];
				if( X[i] < 0 ) X[i] = 0;
			}
		}
		for( int i = 0; i < 4; ++i )
		{
			cout<<B[i]<< " ";
		}
		cout<<endl;

	}

}
