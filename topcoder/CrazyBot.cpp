#line 2 "CrazyBot.cpp"
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

double dfs( int k, int i, int j, vector<vector<bool> > & visited, double e, double w, double s, double n )
{
       cout<<i<<" "<<j<<endl;
      // cout<<e<<" "<<w<<" "<<s<<" "<<n<<endl;
       if( visited[i][j] ) return 1.0;
       if( k == 0 ) return 1.0;
       visited[i][j] = true;
       double ret = 0;
       if( !visited[i-1][j] ) ret += dfs( k - 1, i - 1, j, visited, e, w, s, n ) * n;
       if( !visited[i+1][j] ) ret += dfs( k - 1, i + 1, j, visited, e,w,s,n) * s;
       if( !visited[i][j-1] ) ret += dfs( k - 1, i, j - 1, visited, e,w,s,n) * w;
       if( !visited[i][j+1] ) ret += dfs( k - 1, i, j + 1, visited, e,w,s,n) * e;
       visited[i][j] = false;
       cout<<"======"<<endl;
       return ret;
}

class CrazyBot 
{
	public:
	double getProbability(int n, int east, int west, int south, int north) 
	{
		vector<vector<bool> > visited( 3 * n + 1, vector<bool>(3 * n + 1, false ) );
//		visited[n/2][n/2] = true;
		return dfs( n , n+1, n+1, visited, (double)east/100, (double)west/100, (double)south/100, (double)north/100 );
	}
};
