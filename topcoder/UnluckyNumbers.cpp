#line 2 "UnluckyNumbers.cpp"
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

class UnluckyNumbers 
{
	public:
	int getCount(vector <int> luckySet, int n) 
	{
		sort( ALL( luckySet ) );
        int a,b;
        FOR( i, luckySet.size() - 1 )
        {
             if( luckySet[i] == n || luckySet[i+1] == n ) return 0;
             if( luckySet[i] < n && luckySet[i+1] > n )
             {
                 a = luckySet[i] + 1;
                 b = luckySet[i+1] - 1;
                 cout<<a<<" "<<b<<endl;
                 break;
             } 
         }
         int ways = 0;
         for( int i = a; i <= n; ++i )
         {
              for( int j = n; j <= b; ++j )
              { 
                   if( i != j )
                   {
                   cout<<i<<" "<<j<<endl;
                   ++ways;
                   }
               }
          }
          return ways;
	}
};
