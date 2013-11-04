#include <iostream>
#include <map>
#include <vector>
#include <bitset>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ext/hash_map>

namespace std { using namespace __gnu_cxx; }


typedef unsigned long long ull;

using namespace std;

int main( int argc, char ** argv )
{
	int X;
	cin>>X;
	vector<bool> switches(X+1,true);
	for( int i = 1; i <= X; ++i )
	{
		for( int j = i; j <= X; ++j )
		{
			if( j % i == 0 ) switches[j] = !switches[j];
		}
	}
	cout<<(switches[X]?"ON":"OFF")<<endl;
}
