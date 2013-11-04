#line 2 "RestaurantManager.cpp"
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

class RestaurantManager 
{
	public:
	int allocateTables(vector <int> tables, vector <int> groupSizes, vector <int> arrivals, vector <int> departures) 
	{
        // map table to group.
        sort( ALL( tables ) );
        map< int, int > seated;
        int turned_away = 0;
		FOR( i, groupSizes.size() )
		{
             bool found_table = false;
             FOR( j, tables.size() )
             {
                  if( isMaped( seated, j ) )
                  {
                      if( departures[ seated[j] ] <= arrivals[i] )
                      {
                          if( tables[j] >= groupSizes[i] )
                          {
                              seated[j] = i;
                              found_table = true;
                              break;
                          }                          
                      }                      
                  }
                  else
                  {
                      if( tables[j] >= groupSizes[i] )
                      {
                          seated[j] = i;
                          found_table = true;
                          break;
                      }
                  }
              }
              if( !found_table ) turned_away += groupSizes[i];
         }
         return turned_away;
	}
};


// Powered by FileEdit
