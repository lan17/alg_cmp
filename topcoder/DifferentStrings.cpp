#line 2 "DifferentStrings.cpp"
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

class DifferentStrings 
{
	public:
	int minimize(string A, string B) 
	{
		int ret = 0;
        int diff = 0;
        //if( A.size() == B.size() )
        {
            FOR( i, A.size() ) if( A[i] != B[i] ) ++diff;
            if( A.size() == B.size() )  return diff;
        }

        FOR( i, B.size() - A.size() +1 )
        {
             bool same = true;
             int new_diff = 0;
             FORR( j, i, i + A.size())
             {
                   if( j >= B.size() ) break;
                   if( A[j-i] != B[j] )
                   {
                       same = false;
                       //break;
                       ++new_diff;
                   }
             }     
             diff = min( diff, new_diff );
             if( same ) return 0;        
        }
        
        
        
        return diff;
	}
};
