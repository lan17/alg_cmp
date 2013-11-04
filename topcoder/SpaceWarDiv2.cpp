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

bool cmp(const pair<int,int> & a, const pair<int,int> & b)
{
	return a.first < b.first;
}

template<class T>
int indexOfSmallestElement( const vector<T> & a)
{
	if( a.size() == 0 ) return -1;
	T val= a[0];
	int ret = 0;
	for( int i = 1; i < a.size(); ++ i )
	{
		if( val < a[i] )
		{
			val = a[i];
			ret = i;
		}
	}
	return ret;
}


class SpaceWarDiv2
{
	public:
	int minimalFatigue(vector <int> gS, vector <int> eS, vector <int> eC)
	{
		int N = gS.size();
		int M = eS.size();
		vector<ull> F(N,0);
		vector<pair<int,int> > enemy;
		for( int i = 0; i < M; ++i )
			enemy.push_back(make_pair(eS[i],eC[i]));
		sort(ALL(enemy),cmp);
		reverse(ALL(enemy));
		sort(ALL(gS));
		reverse(ALL(gS));
		map<int,vector<int> * > enemy2girl;
		map<int,vector<int> * > girl2enemy;
		for(int i = 0; i < M; ++i )
		{
			enemy2girl[i] = new vector<int>();
			for( int j = 0; j < N; ++j )
			{
				if( girl2enemy[j] == NULL )
					girl2enemy[j] = new vector<int>();
				if( enemy[i].first <= gS[j] )
				{
					enemy2girl[i]->push_back(j);
					girl2enemy[j]->push_back(i);
				}
			}
		}
		for( int i = 0; i < M; ++i )
		{
			vector<int> & girls = * enemy2girl[i];
			if( girls.size() == 0 )
			{
				return -1;
			}
			ull sum = 0;
			FOREACH(g,girls) sum += F[*g];
			sum += enemy[i].second;
			ull toAdd = sum / girls.size();
			ull modAdd = sum % girls.size();
			FOREACH(g,girls) F[*g] += toAdd;
			F[girls[girls.size()-1]] += modAdd;

		}
		cout<<enemy<<endl;
		cout<<F<<endl;
		cout<<enemy2girl<<endl;
		return F[indexOfSmallestElement(F)];
	}
};
