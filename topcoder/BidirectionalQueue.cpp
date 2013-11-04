#line 2 "BidirectionalQueue.cpp"
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

inline int find_i( vector<int> & num, int f )
{
       FOR( i, num.size() )
       {
            if( num[i] == f ) return i;
        }        
}

vector<int>::iterator find_iter( vector<int> & num, int f )
{
                      FOREACH( i, num )
                      {
                               if( *i == f ) return i;
                      }
}

inline int min_shift( vector<int> & num, int t, int f )
{
       int n = num.size();
       int to = find_i( num, f );
       if( to < t ) return min( t - to, n - t + to );
       else return min( to-t, t + n - to );
}

int comp( int N, vector <int> & indices )
{
    vector<int> num( N, 0 );
    FORR( i, 1, N ) num[i-1]=i;
    int t = 0;
    int sum = 0;
    FOR( i, indices.size() )
    {
         sum += min_shift( num, t, indices[i] );
         t = find_i( num, indices[i] );
         num.erase( find_iter( num, indices[i] ) );
    }
    return sum;
}

class BidirectionalQueue 
{
	public:
	int extractElements(int N, vector <int> indices) 
	{
		return comp( N, indices );
	}
};


// Powered by FileEdit
