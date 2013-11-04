#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <math.h>
#include <sstream>

#define in(x,y) ((x).find((y)) != (x).end())
#define d_print(x) cout<<#x<<"="<<x<<endl

using namespace std;

class CubeAnts 
{
	public:
	int getMinimumSteps(vector <int> pos) 
	{
		set<int> is;
		for( int i = 0; i < pos.size(); ++i ) is.insert(pos[i]);
		if(in(is,6)) return 3;
		if(in(is,2) || in(is,5) || in(is,7)) return 2;
		if( is.size() == 1 && in(is,0) ) return 0;
		return 1;
	}
};


// Powered by FileEdit
