#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main(int argc, char ** argv )
{
	ull X, sum, ssum;
	cin>>X;

	sum = ssum = 0;

	for( ull i = 1; i <= X; ++i )
	{
		sum += i;
		ssum += i*i;
	}
	//cout<<sum<<endl<<ssum<<endl;
	cout<<(sum*sum-ssum)<<endl;

}
