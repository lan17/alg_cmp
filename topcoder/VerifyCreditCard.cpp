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

#define ld long double
#define ll long long
#define ull unsigned long long

#define vecs vector< string > 
#define veci vector< int >
#define vecsi vector<string>::iterator
#define vecii vector<int>::iterator
#define vec vector

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define pnt(x) cout<<#x<<" = "<<(x)<<endl;

using namespace std;

int sumD( int i )
{
	stringstream s;
	s<<i;
	string l = s.str( );
	int ret = 0;
	FOREACH( c, l )
	{
		ret += *c - 48;
	}
	return ret;
}

class VerifyCreditCard 
{
	public:
	string checkDigits(string cardNumber)
	 {
		int sum = 0;
		for( int i = 0; i < cardNumber.size( ); ++i )
		{
			if( cardNumber.size( ) % 2 == 0 )
			{
				if( i % 2 == 0 ) 
				{
					sum += sumD( ( cardNumber[i] - 48 ) *2 );
				}
				else sum += cardNumber[i] - 48;
			}
			if( cardNumber.size( ) % 2 != 0 )
			{
				if( i % 2 != 0 ) 
				{
					sum += sumD( ( cardNumber[i] - 48 ) *2 );
				}
				else sum += cardNumber[i] - 48;
			}
		}
		if( sum %10 == 0 ) return "VALID"; 
		else return "INVALID";
	}
};

/* Lev A Neiman's coding here */
