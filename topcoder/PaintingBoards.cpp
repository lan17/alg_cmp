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

#define FOR( i, n ) for( int (i) = 0; (i) < (int)(n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (int)(n); (i) <= (int)(m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define pnt(x) cout<<#x<<" = "<<(x)<<endl;

#define fmin DBL_MIN_10_EXP;
#define fmax DBL_MAX_10_EXP;
using namespace std;

void printBP( vector<vector< double > > & bp )
{
	FOR( i, bp.size( ) )
	{
		FOR( j, bp[i].size( ) )
		{
			cout<<bp[i][j]<<"\t";
		}
		cout<<endl;
	}
}

class PaintingBoards 
{
	public:
	
	double Min( const  vector< vector< double > > & bp, const vector<vector< double > > & speedz, int b, int p )
	{
		double min = fmax;
		FORR( i, 1, p-1 )
		{
			double n = bp[b-1][p] + speedz[b][i];
			if( min > n ) min = n;
			
		}
		//return bp[b-1][p-1]+speedz[b][p-1];
		return min;

	}
	
	double minimalTime(vector <int> boardLength, vector <int> painterSpeed)
	{
		vector< vector< double > > bp( boardLength.size( ) + 1, vector<double>( painterSpeed.size( ) + 1, 0.0f ) );
		vector< vector< double > > speedz( boardLength.size( ) + 1, vector<double>( painterSpeed.size( ) + 1, 0.0f ) );
		FORR( i, 1, boardLength.size( ) )
		{
			FORR( j, 1, painterSpeed.size( ) )
			{
				speedz[i][j] = boardLength[i-1]*( 1.0 / painterSpeed[j-1] );
			}
		}
		
		FORR( i, 1, boardLength.size( ) )
		{
			bp[i][1] = bp[i-1][1] + speedz[i][1];
		}
		
		FORR( p, 2, painterSpeed.size( ) )
		{
			FORR( b, 1, boardLength.size( ) )
			{
				double lol = Min(bp, speedz, b, p );
				if( lol < bp[b][p-1] + speedz[b][p] ) bp[b][p] = lol;
				else bp[b][p] = bp[b][p-1] + speedz[b][p];
			}

		}
		printBP( bp );

		return bp[boardLength.size( )][painterSpeed.size( )];
	}
};

/* Lev A Neiman's coding here */


// Powered by FileEdit


// Powered by FileEdit
