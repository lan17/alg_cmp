#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <cstdio>
#include <valarray>      
#include <ext/hash_set> 
#include <ext/hash_map>
#include "float.h"

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define print(x) cout<<#x<<" = "<<(x)<<endl;

using namespace std;
class ToolsBox {
	public:
	int countTools(vector <string> need) 
	{
		set<string> tools;
		FOREACH(tool_set,need)
		{
			string toolz = *tool_set;
			int p = 0;
			for( int i = 0; i < toolz.size();++i)
			{
				if( toolz[i]== ' ')
				{
					string new_tool =toolz.substr(p,i-p);
					tools.insert(new_tool);
					p =  i +1;
				}
				if( i==toolz.size()-1)
				{
					tools.insert(toolz.substr(p));
				}
			}
		}
		FOREACH(tool,tools)
		{
			cout<<*tool<<endl;
		}
		return tools.size();
	}
};


// Powered by FileEdit
