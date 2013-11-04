#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;
typedef vector<string> vecs;
typedef unsigned long long ull;

#define in(x,y) ((x).find((y)) != (x).end())
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

// Implementation of Levenshtein algorithm on host.
int levDistHost( const string & a, const string & b )
{
	static int M[200];
	for( int i = 0; i < 200; ++i )
		M[i]=0;
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



bool lev_dist_cmp( const pair<int,int> & a, const pair<int,int> & b )
{
	return a.second < b.second;
}

bool scores_cmp( const pair<string,int> & a, const pair<string,int> & b )
{
	return a.second > b.second;
}

int score( const string & word, const string & list )//, const vector<int> & words, map<int,vector<int> > & by_length)
{
	return levDistHost( word, list );
}

int main( int argc, char ** argv )
{
	string t;
	getline(cin,t);
	int T = atoi( t.c_str() );
	for( int CASE = 1; CASE <= T; ++CASE )
	{
		getline(cin,t);
		vecs line = expand( t, " " );
		int N,M;
		N = atoi( line[0].c_str() );
		M = atoi( line[1].c_str() );
		vecs words, lists;
		map<size_t,vector<int> > by_length;
		map<string,int> by_id;
		int counter = 0;

		for( int i = 0; i < N; ++i )
		{
			getline(cin,t);
			words.push_back( t );
			int id = counter++;
			by_length[t.size()].push_back(id);
			by_id[t] = id;

		}
		for( int i = 0; i < M; ++i )
		{
			getline( cin, t );
			lists.push_back( t );
		}

		cout<<"Case #"<<CASE<<": ";

		for( int list = 0; list < M; ++ list )
		{
			vector<pair<string,int> > scores;
		for( int i = 0; i < N; ++i )
		{
			if( by_length[words[i].size()].size() == 1 )
			{
				scores.push_back( make_pair( words[i], 0 ));
			}
			else
			{
				vector<int> & group_words = by_length[words[i].size()];
				int gn = group_words.size();
				vector<vector<int> > lev_dists( gn, vector<int>(gn, -1));
				for( int z = 0; z < gn; ++z )
				{
					for( int x = 0; x < gn; ++x )
					{
						int z1 = group_words[z];
						int x1 = group_words[x];
						lev_dists[z][x] = lev_dists[x][z] = levDistHost( words[z1], words[x1]  );
					}
				}
				// id 2 min lev dist;
				vector<pair<int,int> > min_lev_dists(gn);
				for( int z = 0; z < gn; ++z )
				{
					min_lev_dists.push_back(make_pair(z,1<<29));
					for( int x = 0; x < gn; ++x )
					{
						if( x == z ) continue;
						min_lev_dists[z].second = min( min_lev_dists[z].second, lev_dists[z][x] );
					}
				}
				sort( min_lev_dists.begin(), min_lev_dists.end(), lev_dist_cmp );
				int min_lev_dist = min_lev_dists[0].second;
				for( int z = 0; z < min_lev_dists.size() && min_lev_dists[z].second == min_lev_dist; ++ z )
				{
					string & word = words[ group_words[min_lev_dists[z].first] ];
					scores.push_back( make_pair(word, score( word, lists[list]) ));
				}



			}
		}

		sort( scores.begin(), scores.end(), scores_cmp );

		for( int z = 0; z < scores.size(); ++z )
		{
			cout<<scores[z].first<<" "<<scores[z].second<<endl;
		}

		int best_score = scores[0].second;
		int lowest_id = words.size()+1;
		string answer;
		for( int z = 0; z < scores.size() && scores[z].second == best_score; ++z )
		{
			if( lowest_id > by_id[scores[z].first])
			{
				answer = scores[z].first;
				lowest_id = by_id[scores[z].first];
			}
		}
		cout<<answer<<" ";

		}
		cout<<endl;

	}
}
