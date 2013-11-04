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

class IPConverter 
{
	public:

	bool checkS( const string & s )
	{
		vecs lolz = expand( s, '.' );
		if( lolz.size( ) != 4 ) return false;
		FOREACH( i, lolz )
		{
			if( i->size( ) == 0 ) return false;
			int z = atoi( i->c_str( ) );
			if( z > 255 || z < 0 ) return false;
			if( (*i)[0] == '0' && i->size( ) != 1 ) return false;
		}
		return true;
	}

	vector <string> possibleAddresses(string ambiguousIP)
	{
		vector<string> ret;
		//if( ambiguousIP.size( ) != 7 ) return ret;
		if( ambiguousIP.size( ) == 0 ) return ret;
		//if( ambiguousIP.size( ) < 7 ) return ret;
		FORR( i, 1, ambiguousIP.size( )-2 )
		{
			FORR( j, i+1, ambiguousIP.size( ) )
			{
				FORR( k, j + 1, ambiguousIP.size( ) )
				{
					string b = ambiguousIP;
					b.insert( i, "." );
					b.insert( j+1, "." );
					b.insert( k+2, "." );
					cout<<b<<endl;
					if( checkS( b ) ) ret.push_back( b );

				}
			}

		}
		sort( ALL( ret ) );
		return ret;
	}
};

/* Lev A Neiman's coding here */


// Powered by FileEdit


// Powered by FileEdit
