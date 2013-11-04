#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define d_print(x) cout<<#x<<(x)<<endl;


int main( int argc, char ** argv )
{
	int T;
	cin>>T;
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision( 6 );
	for( int CASE=1; CASE <=T ; ++ CASE )
	{
		int N;
		cin>>N;
		vector<int> nums;
		for( int i = 0; i < N; ++i )
		{
			int n;
			cin>>n;
			nums.push_back( n );
		}
		
		vector<int> nums2 = nums;
		sort( nums2.begin(), nums2.end() );
		
		double answer = 0;
		for( int i = 0; i < nums.size(); ++i )
		{
			if( nums[i] != nums2[i] ) answer += 1;
		}
		cout<<"Case #"<<CASE<<": "<<answer<<endl;
	}
}
