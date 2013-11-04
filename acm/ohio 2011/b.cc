#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main(int argc, char ** argv )
{
	ull X;
	cin>>X;
	ull sum = 0;
	for( ull i = 2; i <X; ++i )
	{
		bool div = false;
		for( ull j = 1; j <= i; ++j )
		{
			if( div && i % j == 0 )
			{
				sum += i;
				break;
			}
			if( i % j == 0 )
			{
				div = true;
			}
			else
			{
				div = false;
			}
		}
	}
	cout<<sum<<endl;
}
