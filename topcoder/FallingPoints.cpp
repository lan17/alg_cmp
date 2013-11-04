#line 2 "FallingPoints.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

class FallingPoints 
{
	public:
	vector <double> getHeights(vector <int> X, int R) 
	{
		vector<double> dist( X.size(), 0.0 );
		pair<double,double> last_point;
		last_point.first = (double)X[0];
		last_point.second = 0.0;
		FORR( i, 1, X.size()-1)
		{
              double new_y;
              if( abs( X[i] - X[i-1] ) > R ) new_y = 0.0;
              else if( abs( X[i] - X[i-1] ) == R ) new_y = dist[i-1];
              else
              {
                  new_y = (double)(R*R) - (double)((X[i]-X[i-1])*(X[i]-X[i-1]));
                  cout<<new_y<<endl;
                  new_y = sqrt( new_y ) +  dist[i-1];
              }
              dist[i] = new_y;
        }
        return dist;
	}
};
