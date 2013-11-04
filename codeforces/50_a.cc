#include <iostream>
#include <algorithm>

using namespace std;

int solve(int m, int n )
{
	if( m < 2 && n < 2 ) return 0;
	if( n == 1 ) return m / 2;
	if( n == 2 ) return m;
	return solve(m, n - 2 ) + m;
}

int main( int argc, char ** argv )
{
	 int M,N;
	 cin>>M>>N;
	 cout<<solve(M,N)<<endl;
}
