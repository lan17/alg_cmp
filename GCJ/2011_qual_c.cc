#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define d_print(x) cout<<#x<<(x)<<endl;

long long p_add( long long a, long long b )
{
	long long c = ~(a & b);
	a &= c;
	b &= c;
	return a + b;
}

int main( int argc, char ** argv )
{
	/*
	cout<<p_add(12,5)<<endl;
	cout<<p_add(5,4)<<endl;
	cout<<p_add(7,9)<<endl;
	cout<<p_add(50,10)<<endl;
	*/
	
	int T;
	cin>>T;
	for( int CASE=1; CASE<=T; ++CASE)
	{
		int N;
		cin>>N;
		long long accum = 0;
		vector<long long> C;
		for( int i = 0; i < N;++i)
		{
			long long c;
			cin>>c;
			C.push_back(c);
			accum = p_add(accum,c);
		}
		if( accum != 0 )
		{
			cout<<"Case #"<<CASE<<": NO"<<endl;
			continue;
		}
		sort(C.begin(),C.end());
		
		long long answer = 0;
		for( int i = 0; i < C.size(); ++i )
		{
			answer += C[i];
		}
		answer -= C[0];
		cout<<"Case #"<<CASE<<": "<<answer<<endl;
	}
	
	
}
