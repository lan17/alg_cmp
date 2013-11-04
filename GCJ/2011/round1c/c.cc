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
	for( int CASE =1 ; CASE<=T; ++CASE )
	{
		int N,L,H;
		cin>>N>>L>>H;
		vector<int> notes;
		for( int i = 0; i < N; ++i )
		{
			int t;
			cin>>t;
			notes.push_back(t);
		}
		int answer = -1;
		for( int p = L; p <=H; ++p )
		{
			bool good = true;
			for( int i = 0; i < notes.size(); ++i )
			{
				if( notes[i] % p != 0 && p%notes[i] != 0 )
				{
					good = false;
					break;
				}
			}
			if( good )
			{
				answer = p;
				break;
			}
		}
		cout<<"Case #"<<CASE<<": ";
		if( answer == -1 ) cout<<"NO";
		else cout<<answer;
		cout<<endl;
	}
}
