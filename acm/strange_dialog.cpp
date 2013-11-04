#include <iostream>
#include <vector>
#include <string>

#define vecs vector< string > 
#define veci vector< int >
#define vecsi vector<string>::iterator
#define vecii vector<int>::iterator

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

/*
void printVeci( veci & v )
{
	cout<<"{ ";
	FOREACH( i, v )
	{
		cout<<*i<<", ";
	}
	cout<<"};";
	cout<<endl;
}
*/

bool check( string & s, vecs & words )
{
	if( s.size( ) == 0 ) return false;
	veci nfa( 6, -1 ); // this vector of integers keeps track of states, modeling NFA.
	bool begin = true; // is true if one of the states in NFA is at initial state.
	for(string::iterator ch=s.begin( ); ch != s.end( ); ++ch )
	{
		// if one of the final states is reached but there is more letters to be consumed
		// then NFA needs to go back to initial state on a lambda transition.  next loop does this.
		FOR( i, (int)nfa.size( ) )
		{
			if( nfa[i] == (int)words[i].size( ) - 1 ) { nfa[i] = -1; begin = true; }
		}
		// init found to false.  if its false after next loop then NFA can't move to any new state
		// and string is invalid.
		bool found = false;
		FOR( i, (int)words.size( ) )
		{
			
			if( !begin && nfa[i] == -1){} // if NFA is not in initial state and the NFA counter for specific word is -1 then do nothing
			else  // otherwise figure out next state.
			{
                int t = nfa[i] + 1;
				if( *ch == words[i][t] ) 
				{
					nfa[i]=t;
					found = true;
				}
				else if( !begin ) nfa[i] = -1; 
				else if( *ch == words[i][0] ) { nfa[i]=0; found=true; }
			}
		}
		//cout<<*ch;
		//printVeci( nfa );
		if( !found ) return false;
		else begin = false;

	}
	FOR( i, (int)words.size( ) )
	{
		if( nfa[i] == (int)words[i].size( ) -1 ) return true; 
	}
	return false;
}

int main(int argc, char *argv[])
{
	vecs good( 6, "" );
	good[0] = "one";
	good[1] = "output";
	good[2] = "out";
	good[3] = "puton";
	good[4] = "in";
	good[5] = "input";
	int n;
	cin>>n;
	if( cin.peek( ) == '\n' ) cin.ignore( );
	FOR( i, n )
	{
		string line;
		getline( cin, line );
		if( check( line, good ) ) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	
	return 0;
}
