#line 2 "TheTower.cpp"
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

int distance( int x1, int y1, int x2, int y2 )
{
    return abs( x1 - x2 ) + abs( y1 - y2 );
}

bool cmp( const pair<int,int> & a, const pair<int,int> & b )
       {
            return a.second < b.second;
       }
       
int sum( vector<pair<int,int> > & b )
{
    int ret = 0;
    FOREACH( i, b )
    {
             ret += i->second;
    }
    return ret;
}

int getMinDist( map< int, vector< pair<int,int> > * > & closest, vector<int> &x, vector<int>&y, int min_i, int n )
{
    int ret = 0;
    int pos_x = x[min_i];
    int pos_y = y[min_i];
    FOR( i, n )
    {
         pos_x += x[((*closest[min_i])[i].first)];
         pos_y += y[((*closest[min_i])[i].first)];
     }
     pos_x /= n+1;
     pos_y /= n+1;
     ret += distance( x[min_i],y[min_i], pos_x, pos_y );
     FOR( i, n )
     {
          ret += distance( x[((*closest[min_i])[i].first)], y[((*closest[min_i])[i].first)], pos_x, pos_y );
     }
     return ret;
}


class TheTower 
{
	public:
	vector <int> count(vector <int> x, vector <int> y) 
	{
		int N = x.size();
		//vector<vector< int > > dist( N, vector<int>( N, 0 ) );
		map< int, vector< pair<int,int> > * > closest;
		FOR( i, N ) closest[i] =  new vector<pair<int,int> >();
		
		FOR( i, N )
		{
             FOR( j, N )
             {
                  closest[i]->push_back( pair<int,int>( j, distance( x[i],y[i], x[j], y[j] ) ) );
                  
             }
        }
        FOR( i, N ) sort( ALL( *closest[i] ) , cmp );
        
        vector<int> ret;
        ret.push_back( 0 );
        FORR( i, 1, N-1 )
        {
              int min_dist = 1<<29;
              int min_i = -1;
             FOR( i1, N )
             {
                  int dist = 0;
                  FOR( j, i -1 )
                  {
                       dist += (*closest[i1])[j].second;
                  }
                  if( min_dist > dist )
                  {
                      min_dist = dist;
                      min_i = i1;
                  } 
              }
              ret.push_back( getMinDist( closest, x, y, min_i, i ) );
              
        }
        return ret;
		
	}
};
