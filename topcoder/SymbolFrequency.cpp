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

bool isLetter( const char & a )
{
	if( a >= 65 && a <= 90 ) return true;
	if( a >=97 && a <= 122 ) return true;
	return false;
}

void populate( string & language, map<char,int> & lang )
{
	for( int i = 0; i < language.size( ); i += 3 )
	{
		int percentage = atoi( language.substr( i+1, 2 ).c_str( ) );
		lang[language[i]] = percentage;
	}
	cout<<endl;
}

double diviation( map< char, int > & language, map< char, int > & letter_count, int & text_count )
{
	double ret = 0;
		FORR( j, 97, 122 )
		{
			double expected = ((double)language[j]/100.0)*(double)text_count;
			double diff = fabs( expected - (double)letter_count[j] );
			ret += diff*diff;
		}
	
	return ret;
}

class SymbolFrequency 
{
	public:
	double language(vector <string> frequencies, vector <string> text)
	{
		map<char, int> letter_count;
		vector< map< char, int > > languages;
		vector< double > div;
		FOREACH( i, frequencies )
		{
			map<char, int> lang;
			FORR( j, 97, 122 )
			{
				lang[j] = 0;
			}
			populate( *i, lang );
			languages.push_back( lang );
		}
		FORR( i, 97, 122 )
		{
			letter_count[i] = 0;
		}
		int text_count = 0;
		FOREACH( i, text )
		{
			FOREACH( j, *i )
			{
				if( isLetter( *j ) )
				{
					letter_count[*j] += 1;
					text_count++;
				}
			}
		}
		double ret = DBL_MAX;
		FOREACH( i, languages )
		{
			double t = diviation( *i, letter_count, text_count );
			ret = min( ret,  t );
		}
		return ret;
	}
};

/* Lev A Neiman's coding here */
