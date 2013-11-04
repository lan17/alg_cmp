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

vecs expand( const string & input, char delimiter )
{
     vecs out;
     int begin = 0;
     int i;
     for( i = 0; i < input.length( ); i++ )
     {
          if( i > 0 && input[i] == delimiter && input[i-1] != delimiter ) 
          { 
              out.push_back( input.substr( begin, i - begin ) ); 
              begin = i+1 ;
          }
          else
          {
              if( input[i] == delimiter ){ begin = i+1; }
          }
     }
     if( begin < i )
     {
         out.push_back( input.substr( begin ) );
     }
     return out;
}

void printVVd( vec<vec<ld> > & data )
{
	FOREACH( i, data )
	{
		FOREACH( j, *i )
		{
			cout<<*j<<" ";
		}
		cout<<endl;
	}
	cout<<"====================="<<endl;
}

class DiscountCombination 
{
	public:
	double minimumPrice(vector <string> discounts, int price)
	{
		vec<vec<ld> > data( 4, vec<ld>() );
		FOREACH( d, discounts )
		{
			vecs t = expand( *d, ' ' );
			int cost = atoi( t[0].c_str( ) );
			int percentage = atoi( t[1].c_str( ) );
			data[percentage].push_back( cost );
		}
		//printVVd( data );
		FORR( i, 1, 3 )
		{
			data[i].push_back( 0 );
			sort( ALL( data[i] ) );
		}
		printVVd( data );
		FORR( i, 1, 3 )
		{
			ld sum = 0.0;
			FOREACH( cost, data[i] )
			{
				sum = *cost = sum + * cost;
			}
		}
		printVVd( data );
		ld ret = (ld)price;
		FOR( a, data[1].size( ) )
			FOR( b, data[2].size( ) )
				FOR( c, data[3].size( ) )
				{
					ld cost = price * pow( 0.99, (double)a ) * pow( 0.98,(double) b ) * pow( 0.97,(double) c ) + data[1][a] + data[2][b] + data[3][c];
					if( ret > cost ) ret = cost;
				}
		
		
		return ret;


	}
};

/* Lev A Neiman's coding here */



// Powered by FileEdit
