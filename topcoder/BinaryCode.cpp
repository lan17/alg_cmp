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

vector<int> sdo(const vector<int> & message, const string & fc)
{
	vector<int> r1 = fc;
	for( int i = 1; i < message.size(); ++i )
	{
		int bit = message[i];
		for( int j = i; j >= 0; --j )
		{
			bit -= r1[j] - '0';
		}
		r1 += char(bit)+'0';
	}
	return r1;
}

class BinaryCode 
{
	public:
	vector <string> decode(string message) 
	{
		string r1 = sdo( message, "0" );
		string r2 = sdo( message, "1" );
		d_print(r1);
		d_print(r2);
		for( int i = 0; i < r1.size(); ++i )
		{
			if( r1[i] != '0' && r1[i] != '1' ) r1 = "NONE";
			if( r2[i] != '0' && r2[i] != '1' ) r2 = "NONE";
		}
		vector<string> ret(2);
		ret[0] = r1;
		ret[1] = r2;
		return ret;
	}
};
