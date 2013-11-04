#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

#define d_print(x) cout<<#x<<(x)<<endl;

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
	#undef string_find
}

int main( int argc, char ** argv )
{
	string t;
	getline(cin,t);
	int T = atoi(t.c_str() );
	for( int CASE = 1; CASE <= T; ++CASE )
	{
		getline( cin, t );
		vector<string> moves = expand( t, " " );
		int O_P = 1;
		int B_P = 1;
		int time = 0;
		for( int i = 1; i < moves.size(); i += 2 )
		{
		//	cout<<O_P<<" : "<<B_P<<endl;
			int time_taken = 0;
			int button = atoi(moves[i+1].c_str());
			int NO = -1;
			int NB = -1;
			
			for( int j = i; j < moves.size(); j += 2 )
			{
				if( NO != -1 && NB != -1 ) break;
				if( moves[j][0] == 'O' )
					NO = atoi( moves[j+1].c_str());
				if( moves[j][0] == 'B' )
					NB = atoi( moves[j+1].c_str());
			}
		//	d_print(NO);
		//	d_print(NB);
			int B_P_D;
			int O_P_D;
			switch (moves[i][0])
			{
				case 'O':
					time_taken = abs( button - O_P ) + 1;
					O_P = button;
					
					B_P_D = B_P - NB;
					if( B_P_D < 0 )
					{
						B_P += min( time_taken, abs(B_P_D) );
					}
					if( B_P_D > 0 )
					{
						B_P -= min( time_taken, abs(B_P_D) );
					}					
					break;
					
				case 'B':
					time_taken = abs( button - B_P ) + 1;
					B_P = button;
					O_P_D = O_P - NO;
					if( O_P_D < 0 )
					{
						O_P += min( time_taken, abs(O_P_D) );
					}
					if( O_P_D > 0 )
					{
						O_P -= min( time_taken, abs(O_P_D) );
					}			
					break;
			}
			//cout<<time_taken<<endl;
			time += time_taken;		
		}
		cout<<"Case #"<<CASE<<": "<<time<<endl;
	}
}
