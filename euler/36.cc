#include <string>
#include <sstream>
#include <iostream>

using namespace std;

bool polindrome( int num )
{
	stringstream s;
	s<<num;
	string str = s.str();
	int i = 0;
	int j = str.size() - 1;
	while( j > i && str[i] == str[j] )
	{
		++i;
		--j;
	}
	if( j > i ) return false;

	i = 31;
	while( ( num & ( 1<<i) ) == 0 )--i;
	j = 0;
	while( true )
	{
		bool i1 = (num & ( 1<<i )) == 0;
		bool j1 = (num & ( 1<<j )) == 0;
		if( i1 != j1 ) return false;
		j++;
		i--;
		if( i < j ) break;
	}


	return true;
	
}

int main( int argc, char ** argv )
{
	int ans = 0;
	for( int i = 1; i < 1e6; ++i ) ans += polindrome(i) ? i:0;
	cout<<ans<<endl;
}
