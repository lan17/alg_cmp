#line 2 "ChessMetric.cpp"
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

int move_x[] = { -1,  0, 0,  1, 1, 1, -1, -1, 1,  2, 2, 1, -1, -2, -2, -1 };
int move_y[] = { -1, -1, 1, -1, 1, 0,  0,  1,-2, -1, 1, 2,  2,  1, -1, -2 };

 struct pairCmp {
      bool operator()( const pair<int,int> & p1, const pair<int,int> & p2 ) const {
        if( p1.first != p2.first ) return p1.first < p2.first;
        return p1.second < p2.second;
      }
    };

void clearV( vector<vector<unsigned long long > > & board2 )
{
     FOR( i, board2.size() )
     {
          FOR( j, board2.size() )
          {
               board2[i][j] = 0;
           }
           }
      
}

class ChessMetric 
{
	public:
	long long howMany(int size, vector <int> start, vector <int> end, int numMoves) 
	{
		vector<vector<unsigned long long > > board1( size, vector<unsigned long long>( size, 0 ) );
		vector<vector<unsigned long long > > board2( size, vector<unsigned long long>( size, 0 ) );
		vector<vector<unsigned long long > > * curr_board = & board1;
		vector<vector<unsigned long long > > * next_board = & board2;
		(*curr_board)[start[1]][start[0]] = 1;
		map<pair<int,int>,int, pairCmp > * zomg_pieces = new map<pair<int,int>,int, pairCmp >();
		(*zomg_pieces)[pair<int,int>(start[0],start[1] )] = 0;
		int c = 1;
		FOR( n, numMoves )
		{
             clearV( *next_board );
             map<pair<int,int>,int,pairCmp> * new_pieces = new map<pair<int,int>,int, pairCmp >();;
             FOREACH( curr, *zomg_pieces )
             {
                      FOR( move, 16 )
                      {
                           pair<int,int> new_move = pair<int,int>( curr->first.first + move_x[move], curr->first.second + move_y[move] );
                           if( new_move.first < 0 || new_move.second < 0 || new_move.second >= size || new_move.first >= size ) continue;
                           (*new_pieces)[new_move] = 0;
                           (*next_board)[new_move.second][new_move.first] += (*curr_board)[curr->first.second][curr->first.first];
                      }
             }
             delete zomg_pieces;
             zomg_pieces = new_pieces;
             vector<vector<unsigned long long > > * tmp = curr_board;
             curr_board =  next_board;
             next_board = tmp;             
        }
        long long ret = (*curr_board)[end[1]][end[0]];
      //  if( start[0] == end[0] && start[1] == end[1] ) ret--;
        return ret;
	}
};


// Powered by FileEdit
