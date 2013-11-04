// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Wolf Sothe is playing the game Delaymaster.
In this game, he can create new words according to the following rules:

For each positive integer n, the string which consists of n copies of 'w', then n copies of 'o', then n copies of 'l', and finally n copies of 'f' is a valid word.
The concatenation of two valid words is a valid word.
Only the words that can be obtained by rules 1 and 2 are valid. There are no other valid words.


Thus, for example:

By rule 1, "wolf", "wwoollff", and "wwwooolllfff" are valid words.
Then, by rule 2, "wolfwwoollff" is a valid word.
By applying rule 2 twice, "wolfwwoollffwolf" is a valid word.
The string "wfol" is not a valid word (order matters).
The string "wwolfolf" is not a valid word (we can only concatenate, not insert one word into another).
The string "wwwoolllfff" is not a valid word (only two 'o's instead of three).


You are given a string str.
Return "VALID" if str is a valid word and "INVALID" otherwise.
Note that the return value is case-sensitive: you must return the strings "VALID" and "INVALID" in all-uppercase.

DEFINITION
Class:WolfDelaymaster
Method:check
Parameters:string
Returns:string
Method signature:string check(string str)


CONSTRAINTS
-str will contain between 1 and 50 characters, inclusive.
-Each character in str will be 'w', 'o', 'l' or 'f'.


EXAMPLES

0)
"wolf"

Returns: "VALID"

The first valid word from the examples in the problem statement.

1)
"wwolfolf"

Returns: "INVALID"

The second invalid word from the examples in the problem statement.

2)
"wolfwwoollffwwwooolllfffwwwwoooollllffff"

Returns: "VALID"



3)
"flowolf"

Returns: "INVALID"



*/
// END CUT HERE

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>

using namespace std;

int print_dbg = 1;

#define d_print(x) { if(print_dbg){  cerr << __LINE__ << " " << #x << " = " << x << endl; cerr.flush(); } }

typedef vector<string> vecs;
typedef vector<int> veci;
typedef unsigned long long ull;
typedef long long ll;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))


// wwwwwwwwwooooooooolllllllllfffffffff - valid
// olfwolf - invalid

struct StateMachine
{
	int state;
	int c1,c2;
	string word;
	
	StateMachine():state(-1),c1(0),c2(0),word("wolf"){}
	
	void advance(char c)
	{
		int nState = (state + 1 ) % word.size();
		if( state >= 0 )
		{
			if( c == word[state] )
			{
				++c2;
				if( state == 0 ) ++c1;
				if( c2 > c1 ) state = -2;
			}
			else if( c == word[nState] )
			{
				if( nState > 0  && c2 != c1 ) state = -2;
				else if( nState > 0 )
				{
					c2 = 1;
				}
				else
				{
					c1=c2=1;
				}
				state = nState;
				
			}
			else state = -2;
		}
		else if( state == -1 && word[0] == c )
		{
			state = 0;
			c1 = c2 = 1;
		}
		else if( state == -1 )state = -2;
		d_print( c << " " << state <<", "<<c1<<", "<<c2);
		
	}

	bool good()
	{
		return state == word.size() - 1 && c1==c2;
	}
	
};


class WolfDelaymaster
{
	public:
	string check(string str)
	{
		StateMachine s;
		for( int i = 0; i < str.size(); ++i )
		{
			s.advance(str[i]);
		}
		return s.good() ? "VALID" : "INVALID";
	}
};
