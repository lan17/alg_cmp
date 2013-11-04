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
#include <math.h>

#include <ext/hash_map>


namespace std { using namespace __gnu_cxx; }


typedef unsigned long long ull;

using namespace std;

#define eat_shit() while(cin.peek() =='\n' || cin.peek() =='\r') cin.ignore()

int main( int argc, char ** argv )
{
	int X;
	string t;
	vector<string> strs;
	getline(cin,t);
	X = atoi( t.c_str() );
	int max_size = 0;
	for( int i = 0; i < X; ++i )
	{
		eat_shit();
		getline(cin, t );
		eat_shit();
		strs.push_back( t );
		max_size = max( (size_t)max_size, t.size() );
	}

//	cout<<"max_size = "<<max_size<<endl;
	
	for( int i = 0; i < strs.size(); ++i )
	{
		for( int j = 0; j <  max_size - strs[i].size(); ++j )
		{
			cout<<"*";
		}
		cout<<strs[i]<<endl;
	}
}
