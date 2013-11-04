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


vector<string> expand( const string & input, string delimiters = " \t")
{
	#define string_find(del,k) ((del).find((k)) != string::npos)
	vector<string> out;
	size_t begin = 0;
	size_t i;
	for( i = 0; i < input.length( ); i++ )
	{
		if( i > 0 && string_find( delimiters, input[i] ) && !string_find( delimiters, input[i-1] ) )
		{
			out.push_back( input.substr( begin, i - begin ) );
			begin = i+1 ;
		}
		else
		{
			if( string_find( delimiters, input[i] ) ){ begin = i+1; }
		}
	}
	if( begin < i )
	{
		out.push_back( input.substr( begin ) );
	}
	return out;
}

bool cmp(const pair<pair<int,int>,int > & a, const pair<pair<int,int>,int > & b )
{
	return a.first.first < b.first.first;
}

int solve( vector<pair<pair<int,int>,int > > & orders, const int i, vector<int> & mem, vector<int> & mem2 )
{
//	cout<<i<<endl;
	if( mem[i] != -1 )
	{
		return mem[i];
	}
	int start = orders[i].first.first;
	int dur = orders[i].first.second;
	int end = start + dur;
	int price = orders[i].second;

	int ret = 0;

	int mj = -1;
	for( int j = i+1; j < orders.size(); ++j )
	{
		if( orders[j].first.first >= end )
		{
			ret = solve(orders,j,mem,mem2);
			break;
		}
	}

	ret += price;
	ret = max( ret, solve(orders,i+1,mem,mem2));

	mem[i]= ret;
	return mem[i];
}


int main( int argc, char ** argv )
{
	int T;
	cin>>T;
	for( int CASE = 0; CASE < T; ++CASE )
	{
		int N;
		cin>>N;
		vector<pair<pair<int,int>,int > > orders;
		for( int j = 0; j < N; ++j )
		{
			int a,b,c;
			cin>>a>>b>>c;
			orders.push_back(make_pair(make_pair(a,b),c));
		}
		sort(ALL(orders),cmp);
		//reverse(ALL(orders));

		vector<int> mem(N,-1);

		/*
		vector<int> mem2(N,-1);
		int answer = 0;
		for( int j = N-1; j >= 0 ; --j )
		{
			//cout<<"========"<<endl;
			answer = max(answer,solve(orders,j,mem,mem2));
		}
		cout<<answer<<endl;
		*/


		reverse(ALL(orders));

		mem[0] = orders[0].second;
		for( int i = 1; i < N; ++i )
		{
			int end = orders[i].first.first + orders[i].first.second;
			for( int j = i-1; j >= 0; --j )
			{
				if( orders[j].first.first >= end )
				{
					mem[i] = orders[i].second + mem[j];
					break;
				}
			}
			mem[i] = max(mem[i],mem[i-1]);
			mem[i] = max(mem[i],orders[i].second);
		}

		cout<<mem[N-1]<<endl;

	}

}
