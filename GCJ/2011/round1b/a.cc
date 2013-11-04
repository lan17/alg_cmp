#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

#define d_print(x) cout<<#x<<(x)<<endl;

typedef vector<string> vecs;
typedef unsigned long long ull;

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
	#undef string_find
}

int main( int argc, char ** argv )
{
	string t;
	int T;
	getline( cin, t );
	T = atoi( t.c_str() );
	for( int CASE = 1; CASE <= T; ++CASE )
	{
		int N;
		getline(cin,t);
		N = atoi( t.c_str() );
		vector<string> schedule;

		for( int i = 0; i < N; ++i )
		{
			getline(cin,t);
			schedule.push_back(t);
		}

		map<int,vector<int> > opponents;

		vector<double> team_WP(N,0);
		// element i,j is WP of team j with opponent i
		vector<vector<double> > team_OWP(N);
		vector<double> OWPS(N);
		vector<double> team_OOWP;

		for( int team = 0; team < N; ++team )
		{
			int total = 0;
			int won = 0;
			for( int i = 0; i < N; ++i )
			{
				if( schedule[team][i] != '.' )
				{
					int opposing_team=i;
					opponents[team].push_back(opposing_team);
					total++;
					if( schedule[team][i] == '1' )
					{
						won++;
					}

					int total_o = 0;
					int won_o = 0;
					for( int j = 0; j < N; ++j )
					{
						if( j != team )
						{
							if( schedule[opposing_team][j] != '.')
							{
								total_o++;
								if( schedule[opposing_team][j] == '1' )
								{
									won_o++;
								}
							}
						}
					}
					team_OWP[team].push_back( double(won_o)/double(total_o) );

				}
			}
			team_WP[team] = double(won)/double(total);
			double OWP = 0;
			for( int i = 0; i < team_OWP[team].size(); ++i )
			{
				OWP += team_OWP[team][i];
			}
			OWP /= double(team_OWP[team].size() );
			OWPS[team] = OWP;
		}
		cout<<"Case #"<<CASE<<":\n";
		for( int team = 0; team < N; ++team)
		{
			double WP = team_WP[team];
			double OWP = OWPS[team];
			double OOWP = 0;
			vector<int> & ops = opponents[team];
			for( int i = 0; i < ops.size(); ++i )
			{
				OOWP += OWPS[ops[i]];
			}
			OOWP /= double(ops.size());
			double RPI = 0.25 * WP + 0.5 * OWP + 0.25 * OOWP;
			cout<<RPI<<endl;
		}
	}
}
