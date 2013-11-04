#line 2 "KthProbableElement.cpp"
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

class KthProbableElement 
{
	public:
	double probability(int M, int lowerBound, int upperBound, int N, int K) 
	{
        int interval = upperBound-lowerBound + 1;
		return (double)M/( upperBound-lowerBound+1);
	}
};
