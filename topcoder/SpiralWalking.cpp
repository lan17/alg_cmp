#line 2 "SpiralWalking.cpp"
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

void turn90( pair<int,int> & p )
{
     if( p.first == 1 )
     {
         p.second = 1;
         p.first = 0;
         return;
     }
     if( p.second == 1 )
     {
         p.first = -1;
         p.second = 0;
         return;
     }
     if( p.second == -1 )
     {
         p.first = 1;
         p.second = 0;
         return;
     }
     if( p.first == -1 )
     {
         p.second = -1;
         p.first =0;
     }
     
}

pair<int,int> add( pair<int,int> & a, pair<int,int> & b )
{
              pair<int,int> ret;
              ret.first = a.first + b.first;
              ret.second = a.second + b.second;
              return ret;
              }

class SpiralWalking 
{
	public:
	int totalPoints(vector <string> levelMap) 
	{
        int x = levelMap[0].size();
        int y = levelMap.size();
		pair<int,int> p; p.first = p.second = 0;
		pair<int,int> direction; direction.first = 1; direction.second  = 0;
		vector< vector< bool > > visited( y, vector<bool>( x, false ) );
		int n = y * x;
		int ret = 0;
		while( n > 0 )
		{
               visited[p.second][p.first] = true;
               pair<int,int> next = add( p, direction );
               if( n > 1 && ( next.first < 0 || next.first >= x || next.second < 0 || next.second >= y || visited[next.second][next.first] ) )
               {
                   turn90( direction );
                   p = add( p, direction );
                   n--;
                   continue;
               }
               ret += levelMap[p.second][p.first] - 48;
               p = next;
               n--;
               
               
        }
        return ret;
		
	}
};
