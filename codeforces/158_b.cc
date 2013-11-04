#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LIM = 4;

int solve( vector<int> G )
{
	sort(G.begin(), G.end());
	int ret = 0;
	int j = 0;
	for( int i = G.size()-1; i >= 0 && j <= i; --i )
	{
		if( G[i] == LIM ) ++ret;
		else
		{
			int f = G[i];
			while( j < i )
			{
				if( f + G[j] > LIM )
				{
					break;
				}
				f += G[j++];
			}
			++ret;
		}
	}
	return ret;
}

int main( int argc, char ** argv )
{
	int n;
	vector<int> G;
	cin>>n;
	for(int i = 0; i < n; ++i )
	{
		int t;
		cin>>t;
		G.push_back(t);
	}
	
	
	cout<<solve(G)<<endl;
}
