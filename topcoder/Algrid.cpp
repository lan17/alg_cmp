#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Algrid 
{
	void alg( string & curr, string & next, string & res )
	{
		for( int i = 0; i < curr.size()-1; ++i )
		{
			char a,b;
			a = curr[i];
			b = curr[i+1];
			if( a=='B' &&  b=='W' )
			{
				res[i] = 'B' = res[i+1] 'B';
			}
			if( 
		}
	}
	
	string getNext( string & curr, string & output )
	{
		
	}
	
	
	public:
	vector <string> makeProgram(vector <string> output) 
	{
		vector<string> res;
		string curr = output[0];
		res.push_back(curr);
		for( int i = 1; i < output.size(); ++i )
		{
			string next;
			for( int j = 0; j < output.size(); ++j )
			{
				
			}
		}
	}
};
