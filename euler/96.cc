#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

template <class T>
void printDVector( const vector<vector<T> > & grid )
{
	for( int i = 0; i < grid.size(); ++i )
	{
		for( int j = 0; j < grid[i].size(); ++j )
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}

class Grid
{
	public:
		vector<vector<int> > grid;
		vector<pair<int,int> > zeros;
		Grid( istream & is ) 
		{
			vector<vector<int> > grid(9,vector<int>(9,0));
			for( int i = 0; i < 9; ++i )
			{
				string line;	
				getline( is, line );
				for( int j = 0; j < 9; ++j )
				{
					grid[i][j] = line[j]-'0';
					if( grid[i][j] == 0 )
					{
						zeros.push_back(make_pair(i,j));
						//cout<<"zero at "<<i<<", "<<j<<endl;
					}
				}
			}
			this->grid = grid;
			//cout<<"read in a grid with "<<zeros.size()<<" zeros"<<endl;
		}

		bitset<9> get_possible_nums( int i, int j )
		{
			bitset<9> nums;
			nums.reset();
			nums.flip();
			for( int i1 = 0; i1 < 9; ++i1 )
			{
				int n = grid[i][i1];
				if( n > 0 ) nums[n-1] = false;
				n = grid[i1][j];
				if( n > 0 ) nums[n-1] = false;
			}
			int i1_start = i < 3 ? 0 : i < 6 ? 3 : 6;
			int j1_start = j < 3 ? 0 : j < 6 ? 3 : 6;
			for( int i1 = i1_start; i1 < i1_start + 3; ++i1 )
			{
				for( int j1 = j1_start; j1 < j1_start + 3; ++j1 )
				{
					int n = grid[i1][j1];
					if( n > 0 ) nums[n-1] = false;
				}
			}
			return nums;
		}

		void solve()
		{
			bitset<9> nums = get_possible_nums( zeros[0].first, zeros[0].second );
			for( int i = 0; i < nums.size(); ++i )
			{
				if( nums[i] ) 
				{
					//cout<<i+1<<endl;
					if( solve( 0, i + 1 ) )
						break;
				}
			}
		}

		bool solve( int z, int n )
		{
			int i_o = zeros[z].first;
			int j_o = zeros[z].second;
			grid[i_o][j_o] = n;
			if( z == zeros.size() - 1 ) return true;

			int i = zeros[z+1].first;
			int j = zeros[z+1].second;
			
			bitset<9> nums = get_possible_nums( i, j );
			if( ! nums.any() ) // impossible configuration.
			{
				grid[i_o][j_o] = 0;
				return false;
			}
			bool good = false;
			for( int i1 = 0; i1 < nums.size(); ++i1 )
			{
				if( nums[i1] )
				{
					if( solve( z + 1, i1 + 1 ) )
					{
						good = true;
						break;
					}
				}
			}
			if( ! good )
			{
				grid[i_o][j_o] = 0;
			}
			return good;
		}

		int getAnswer()
		{
			int ret = 0;
			ret += grid[0][0] * 10*10;
			ret += grid[0][1] * 10;
			ret += grid[0][2];
			return ret;
		}
		
		
};


int main( int argc, char ** argv )
{
	vector<Grid> boards;

	ifstream ifs( argv[1] );
	while( ifs.good() )
	{
		string t;
		getline( ifs, t );
		Grid board(ifs);
		if( board.zeros.size() > 0 ) boards.push_back( board );
	}
	
	int answer = 0;

	for( int i = 0; i < boards.size(); ++i )
	{
		boards[i].solve();
		printDVector(boards[i].grid);
		int ba = boards[i].getAnswer();
		//cout<<ba<<endl<<"============"<<endl;
		answer += ba;
	}
	cout<<answer<<endl;
}
