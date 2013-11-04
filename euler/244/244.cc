#include "common.h"

#define MOD 100000007

int INF = 1<<29;
const int LIM = (1<<16) * 16;

char moves[4] = {'L','U','R','D'};
char rmoves[4] = {'R','D','L','U'};

struct state
{
	unsigned short board; // binary representation of the board.  1 is red 0 is blue.
	short blank_pos; // position of the empty square.

	state():board(0),blank_pos(0){}

	state( unsigned short board, int blank_pos ):board(board),blank_pos(blank_pos)
	{
		set( blank_pos, false );
	}

	state( vector<bool> & board, int blank_pos ) : blank_pos(blank_pos)
	{
		this->board = 0;
		for( size_t i = 0; i < board.size(); ++i )
		{
			if( board[i] )
			{
				this->board += (1<<i);
			}
		}
	}

	size_t hash() const
	{
		return board + blank_pos * (1<<16);
	}

	bool operator==(const state & a ) const
	{
		return board == a.board && blank_pos == a.blank_pos;
	}

	bool operator<(const state & a ) const
	{
		return hash() < a.hash();
	}

	int stridez( int x, int y )
	{
		return x + y * 4;
	}

	/*
	* Get whether element on board at p is red. if not red then either blue or blank.
	*/
	bool red( int p )
	{
		return (board&(1<<p)) != 0;
	}
	
	// set element on board.
	void set( int p, bool val )
	{
		if( val )
		{
			board |= 1<<p;
		}
		else
		{
			board &= ( 0xFFFF ^ 1<<p );
		}
	}

	bool move( char m )
	{		
		switch( m )
		{
			case 'L':
				if( blank_pos % 4 == 0 ) return false;
				set(blank_pos, red(blank_pos-1) );
				--blank_pos;
				break;
			case 'R':
				if( ( blank_pos+1 ) % 4 == 0 ) return false;
				set(blank_pos, red(blank_pos + 1 ));
				++blank_pos;
				break;
			case 'U':
				if( blank_pos <= 3) return false;
				set( blank_pos, red(blank_pos-4) );
				blank_pos -= 4;
				break;
			case 'D':
				if( blank_pos > 11 ) return false;
				set( blank_pos, red(blank_pos+4 ) );
				blank_pos += 4;
				break;	
		}
		set( blank_pos, false );
		return true;
	}

	bool move( const string & t )
	{
		for( size_t i = 0; i < t.size(); ++i )
		{
			if( ! move( t[i] ) )
			{
				cerr<<"Couldnt perform move "<<i<<endl;
				return false;
			}
		}
		return true;
	}

	void print( )
	{
		for( int y = 3; y >= 0; --y )
		{
			for( int x = 3; x>=0; --x )
			{
				if( x + y * 4 == blank_pos ) cout<<" ";
				else
				{
					bool R = red( stridez(x,y) );
					cout<<(R?'R':'B');
				}
			}
			cout<<endl;
		}
	}

	// compute which move must have been performed to get from state a to b.
	// it is always a given that b can be reached from a in one step.
	static char move( const state & a, const state & b )
	{
		short t = a.blank_pos - b.blank_pos;
		if( t == 1 ) return 'L';
		if( t == -1 ) return 'R';
		if( t == 4 ) return 'U';
		if( t == -4 ) return 'D';
	}
};

namespace __gnu_cxx
{
  template<> struct hash< state >
  {
    size_t operator()( const state & x ) const
    {
      return x.hash();
    }
  };
}


ull checksum( const string & a )
{
	ull ret = 0;
	for( size_t i = 0; i < a.size(); ++i )
	{
		ret = ( ret * 243 + a[i] ) % MOD;
	}
	return ret;
}

state start( 0xCCCC, 15 ); 
state sample( 0xC8AC, 6 ); // sample end state from problem description.
state end_state( 0x25A5, 15 ); // endstate from problem description.

state umu_ways_560( 0x7f00, 15 );
state umu_ways_22( 0x3332, 0 );
state umu_ways_3609( 0xd710, 1 );

//hash_map<state, int> dist;  // store shortest distance from start to some state
hash_map<state,set<state> > prev; // store previous states in shortest path for state
//hash_map<state,bool> not_in_q; // store whether or not state has been already considered

int dist[LIM];
bool not_in_q[LIM];

struct PQ_cmp
{
	bool operator()(const state & a, const state & b)
	{
		return dist[a.hash()] > dist[b.hash()];
	}
};

void dijkstra2( vector<state> & states, const state & final )
{
	for( size_t i = 0; i < states.size(); ++i )
	{
		state & si = states[i];
		not_in_q[si.hash()] = false;
		dist[si.hash()] = INF;
	}

//	priority_queue<state,deque<state>, PQ_cmp> pq;	
	deque<state> pq;

	pq.push_back(start);
	dist[start.hash()] = 0;

	while(!pq.empty())
	{
		state u = pq.front();
		pq.pop_front();

		if( u == final )
			return;

		not_in_q[u.hash()] = true;

		state v = u;
		for( size_t move = 0; move < 4; ++ move )
		{
			if( v.move( moves[move]) )
			{
				if( !not_in_q[v.hash()] )
				{
					pq.push_back(v);
				}
				int alt = dist[u.hash()] + 1;
				if( alt < dist[v.hash()])
				{
					dist[v.hash()] = alt;
					prev[v].clear();
					prev[v].insert( u );
				}
				if( alt == dist[v.hash()] )
				{
					prev[v].insert(u);
				}
				v.move(rmoves[move]);
			}
		}
	}
}

// Retrieve shortest path from results in dijsktra algo.
void moves_rec( hash_map<state,set<state> > & prev, state & curr, string path, set<string> & paths)
{
	if( prev[curr].size() == 0 )
	{
		reverse(path.begin(),path.end());
		paths.insert( path );
		return;
	}
	set<state> & prevv = prev[curr];
	for( set<state>::iterator i = prevv.begin(); i != prevv.end(); ++i )
	{
		state  g = *i;
		moves_rec( prev, g, path + state::move(g, curr), paths );
	}
}

int main( int argc, char ** argv )
{
	// create all possible states.

	vector<bool> board(16, false );
	board[0] = board[1] = board[2] = board[3] = board[4] = board[5] = board[6] = true;

	vector<state> states;

	for( int blank_pos = 0; blank_pos < 16; ++blank_pos )
	{
		sort( board.begin(), board.end() );	
		while( true )
		{
			state t(board,blank_pos);
			states.push_back( t );
			if( ! next_permutation( board.begin(), board.end() ) ) break;
		}
	}
	cout<<"We have " <<states.size()<<" states "<<endl;

	// do the dijkstra.
	
	state & final = end_state;//umu_ways_3609;

	dijkstra2( states, final );


	set<string>  answers;
	
	answers.clear();
	moves_rec( prev, final, "", answers );
	ull answer = 0;
	for(set<string>::iterator i = answers.begin(); i != answers.end(); ++i )
	{
	//	cout<<*i<<endl;
		answer += checksum( *i );
	}
	cout<<answer<<endl;
}
