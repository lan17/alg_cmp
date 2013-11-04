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

#define vecs vector< string > 
#define veci vector< int >
#define vecsi vector<string>::iterator
#define vecii vector<int>::iterator

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

int howManyDigits( int num )
{
	int k = 0;
	while (num != 0)
	{
		num /= 10;
		k++;
	}
	return k;
}

class ConcatenateNumber 
{
	public:
	int getSmallest(int number, int k)
	{
		if( number % 2 != 0 && k % 2 == 0 ) return -1;
		if( number % k == 0 ) return 1;
		unsigned long long lolz = number;
		int c = 2;
		unsigned long long how = howManyDigits( number );
		cout<<how;
		while( lolz < 1.844674407e19 )
		{
			lolz = lolz*10^how + number;
			if( lolz % k == 0 ) return c;
			c++;
		}
		return -1;

		
	}
};

/* Lev A Neiman's coding here */
