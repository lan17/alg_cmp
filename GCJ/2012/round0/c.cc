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
string toString( const T & a )
{
	stringstream s;
	s<<a;
	return s.str();
}

int c(int n, int A, int B )
{
	int ret = 0;
	string N = toString(n);
	set<int> nums;
	for( int i = 0; i <= N.size(); ++i )
	{
		string a,b,c;
		a = N.substr(0,i);
		b = N.substr(i);
		c = b + a;
		int C = atoi(c.c_str());
		if( C > n && C <= B )
		{
		//	++ret;
			nums.insert(C);
		}
	}
	return nums.size();
}




int main( int argc, char ** argv )
{
	int T;
	cin>>T;
	for( int CASE=1; CASE <=T; ++CASE )
	{
		int A,B;
		cin>>A>>B;
		int ans = 0;
		for( int i = A; i <= B; ++i )
		{
			ans += c(i,A,B);
		}

		cout<<"Case #"<<CASE<<": "<<ans<<endl;
	}
}
