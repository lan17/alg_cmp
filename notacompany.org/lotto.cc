#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main( int argc, char ** argv )
{
	int D;
	cin>>D;
	vector<vector<int> > days(D, vector<int>(D,0));
	for( int i = 0; i < D; ++i )
	{
		for( int j = 0; j < D; ++j )
		{
			cin>>days[i][j];
		}
	}
	int sum = 0;
	for( int i = 0; i < D; ++i )
	{
		int pick = 0;
		for( int j = 0; j < D; ++j )
		{
			pick = max(pick, days[i][j] );
		}
		sum += pick;
	}
	cout<<sum<<endl;
}
