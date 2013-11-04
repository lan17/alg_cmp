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
#define db(x) cout<< #x<<" = "<< (x)<<endl;

using namespace std;


class FingerCounting 
{
	public:
	int maxNumber(int weakFinger, int maxCount)
	 {
		if( weakFinger == 1 && maxCount == 0 ) return 0;
		if( weakFinger > 1 && maxCount == 0 ) return weakFinger - 1;
		int sum = 0;
		int wnum = 0;
		int f = 1;
		bool i = true;
		while( ((wnum != maxCount+1) && maxCount > 2 )||((wnum!=maxCount)&&maxCount<=2) )
		 {
			db(f) ;
			sum++;
			if( i )
			 {
				if( f != 4 )f++;
				else{
					f++;
					i = false;
				}
			 }
			 else
			 {
			if( !i )
			{
				if( f != 2 ) f--;
				else
				{
					f--;
					i = true;
				}
			}
			 }
			if( f == weakFinger )
			 {
				wnum++;
				db( wnum );
			 }
		}
		return sum;
			
		
	}
};

/* Lev A Neiman's coding here */


// Powered by FileEdit


// Powered by FileEdit
