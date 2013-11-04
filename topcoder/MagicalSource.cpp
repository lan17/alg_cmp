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

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define print(x) cout<<#x<<" = "<<(x)<<endl;

long long * powers = new long long[13];


using namespace std;

void printv(vector<int> & v)
{
	FOREACH( i,v)cout<<*i<<" ";
	cout<<endl;
}

bool isMagicSource( long long x, long long source )
{
	if(source==0)return false;
	long long sum = source;
	int i = 0;
	while( sum <= x )
	{
		if( x == sum ) return true;
		sum += source * powers[i++];
	}
	return false;
}

long long digitz2numba(vector<int>&digitz)
{
	long long ret = 0;
	for( int i = 0; i < digitz.size(); ++i)
	{
		ret += digitz[i]*(long long)pow(10,(double)i);
	}
	return ret;
}

class MagicalSource
{
	public:
		long long calculate( long long x )
		{
			for (int i = 1; i <= 13; ++i)
			{
				powers[i - 1] = (long long) pow( 10, (double) i );
			}
			stringstream s;
			s << x;
			string sstr = s.str();
			int n = sstr.size();

			for( int i = n; i >= 0; --i )
			{
				long long t = 0;
				for( int j = 0; j <=i; ++j )
				{
					t += 1 * (long long )pow(10,(double)j);
				}
				cout<<t<<endl;
				if( x % t == 0 ) return x / t;
			}

			return -1;

			int * digits = new int[n];
			for( int i = 0; i < n; ++i )
			{
				digits[i]=sstr[n-1-i]-48;
			}
			/*
			for( int i = 0; i < n;++i)
			{
				cout<<digits[i]<<" ";
			}
			cout<<endl;
			*/

			/*
			// LOL BRUTE FORCE 2 DA XTREME!
			for( long long i = x %10 ; i < x; i*=10)
			{
				if( isMagicSource(x,i))return i;
			}
			*/

			// OMG MATHS!
			for (int i = 0; i < n; ++i)
			{
				vector<int> s(i+1,0);
				s[0]=digits[0];

				for (int j = 1; j <= i; ++j)
				{
					s[j]=digits[j];
					int ps=0;
					for( int i1 = j-1; i1>=0;--i1)
					{
						ps+=s[i1];
						for( int j1=j-2; j1 >=0; --j1 )
						{
							for( int i2=j1; i2 >= 0; --i2)
							{
								ps+=s[i2]/10;
							}
						}
					}
					s[j]-=ps;
					s[j]%=10;
				}
				cout<<"======================"<<endl;
				printv(s);
				long long numba = digitz2numba(s);
				cout<<numba<<endl;
				cout<<"======================"<<endl;


				if( isMagicSource(x,numba))return numba;
			}

		}
};
