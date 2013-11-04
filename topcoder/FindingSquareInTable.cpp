#line 2 "FindingSquareInTable.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <set>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;


class FindingSquareInTable 
{
	public:
	int findMaximalSquare(vector <string> table) 
	{
		int n = table.size();
		int m = table[0].size();
		set<long long> perf_square;
		map<long,long> perf_square_map;
		for( long long i = 0; i < 1e6; ++i )
        {
              perf_square.insert( i*i );
              perf_square_map[i*i]=i;
        }
		cout<<isMaped( perf_square, 542352377  )<<endl;
		cout<<perf_square_map[542352377]<<endl;
		vector<int> found;
		for( int i = 0; i < n; ++i )
		{
             for( int j = 0; j < m; ++j )
             {
                  
                            for( int d_i = 0; d_i <= n; ++d_i )
                            {
                                 for( int d_j = 0; d_j <= m; ++d_j )
                                 {
                                      for( int direction_i = -1; direction_i <= 1; direction_i += 2 )
                  {
                       for( int direction_j = -1; direction_j <=1; direction_j += 2 )
                       {
                                      if( d_j == 0 && d_i == 00 ) break;
                                      string perm;
                                      int i_1 = i;
                                      int j_1 = j;
                                      while( i_1 >= 0 && j_1 >= 0 && i_1 < n && j_1 < m )
                                      {
                                             perm.push_back( table[i_1][j_1] );
                                             int t = atoi( perm.c_str() );
                                             if( isMaped( perf_square, t ) )
                                             {
                                                 found.push_back( t );
                                             }
                                             i_1 += d_i * direction_i;
                                             j_1 += d_j * direction_j;
                                             //cout<<"COCK: "<<perm<<endl;
                                             
                                      }                                      
                                   }
                            }
                       }
                  }
             }
        }
        if( found.size() == 0 ) return -1;
        sort( ALL( found ) );
        reverse( ALL( found ) );
        FOR( i, found.size() )
        {
             cout<<found[i]<<endl;
         }
        return found[0];
	}
};
