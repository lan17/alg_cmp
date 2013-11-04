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

#define d_print(x) { if(print_dbg){  cerr << __LINE__ << " " << #x << "\t=\t" << x << endl; cerr.flush(); } }

typedef vector<string> vecs;
typedef vector<int> veci;
typedef unsigned long long ull;
typedef long long ll;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

string dbg = "                                      ";

class SurveillanceSystem
{

	void pStr( string & s, ull mask, char c )
	{
		for( int i = 0; i < s.size(); ++i )
		{
			if( mask & (1 << i) && s[i] != '+')
			{
				s[i] = c;
			}
		}
	}
	string pMask( ull mask, char c )
	{
		string t = dbg;
		pStr( t, mask, c );
		return "'"+t+"'";
	}

	public:
	string getContainerInfo(string containers, vector <int> reports, int L)
	{


		int NR = reports.size();
		int N = containers.size();
		dbg = containers;
		for( int i = 0; i < N; ++i ) dbg[i] = ' ';

		vector<ull> allCovers;

		for( int i = 0; i < NR; ++i )
		{


			int num = reports[i];
			for( int j = 0; j + L <= N; ++j )
			{
				int cnt = 0;
				ull cover=0;
				for( int jj = j; jj < j + L; ++jj )
				{
					if( containers[jj] == 'X' )
					{
						++cnt;
					}
					cover |= ull(1)<<jj;
				}
				if( cnt == num )
				{

					allCovers.push_back(cover);
				}
			}

		}

		d_print("-----");
		string ret;
		for( int i = 0; i < N; ++i ) ret += '-';
		veci cunt(N,0);
		for( int i = 0; i < allCovers.size(); ++i )
		{
			for( int j = 0; j < N; ++j )
			{
				if( allCovers[i] & (1<<j))
					cunt[j]++;
			}
		}
		for(int i = 0; i < cunt.size(); ++i )
		{
			if( cunt[i] == 1 ) ret[i] = '?';
			if( cunt[i] > 1 ) ret[i] = '+';
		}

		return ret;

	}
};
