#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;

int liars_cnt( vector<bool> & liars )
{
	int ret = 0;
	for(size_t i = 0; i < liars.size(); ++i )
	{
		ret += liars[i] ? 1 : 0;
	}
	return ret;
}

bool possible( vector<int> & claim, vector<bool> & liars, int i )
{
	int a = liars_cnt( liars );
	for( int j = 0; j < claim.size(); ++j )
	{
		if( !liars[j] && claim[j] > a ) return false;
	}
	return true;
}

class MinimumLiars 
{
	public:
	int getMinimum(vector <int> claim) 
	{
		int n = claim.size();
		sort( claim.begin(), claim.end() );

		bool allzero = true;
		bool mis_understood = true;
		for( int i = 0; i <n; ++i )
		{
			if( claim[i] != 0 )
			{
				allzero = false;
				//break;
			}
			if( claim[i] != n )
			{
				mis_understood = false;
				//break;
			}
		}
		if( allzero) return 0;
		if( mis_understood) return -1;

		vector<bool> liars(n,false);
		for( size_t i = 0; i < claim.size(); ++i )
		{
			if( claim[i] >= n )
			{
				liars[i] = true;
			}
		}
		
		bool good = false;
		for( int i = n-1; i >= 0; --i )
		{
			liars[i] = true;
			if( possible( claim, liars, i ) )
			{
				good = true;
				break;
			}
		}
		//if( ! good ) return -1;
		int answer = liars_cnt(liars);
		for( int i = 0; i < liars.size(); ++i )
		{
			if( claim[i] == n ) return -1;
			if( liars[i] && claim[i] == answer)
			{
				answer++;
			}
			//if(liars[i] ) ++answer;
		}
		return answer;


	}
};


// Powered by FileEdit
