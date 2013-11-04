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

int main(int argc, char *argv[])
{
	vector< string > dictionary;
	dictionary.push_back( "abc" );
	dictionary.push_back( "bcd" );
	dictionary.push_back( "cd" );
	dictionary.push_back( "abcb" );
	dictionary.push_back( "abcbcd" );
	string message = "abcbcd";
	veci ways( message.size( )+1, 0 );
	ways[0]=1;
	FOR( i, (int)message.size( ) + 1 )
	{
		string s = message.substr( 0, i );
		FOREACH( word, dictionary )
		{
			int n = word->size( );
			if( n > i ) continue;
			string ns = s.substr( i-n );
			if( ns == *word ) ways[i] += ways[i-n];
		}
	}
	cout<<ways[message.size()];
	
	
	return 0;
}
