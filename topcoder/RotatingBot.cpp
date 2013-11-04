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

#define MAX_S 51*51

#define EAST 0
#define NORTH 1
#define WEST 2
#define SOUTH 3

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

class RotatingBot
{
	public:
	int minArea(vector <int> moves)
	{
		vector<vector<bool> > grid(MAX_S,vector<bool>(MAX_S,false));
		int x,y;
		x = MAX_S/50;
		y = MAX_S/50;
		int dir = EAST;
		grid[x][y]=true;
		bool bad = false;
		for( int i = 0; i < moves.size(); ++i )
		{
			for( int j = 0; j < moves[i]; ++j )
			{
				int nx,ny;
				nx = x + dx[dir];
				ny = y + dy[dir];
				if(grid[nx][ny])
				{
					bad = true;
					break;
				}
				grid[nx][ny] = true;
				x = nx;
				y = ny;
			}
			if(bad)
				break;
			if( EAST == dir || WEST == dir )
			{
				int nx = x + dx[dir];
				for( int ny = 0; ny < MAX_S; ++ny )
				{
					grid[nx][ny] = true;
				}
			}
			if( NORTH == dir || SOUTH == dir )
			{
				int ny = y + dy[dir];
				for( int nx = 0; nx < MAX_S; ++nx )
				{
					grid[nx][ny]=true;
				}
			}
			dir = (dir + 1) % 4;
		}
		if( bad )
			return -1;
	}
};
