#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main( int argc, char **argv )
{
	int n, k;
	cin>>n>>k;
	vector<int> nums;
	for( int i = 0; i < n; ++i )
	{
		int t;
		cin>>t;
		nums.push_back(t);
	}
	
	int s = nums[k-1];
	int cn = 0;
	for( int i = 0; i < n; ++i )
	{
		if( nums[i] >= s && nums[i] > 0 ) ++cn;
	}
	cout<<cn<<endl;
}
