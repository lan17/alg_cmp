#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <iostream>

#define in(x,y) ((x).find((y)) != (x).end())
#define d_print(x) cout<<#x<<"="<<x<<endl

using namespace std;

class CubeStickers 
{
	public:
	string isPossible(vector <string> sticker) 
	{
		map<string,int> cols;
		for( int i = 0; i < sticker.size(); ++i )
		{
			cols[sticker[i]] += 1;
		}
		d_print(cols.size());
		if( cols.size() >= 6 ) return "YES";

		int total = 6;

		for(map<string,int>::iterator i = cols.begin(); i != cols.end(); ++i )
		{
			if( i->second > 1 ) total -=2;
			else total -= 1;
		}

		if( total > 0 ) return "NO";
		return "YES";
	}
};


// Powered by FileEdit
