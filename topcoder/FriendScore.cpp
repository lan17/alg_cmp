#line 2 "FriendScore.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <set>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

int sum( vector <string> & friends, vector<bool> & visited, int root, int rec = 0 )
{
    if( visited[root] ) return 0;
    for( int i = 0; i < rec; ++i )cout<<" ";
    cout<<root<<endl;
    visited[root] = true;
    int output = rec != 0;
    for( int i = 0; i < friends[root].size(); ++i )
    {
         if( friends[root][i] == 'Y' )
         {
             output += sum( friends,  visited, i, rec + 1 );
         }
     }
     return output;    
}

class FriendScore 
{
	public:
	int highestScore(vector <string> friends) 
	{
		vector<bool> visited( friends.size(), false );
		int output = 0;
		for( int i = 0; i < visited.size(); ++i )
		{
             if( visited[i] ) continue;
             cout<<"==================="<<endl;
             output = max( output, sum( friends, visited, i ) );
         }
         return output;
	}
};
