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

#define vecs vector< string > 

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

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

bool isLetter( char & c )
{
	if( c >= 65 && c <= 90 ) return true;
	if( c >= 97 && c <=122 ) return true;
	return false;
}

int countWord( string & word )
{
	int size = word.size( );
	if( size == 0 ) return 0; 
	if( !isLetter( word[0] ) )return 0;
	FOR( i, size - 1 )
	{
		if( !isLetter( word[i] ) ) return 0;
	}
	if( isLetter( word[size-1] ) ) { return size; }
	if( word[size-1] == '.' ) { return size - 1; }
	return 0;
}



class HowEasy 
{
	public:
	int pointVal(string param0)
	 {
		vecs tokens = expand( param0, ' ' );
		int words = 0;
		int sum = 0;
		FOREACH( i, tokens )
		{
			int tmp = countWord( *i );
			if( tmp != 0 ) words++;
			sum += countWord( *i );
		}
		if ( words == 0 )
		{
			return 250;
		}
		int average = sum / words;
		cout<<sum<<"/"<<words<<"="<<average<<endl;
		
		if ( average <= 3 )
		{
			return 250;
		}
		if ( average == 4 || average == 5 )
		{
			return 500;
		}
		if ( average >= 6 )
		{
			return 1000;
		}




		
	}
};

/* Lev A Neiman's coding here */


// Powered by FileEdit
