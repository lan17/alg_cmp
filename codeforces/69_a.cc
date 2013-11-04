#include <iostream>

using namespace std;

bool is_prime( int i )
{
	if( i == 2 ) return true;
	for( int n = 2; n < i; ++n ) if( i % n == 0 ) return false;
	return true;
}

int main( int argc, char ** argv )
{
	int n,m;
	cin>>n>>m;
	if( !is_prime(m) )
	{
		cout<<"NO";
		return 0;
	}
	bool seen_prime = false;
	for( int t = n + 1; t < m; ++t )
	{
		if( is_prime(t) )
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
}
