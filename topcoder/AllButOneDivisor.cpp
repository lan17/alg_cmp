#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;

int gcd( int a, int b )
{
	if( b == 0 ) return a;
	return gcd( b, a % b );
}

int lcm( int a, int b )
{
	return (a*b)/gcd(a,b);
}

class AllButOneDivisor 
{
	public:
	int getMinimum(vector <int> d)
	{
		int answer = 1<<29;
		int n = d.size();
		for( int i = 0; i < n; ++i )
		{
			int l = 1;
			for( int j = 0; j < n; ++j )
			{
				if( i == j ) continue;
				l = lcm( l, d[j] );
			}
			if( l %  d[i] != 0 )
			{
				answer = min( answer, l );
			}
		}
		if( answer == 1<<29) return -1;
		return answer;
	}
};
