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

vector<string> possible_words( const string & board, vector<string> & words, map<size_t,vector<int> > & by_length )
{
	vector<string> ret;
	vector<int> & words_ids = by_length[board.size()];
	for( int i = 0; i < words_ids.size(); ++i )
	{
		bool insert = true;
		string & word = words[words_ids[i]];
		for( int j = 0; j < word.size(); ++j  )
		{
			if( ( board[j] != '_' ) && ( word[j] != board[j] ) )
			{
				insert = false;
				break;
			}
		}
		if( insert )
		{
			ret.push_back( word );
		}
	}
	return ret;
}
vector<bool> used(26,false);

int score( const string & word, const string & list,  vector<string> & words, map<size_t,vector<int> > & by_length )//, const vector<int> & words, map<int,vector<int> > & by_length)
{
	vector<int> & words_ids = by_length[word.size()];
	for( int i = 0; i < list.size(); ++i )
		used[i] = false;

	string board( word.size(), '_');
	int left = word.size();
	int list_id = 0;

	int score = 0;
	while( left > 0 )
	{
		list_id = list_id % 26;
		while( used[list_id] )++list_id;

		bool go_on = false;
		for( int i = 0; i < board.size(); ++i )
		{
			if( board[i] == '_' )
			{
				go_on = true;
				break;
			}
		}
		if(!go_on)break;

		list_id = list_id % 26;

		char letter = list[list_id];
		vector<string> possible = possible_words( board, words, by_length );

		if( possible.size() == 1 ) break;

		bool good = false;
		for( int i = 0; i < possible.size(); ++i )
		{
			if( possible[i].find( list[list_id]) != string::npos )
			{
				good = true;
			}
		}
		used[list_id] = true;
		if( ! good )
		{
			//list_id++;
			continue;
		}
		if( good )
		{
			used[list_id] = true;
		}


		bool in_board = false;
		for( int j = 0; j < word.size(); ++j )
		{
			if( word[j] == letter )
			{
				board[j] = letter;
				in_board = true;
			}
		}
		if( in_board ) --left;
		else score++;
	}
	return score;
}

bool score_cmp( const pair<string,int> & a, const pair<string,int> & b )
{
	return a.second > b.second;
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
		vector<string> words, lists;
		map<size_t,vector<int> > by_length;
		//map<string,int> by_id;
		int counter = 0;

		for( int i = 0; i < N; ++i )
		{
			getline(cin,t);
			words.push_back( t );
			int id = counter++;
			by_length[t.size()].push_back(id);
			//by_id[t] = id;

		}
		for( int i = 0; i < M; ++i )
		{
			getline( cin, t );
			lists.push_back( t );
		}

		cout<<"Case #"<<CASE<<": ";

		for( int list = 0; list < M; ++ list )
		{
			vector<pair<string, int > > scores;
			for( int i = 0; i < N; ++i )
			{
				scores.push_back( make_pair( words[i], score( words[i], lists[list], words, by_length)));
			}
			sort( scores.begin(), scores.end(), score_cmp );
			int best_score = scores[0].second;
			string answer;
			int lowest_id = N+1;
			answer = scores[0].first;

			for( int i = 0; i < scores.size() && scores[i].second == best_score; ++i )
			{
				int id = 0;
				for( int j = 0; j < words.size(); ++j )
				{
					if( words[j] == scores[i].first )
					{
						id = j;
						break;
					}
				}
				if( lowest_id > id )
				{
					answer = scores[i].first;
				//	lowest_id = by_id[scores[i].first];
					lowest_id = id;
				}
			}

			cout<<answer;
			if( list < M -1 ) cout<<" ";

		}


		cout<<endl;

	}
}
