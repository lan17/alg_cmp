#line 2 "TournamentJudging.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

class TournamentJudging 
{
	public:
	int getPoints(vector <int> rawScores, vector <int> conversionFactor) 
	{
		int sum = 0;
		FOR( i, rawScores.size() )
		{
             int adj_score = (int)(( (double)rawScores[i] / (double) conversionFactor[i] ) + .5 );
             sum += adj_score;
        }
        return sum;
	}
};
