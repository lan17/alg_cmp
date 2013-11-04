#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>

using namespace std;

#define d_print(x) { cerr << __LINE__ << " " << #x << " = " << x << endl; cerr.flush(); }

typedef vector<string> vecs;
typedef vector<int> veci;
typedef unsigned long long ull;
typedef long long ll;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

class NetworkXMessageRecovery 
{
	public:
	string recover(vector <string> messages) 
	{
		map<char,set<char> > followers;
		for( size_t i = 0; i < messages.size(); ++i )
		{
			for( int j = 0; j < messages[i].size(); ++j )
			{
				for( int k = j + 1; k < messages[i].size(); ++k )
				{
					followers[messages[i][j]].insert(messages[i][k]);
				}
			}
		}
	}
};
