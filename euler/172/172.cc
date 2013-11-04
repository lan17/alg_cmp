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

#define LIM 18

//map<pair<vector<char>, int >, ull > mem;
map<vector<char>, ull > mem;

ull count( vector<char> & nums, int dig )
{
	if( dig >= LIM )
		return 1;

	//pair<vector<char>, int > key = make_pair(nums,dig);
	if( IN(mem,nums))
		return mem[nums];

	ull answer = 0;
	for( int i = 0; i <=9; ++i )
	{
		if( nums[i] == 3 ) continue;
		vector<char> t = nums;
		t[i]++;
		answer += count( t, dig + 1 );
	}
	mem[nums] = answer;
	return answer;
}

int main( int argc, char ** argv )
{
	vector<char> nums(10,0);
	ull answer = 0;
	for( int i = 1; i < nums.size(); ++i )
	{
		vector<char> t = nums;
		t[i] = 1;
		answer += count(t,1);
	}
	cout<<mem.size()<<endl;
	cout<<answer<<endl;
}
