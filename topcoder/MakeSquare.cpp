#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MATRIX_SIZE = 50*50;

// Implementation of Levenshtein algorithm on host.
int levDistHost( const string & a, const string & b )
{
	int M[MATRIX_SIZE];
	//for( int i = 0; i < MATRIX_SIZE; ++i )M[i]=0;
	int x_dim = a.size() + 1;
	int y_dim = b.size() + 1;

	//d_print( x_dim );
	//d_print( y_dim );

	for( int i = 0; i <= x_dim; ++i )
	{
		M[i] = i;
	}
	for( int i = 0; i <= y_dim; ++i )
	{
		M[i * x_dim] = i;
	}

	for( int j = 1; j < y_dim; ++j )
	{
		for( int i = 1; i < x_dim; ++i )
		{
			int * mp = &M[i + j * x_dim];
			if( a[i - 1] == b[j - 1] )
			{
				mp[0] = M[i - 1 + (j - 1) * x_dim];
			}
			else 
			{ 
				mp[0] = M[i - 1 + (j - 1) * x_dim] + 1;
				mp[0] = min( mp[0], M[i + (j - 1) * x_dim] + 1 );
				mp[0] = min( mp[0], M[i - 1 + (j) * x_dim] + 1 );
			}
		}
	}
	return M[a.size() + b.size() * x_dim];
}

class MakeSquare {
	public:
	int minChanges(string S) 
	{
		int mind = 500;
		if( S.size() == 1 ) return 1;
		if( S.size() == 2 )
		{
			if( S[0] != S[1] ) return 1;
			return 0;
		}
		for( int i = 0; i < S.size() - 1; ++i )
		{
			string a = S.substr( 0, i );
			string b = S.substr( i );
			//cout<<a<<endl;
			//cout<<b<<endl; 
		//if( S.size() % 2 == 0 )
			//{
			mind = min( mind, levDistHost( a, b ) );
		//}
		}
		return mind;
		//string a = S.
		
	}
};
