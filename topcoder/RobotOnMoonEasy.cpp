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
#define FOR(i,n) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR(i,s,e) for( int (i) = (s); (i) <= (e); ++(i))

template<class T>
ostream & operator <<(ostream & os, const vector<T> & v )
{
	os<<"[ ";
	for( int i = 0; i < v.size(); ++i )
	{
		os<<v[i]<<", ";
	}
	os<<"]";
	return os;
}

template<class T>
ostream & operator <<(ostream & os, const vector<T> * v )
{
	os<<*v;
	return os;
}

template<class K, class V>
ostream & operator <<(ostream & os, const map<K,V> & a )
{
	os<<"{ ";
	FOREACH(i,a)
	{
		os<<i->first<<": "<<i->second<<", ";
	}
	os<<"}";
	return os;
}

template<class K, class V>
ostream & operator <<(ostream & os, const pair<K,V> & a )
{
	os<<"[ "<<a.first<<", "<<a.second<<" ]";
	return os;
}

vector<string> expand( const string & input, string delimiters = " 	")
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


class RobotOnMoonEasy
{
	void move(char c, int & x, int & y)
	{
		switch(c){
			case 'U':
				y--;
				break;
			case 'D':
				y++;
				break;
			case 'L':
				x--;
				break;
			case 'R':
				x++;
		}
	}

	public:
	string isSafeCommand(vector <string> board, string S)
	{
		int x,y;
		const int Y = board.size();
		const int X = board[0].size();
		for (int i = 0; i < Y; ++i) for(int j = 0; j < X; ++j) if (board[i][j] == 'S') { x = j; y = i; break;}
		for (const char & c : S) 
		{
			int nx=x,ny=y;
			move(c,nx,ny);
			if (nx < 0 || nx >= X || ny < 0 || ny >= Y) return "Dead";
			if (board[ny][nx] != '#') 
			{
				x = nx;
				y = ny;
			}
			cerr<<"=="<<endl;
			d_print(x);
			d_print(y);
		}
		return "Alive";

	}
};


// Powered by FileEdit
