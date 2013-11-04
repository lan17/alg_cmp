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

#define INF 1<<31-1

using namespace std;
class MazeMaker
{
	public:
		int longestPath( vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol )
		{

			int x_size = maze[0].size();
			int y_size = maze.size();
			vector<vector<int> > has_been( y_size, vector<int> ( x_size, -1 ) );
			//maze[startRow][startCol]=0;
			queue<int> x_queue, y_queue;
			y_queue.push( startRow );
			x_queue.push( startCol );
			int count = 0;
			while (!(x_queue.empty() || y_queue.empty()))
			{
				int s = x_queue.size();
				for( int i = 0; i < s; ++i )
				{
					int x = x_queue.front();
					x_queue.pop();
					int y = y_queue.front();
					y_queue.pop();
					if (y < 0 || y >= y_size)
						continue;
					if (x < 0 || x >= x_size)
						continue;
					if (has_been[y][x] != -1)
						continue;
					if (maze[y][x] == 'X')
						continue;

					has_been[y][x] = count;

					for( int j = 0; j < moveRow.size();++j)
					{
						x_queue.push(x+moveCol[j]);
						y_queue.push(y+moveRow[j]);
					}
				}
				++count;
			}

			for (int x = 0; x < x_size; ++x)
			{
				for (int y = 0; y < y_size; ++y)
				{
					cout << has_been[y][x] << " ";
				}
				cout << endl;
			}

			int max_p = 0;
			for (int x = 0; x < x_size; ++x)
			{
				for (int y = 0; y < y_size; ++y)
				{
					if (maze[y][x] != 'X' && has_been[y][x] == -1)
						return -1;
					if (maze[y][x] != 'X')
						max_p = max( max_p, has_been[y][x] );
				}
			}
			return max_p;
		}
};

