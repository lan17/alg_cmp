#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define d_print(x) cout<<#x<<"="<<(x)<<endl;

typedef vector<string> vecs;
typedef unsigned long long ull;
typedef long long ll;

#define in(x,y) ((x).find((y)) != (x).end())

vector<string> expand( const string & input, string delimiters = " \t")
{
	#define string_find(del,k) ((del).find((k)) != string::npos)
	vector<string> out;
	size_t begin = 0;
	size_t i;
	for( i = 0; i < input.length( ); i++ )
	{
		if( i > 0 && string_find( delimiters, input[i] ) && !string_find( delimiters, input[i-1] ) )
		{
			out.push_back( input.substr( begin, i - begin ) );
			begin = i+1 ;
		}
		else
		{
			if( string_find( delimiters, input[i] ) ){ begin = i+1; }
		}
	}
	if( begin < i )
	{
		out.push_back( input.substr( begin ) );
	}
	return out;
}




int main( int argc, char ** argv )
{

	vector<char> diam;
	diam.push_back( '/');
	diam.push_back('\\');
	diam.push_back('\\');
	diam.push_back('/');

	string t;
	int T;
	getline( cin, t );
	T = atoi(t.c_str() );

	for( int CASE = 1; CASE <=T; ++CASE )
	{
		int R,C;
		getline( cin, t );
		vecs line = expand( t, " " );
		R = atoi( line[0].c_str() );
		C = atoi( line[1].c_str() );

		vector<string> board;
		for( int r = 0; r < R; ++r )
		{
			getline( cin, t );
			board.push_back( t );
		}
		int white_cnt = 0;
		int blue_cnt = 0;
		for( int i = 0; i < R; ++i )
		{
			for( int j = 0; j < C; ++j )
			{
				if( board[i][j] == '.' )
				{
					white_cnt++;
				}
				if( board[i][j] == '#' )
				{
					blue_cnt++;
				}
			}
		}
		string answer;
		if( blue_cnt == 0 )
		{
			for( int i = 0; i < R; ++i )
			{
				for( int j = 0; j < C; ++j )
				{
					answer += board[i] + "\n";
				}
			}
		}
		else
		{
			int g_cnt = 1;
			vector<vector<int> > i_board( R, vector<int>(C, -1 ));
			for( int i = 0; i < R; ++i )
			{
				for( int j = 0; j < C; ++j )
				{
					if( board[i][j] == '.' ) i_board[i][j] = 0;
					if( i_board[i][j] > -1 ) continue;
					if( board[i][j] == '#' && i_board[i][j] == -1 )
					{
						bool good = true;
						int cnt = 0;
						for( int i1 = i; i1 <= i + 1 && i1 < R; ++i1 )
						{
							for( int j1 = j; j1 <= j +1 && j1 < C; ++j1 )
							{
								if( board[i1][j1] == '#' )
								{
									++cnt;
								}
								else
								{
									good = false;
									break;
								}
							}
							if( !good) break;
						}
						if( good && cnt == 4 )
						{
							for( int i1 = i; i1 <= i + 1 && i1 < R; ++i1 )
							{
								for( int j1 = j; j1 <= j +1 && j1 < C; ++j1 )
								{
								//	if( board[i1][j1] == '#' && i_board[i1][j1] == -1 )
									{
										i_board[i1][j1] = g_cnt;
									}
								}
							}
							g_cnt++;
						}
					}
				}
			}

			for( int i = 0; i < R; ++i )
			{
				for( int j = 0; j < C; ++j )
				{
			//		cout<<i_board[i][j]<<" ";
				}
			//	cout<<endl;
			}

			vector<string> new_board = board;
			vector<vector<bool > > done( R, vector<bool>(C, false ));
			bool possible = true;
			for( int i = 0; i < R; ++i )
			{
				for( int j = 0; j < C; ++j )
				{
					if( i_board[i][j] == -1 )
					{
						possible=false;
						break;
					}
					if( !done[i][j] )
					{
						done[i][j] = true;
						if( board[i][j] == '#' )
						{

							int cnt = 0;
							for( int i1 = i; i1 <= i + 1 && i1 < R; ++i1 )
							{
								for( int j1 = j; j1 <= j +1 && j1 < C; ++j1 )
								{
									new_board[i1][j1] = diam[cnt++];
									done[i1][j1] = true;
								}
							}
						}
					}
				}
				if(! possible) break;
			}
			if( !possible)
			{
				answer = "Impossible\n";
			}
			else
			{
				for( int i = 0; i < R; ++i )
				{
					//for( int j = 0; j < C; ++j )
					{
						answer += new_board[i] +"\n";
					}
				}
			}

		}

		cout<<"Case #"<<CASE<<":"<<endl<<answer;



	}
}
