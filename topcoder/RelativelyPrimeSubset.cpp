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

int gcd_mem[101][101];

//assume that a and b cannot both be 0
int GCD(int a, int b)
{
	if( gcd_mem[a][b] != 0 )
		return gcd_mem[a][b];
   if (b==0) return a;
   int ret = GCD(b,a%b);
   gcd_mem[a][b] = ret;
   return ret;
}

ull ullbit(int i)
{
	return ull(pow(2,i));
}

void printbits(vector<int>  S, ull  a)
{
	ostream & out = cout;
	//out<<a<<endl;
	int cnt = 0;
	for( int i = 0; i < S.size(); ++i )
	{
		if( a & ullbit(i) )
		{
			++cnt;
			//out<<i<<endl;
			out<<S[i]<<", ";
		}
	}
	//out<<"=================="<<endl;
	out<<endl<<cnt<<endl;
}

pair<ull,ull> solve( veci & S, int i, vector<pair<ull,ull> > & mem )
{
	if( mem[i].first != 0 )
		return mem[i];
	ull best = 0l;
	ull bestset = 0l;
	for( int j = i+1; j < S.size(); ++j )
	{
		if( GCD(S[i],S[j]) == 1 )
		{
			pair<ull,ull> tt = solve(S,j,mem);
			ull set = tt.second;
			ull cnt = tt.first;
			for( ull k = j; k < S.size(); ++k )
			{
				if( set & ullbit(k) )
				{
					if( GCD(S[i],S[k]) != 1 )
					{
						--cnt;
						set &= ~ullbit(k);
					}
				}
			}
			if( cnt > best )
			{
				bestset = set;
				best = cnt;
			}
		}
	}
	mem[i].first = 1+best;
	mem[i].second = bestset | ullbit(i);
	//cout<<mem[i].second<<endl;
	cout<<S[i]<<" : "<<mem[i].first<<" : ";
	printbits(S,mem[i].second);
	return make_pair(mem[i].first,mem[i].second);
}

class RelativelyPrimeSubset
{
	public:
	int findSize(vector <int> S)
	{
		sort(ALL(S));
		reverse(ALL(S));
		printbits(S,~0l);
		memset(gcd_mem,0,sizeof(gcd_mem));
		int ret = 0;
		ull bestm = 0;
		vector<pair<ull,ull> > mem;
		for( int i = 0; i < S.size(); ++i )
		{
			mem.push_back(make_pair(ull(0),ull(0)));
		}
		for( int i = S.size()-1; i >= 0; --i )
		{
			pair<ull,ull> tt = solve(S,i,mem);
			if( tt.first > ret )
			{
				bestm = tt.second;
				ret = tt.first;
			}
		}
		printbits(S,bestm);
		return ret;
	}
};
int SS[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
		17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
		32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
int SS2[] = {87, 1, 37, 21, 58, 49, 19, 11, 3, 30, 32, 42, 35, 69,
	56, 91, 92, 97, 89, 38, 51, 31, 14, 84, 46, 82, 23, 85,
	25, 78, 63, 7, 13, 10, 54, 75, 59, 60, 98, 53, 96, 8, 88,
	22, 74, 62, 67, 68, 100, 47};

int SS3[] ={48, 72, 65, 44, 76, 41, 43, 2, 79, 90, 22, 85, 47, 28,
		29, 9, 14, 50, 40, 46, 88, 92, 20, 19, 33, 6, 45, 53, 24,
		66, 51, 38, 16, 49, 13, 11, 71, 10, 89, 4, 73, 23, 64, 70,
		7, 5, 99, 86, 1, 63};

int main(int argc, char ** argv)
{
	RelativelyPrimeSubset prob;
#define in SS3
	veci S(in,in+sizeof(in)/sizeof(int));

	cout<<prob.findSize(S)<<endl;
}
