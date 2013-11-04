// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John and Brus have an interest in team sports tournaments.
They are currently investigating a basketball tournament.
Basketball is a team sport in which two teams of five players try to score points against one another by placing a ball through a ten foot high hoop.
Basketball is one of the most popular and widely viewed sports in the world.



There are n teams in the tournament. Each pair of teams plays exactly two games against each other.  In the first of these games, one of the teams is the host, and in the second, the other team is the host. Each game results in one team winning. There are no draws. After the tournament is over, the team with the highest total number of wins is crowned the winner.



The tournament is currently in progress and the current results are described in the vector <string> table.
For each pair of distinct indices, i and j, the j-th character of the i-th element of table is the result of the game where team i hosted team j.
The result is 'W' if team i won, 'L' if team i lost, and '?' if the game hasn't been played yet.
Assuming that every possible outcome is possible for the games that haven't been played yet, return the minimal number of total wins the tournament winner can have at the end of the tournament.



DEFINITION
Class:TheBasketballDivTwo
Method:find
Parameters:vector <string>
Returns:int
Method signature:int find(vector <string> table)


CONSTRAINTS
-table will contain between 2 and 5 elements, inclusive.
-Each element of table will contain exactly n characters, where n is the number of elements in table.
-The j-th character of the i-th element of table, where i and j are different, will be 'W', 'L', or '?'.
-The i-th character of the i-th element of table will be 'X'.


EXAMPLES

0)
{"X?", "?X"}

Returns: 1

One win for each team.

1)
{"XW", "LX"}

Returns: 2

The tournament is over.

2)
{"XWL", "?XW", "WLX"}

Returns: 2

The only game that hasn't been played yet is between the first and second teams.
If the first team wins the game, all of the teams will finish with two wins.

3)
{"XW?", "LX?", "??X"}

Returns: 2

// END CUT HERE
*/
#line 70 "TheBasketballDivTwo.cpp"
#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <cstdio>
#include <valarray>      
#include <ext/hash_set> 
#include <ext/hash_map>
#include "float.h"

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define print(x) cout<<#x<<" = "<<(x)<<endl;

using namespace std;
class TheBasketballDivTwo {
	public:
	int find(vector <string> table) 
	{
		
	}
};
