#line 2 "PiecesMover.cpp"
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

int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

using namespace std;

int check( vector <string> & board, vector<bool> & visited, int i, int j )
{
    if( i < 0 || j < 0 || i >= 5 || j >= 5 ) return 0;
   // cout<<board[i][j];
    if( visited[i*5 + j] ) return 0;
    if( board[i][j] == '.' ) return 0;
    int ret = 1;
    visited[i*5 + j] = true;
    FOR( k, 4 )
    {
         ret += check( board, visited, i + dir_y[k], j + dir_x[k] );
    }
    return ret;    
}

int check( vector <string> & board, int i, int j )
{
    vector<bool> visited(25,false );
    return check( board, visited, i, j );
}

void swap( vector<string> & board, int i, int j, int i1, int j1 )
{
     char c = board[i][j];
     board[i][j] = board[i1][j1];
     board[i1][j1] = c;
}

int inline distance( int i, int j, int i1, int j1 )
{
    return abs( i-i1) + abs(j-j1);
}

int solve( vector<string> board, int i, int j, int n )
{
    int ret = 0;
    while( check( board, i, j ) != n )
    {
           FOR( i1, 5 )
           {
                FOR( j1, 5 )
                {
                     if( board[i1][j1] == '*' )
                     {
                         if( i1 < i && board[i1+1][j1] != '*' )
                         {
                             swap( board, i1,j1, i1+1, j1 );
                             ret++;
                         }
                         else if( i1 > i && board[i1-1][j1] != '*' )
                         {
                              swap( board, i1,j1, i1-1, j1 );
                              ret++;
                         }
                         else if( j1 < j && board[i1][j1+1] != '*' )
                         {
                              swap( board, i1,j1, i1, j1 + 1 );
                              ret++;
                          }
                         else if( j1 > j && board[i1][j1-1] != '*' )
                         {
                              swap( board, i1,j1, i1, j1 - 1 );
                              ret++;
                         }
                     }
                }
                
           }
           
            
    }
    return ret;
}

class PiecesMover 
{
	public:
	int getMinimumMoves(vector <string> board) 
	{
		vector<vector<int> > solutions( 5, vector<int>(5,1<<29));
		int n = 0;
		FOR( i, 5 )
		{
             FOR( j, 5 )
             {
                  if( board[i][j] == '*' ) n++;
             }
         }
         int ret = 1<<29;
		FOR( i, 5 )
		{
             FOR( j,  5 )
             {
                  ret = min( ret, solve( board, i, j, n ) );
             }
        }
        return ret;
	}
};


// Powered by FileEdit
