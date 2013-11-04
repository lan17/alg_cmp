#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define d_print(x) cout<<#x<<"="<<(x)<<endl;

typedef vector<string> vecs;
typedef unsigned long long ull;
typedef long long ll;

#define in(x,y) ((x).find((y)) != (x).end())

int main( int argc, char ** argv )
{
	int T;
	cin>>T;
	for( int CASE = 1; CASE <= T; ++ CASE  )
	{
		size_t L,t,N,C;
		cin>>L>>t>>N>>C;
		vector<ll> a;
		double time = 0;
		for( size_t i = 0; i < C; ++i )
		{
			ll z;
			cin>>z;
			a.push_back(z);
		}
		if( a.size() < N )
		{
			int z = a.size();
			int k = z;
			while( a.size() != N )
			{
				a.push_back(a[k%z]);
				++k;
			}
		}
		int first_boost = 0;
		while( time < t )
		{
			double to_next = a[first_boost]*2;
			if( time + to_next >= t )
			{
				
				a.push_back( a[first_boost] - (t-time)*2);
			}
		}
				
		sort( a.begin(), a.end() );
		reverse( a.begin(), a.end() );
		
		int booster_left = L;
		for( size_t i = 0; i < a.size(); ++i )
		{
			time += a[i] * ( booster_left > 0 ? 1 : 2 );
			booster_left--;
		}
		cout<<"Case #"<<CASE<<": "<<ll(time)<<endl;

	}
}
