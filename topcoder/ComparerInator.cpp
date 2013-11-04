#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class ComparerInator 
{
	public:
	int makeProgram(vector <int> A, vector <int> B, vector <int> wanted) 
	{
		int len[4] = { 1,1,7,7};
		bool prgs[4] = {true,true,true,true};
		
		int p = 0;
		int n = A.size();
		
		for( int i = 0; i < n; ++i )
		{
			if( A[i] != wanted[i] ) prgs[0] = false;
			if( B[i] != wanted[i] ) prgs[1] = false;
			//int m = max(A[i],B[i] );
			
			bool as = A[i] < B[i];
			
			if( as && B[i] == wanted[i] ) prgs[3] = false;
			if( !as && A[i] == wanted[i] ) prgs[2] = false;
			
			//if( ( wanted[i] == A[i] ) && ( wanted[i] != B[i] )) prgs[3] = false;
			//if( ( wanted[i] == B[i] ) && ( wanted[i] != A[i] )) prgs[2] = false;
		}
		
		for( int i = 0; i < 4; ++i )
		{
			if( prgs[i] ) return len[i];
		}
		return -1;
	}
};
