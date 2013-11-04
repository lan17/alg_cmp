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
	
	int a = 1;
	int b = 3;
	int sum = 4;
	for( int x = 2; x < X; ++x )
	{
		int c = b + a;
		a = b;
		b = c;
		sum += c;
	}
	cout<<b<<" "<<sum<<endl;
}
