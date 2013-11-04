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

string findB( string s )
{
	int seen = 0;
	string solution = "";
	solution += s[s.size()-1];
	seen |= 1<<(s[s.size()-1]-'a');

	for( int i = s.size() - 2; i >= 0; --i )
	{
		int m = 1 << (s[i]-'a');
		if( seen & m )
		{
			//d_print(i);
			//d_print(s[i]);
			//d_print(solution[0]);
			//d_print(solution);
			string tt = solution;
			tt.erase(solution.find(s[i]),1);
			tt = s[i] + tt;
			if( !lexicographical_compare(ALL(tt),ALL(solution)))
			{
				solution = tt;
			}
		}
		else
		{
			seen |= m;
			solution = s[i] + solution;
		}
	}
	return solution;
}

string solve(string s) {
	string res = "";
	while (s.size() > 0) {
		printf("%s\n", s.c_str());
		int mask = 0; int used = 0;
		int best_char = 'a'; int best_used = 0;
		int n = s.size();
		for (int i = n-1; i >= 0; i--) {
			if (!(mask & (1<<(s[i]-'a')))) {
				mask |= 1 << (s[i]-'a');
				used++;
			}
			if (best_used < used || best_used == used && s[i] > best_char) {
				best_used = used;
				best_char = s[i];
			}
		}
		string next = "";
		for (int i = 0; i < n; i++) {
			if (s[i] != best_char)
				next += s[i];
		}
		res += best_char;
		s = next;
	}
	return res;
}





int main( int argc, char ** argv )
{
	string s;
	getline(cin,s);
	s.erase(s.find_last_not_of(" \n\r\t")+1);
	cout<<findB(s)<<endl;;

}
