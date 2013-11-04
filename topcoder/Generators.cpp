#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <cstdio>
#include <valarray>      
#include <ext/hash_set> 
#include <ext/hash_map>
#include "float.h"

#define FMAX DBL_MAX
#define FMIN DBL_MIN

#define vecs vector< string > 
#define veci vector< int >
#define vecsi vector<string>::iterator
#define vecii vector<int>::iterator

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define pnt(x) cout<<#x<<" = "<<(x)<<endl;

using namespace std;

void printVeci( veci & lol )
{
	FOREACH( i, lol )
	{
		cout<<*i<<" ";
	}
}

class Generators 
{
	public:
	vector<double> * zp;

	Generators ( )
	{
		zp = NULL;
	}

	vector<double> * ZP( int a, int p )
	{
		zp = new vector<double>(p-1, 0.0 );
		(*zp)[0]=1;
		FORR( i, 1, p-2 )
		{
			(*zp)[i] = pow( (double)a, (double)i ) % p;
		}
		
		cout<<a<<" =  ";
		printVeci( *zp );
		cout<<endl;
		sort( ALL( *zp ) );
		return zp;
	}

	bool compare( vector<double> & v1, vector<double> & v2 )
	{
		FOR( i, v1.size( ) )
		{
			if( v1[i] != v2[i] ) return false;
		}
		return true;
	}

	
	vector <int> find(int p)
	{
		vector<double> realZp( p-1, 0.0 );
		FORR( i, 1, p )
		{
			realZp[i-1] = i;
		}
		veci answerz;
		FORR( i, 2, p)
		{
			if( zp != NULL ) delete zp;
			ZP( i, p );
			if( compare( realZp, * zp ) ) answerz.push_back( i );
		}
		return answerz;
		
	}
}; 

/* Lev A Neiman's coding here */
