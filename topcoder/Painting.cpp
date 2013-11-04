#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Painting
{
	public:
		int largestBrush(vector <string> picture)
		{
			vector<vector<int > > visited( picture.size(), vector<int>(picture[0].size(), -1 ));
			int n = picture.size();
			int m = picture[0].size();
			int smallest = 100000;
			for( int i = 0; i < n; ++i )
			{
				for( int j = 0; j < m; ++j )
				{
					if( picture[i][j] == 'W' ) continue;
				//	if( visited[i][j] ) continue;
					int s;
					for( s = 50; s >= 0; --s )
					{
						if( i + s >= n ) continue;
						if( j + s >= m ) continue;
						bool good = true;
						for( int i1 = i; i1 <= i + s; ++i1 )
						{
							for( int j1 = j; j1 <= j + s; ++j1 )
							{
								if( picture[i1][j1] == 'W' )
								{
									good = false;
									break;
								}
							}
							if( !good ) break;
						}
						if( good )
						{
							{

							cout<<i<<" "<<j<< " "<<s<<endl;
								if( visited[i][j] < s && smallest > s) smallest = s;
							for( int i1 = i; i1 <= i + s; ++i1 ) for( int j1  = j; j1 <= j + s; ++j1 )
							{
							//	cout<<i1<<" "<<j1<<" FUCK" <<endl;
								if( s > visited[i1][j1] ) visited[i1][j1] = s;
							}
							}
							
							break;
						}
					}
				}
			}
			return smallest + 1;
		}
};
