#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;


inline bool string_find( const string & del, const char & k )
{
	return del.find(k) != string::npos;
}

vector<string> expand( const string & input, string delimiters = " \t")
{
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


int score( vector<int> & a, vector<int> & b )
{
	int answer = 0;
	int base = a.size();
	for( int i = 0; i < a.size(); ++i, --base )
	{
		if( i < b.size() && a[i] == b[i] )
		{
			answer += base*base;
		}
		else
		{
			bool good = false;
			for( int j = 0; j < b.size(); ++j )
			{
				if( a[i]==b[j] )
				{
					good = true;
					if( i < j )
					{
						answer += base;
					}
					break;
				}
			}
			if( ! good ) answer += base;
		}
		
	}
	return answer;
}

bool cmp( const pair<int,int> & a, const pair<int,int> & b )
{
	if( a.second == b.second ) return a.first > b.first;
	return a.second > b.second;
}

#define eat_shit() while( ifs.peek() == '\n' || ifs.peek() == '\r' ) ifs.ignore()

int main( int argc, char ** argv )
{
	fstream ifs( argv[1] );

	int n,m;
	ifs>>n>>m;
	eat_shit();

	
	vector<vector< pair<int, int > > > prefs(n,vector<pair<int,int> >(n, make_pair(0,0) ) );
	vector<vector<int> > coffe_prefs( n, vector<int>(0));
	
	eat_shit();
	for( int i = 0; i < m; ++i )
	{
		string use_less_shit;
		getline(ifs,use_less_shit);
	}
	for( int i = 0; i < n; ++i )
	{
		string t;
		getline( ifs, t );
		vector<string> line = expand( t, "\t ," );
		for( int j = 0; j < line.size() - 1; ++j )
		{
			coffe_prefs[atoi(line[0].c_str())].push_back( atoi(line[j+1].c_str() ) );
		}
	}

	// compute preferences.
	for( int p = 0; p < n / 2; ++ p )
	{
		for( int j = 0; j < n / 2; ++j )
		{
			prefs[p][j+n/2] = make_pair( j+n/2, score( coffe_prefs[p], coffe_prefs[j+n/2] ) );
			prefs[j+n/2][p] = make_pair( p, score( coffe_prefs[j+n/2], coffe_prefs[p] ) );
		}
	}

	for( int i = 0; i < n; ++i )
	{
		sort( prefs[i].begin(), prefs[i].end(), cmp );

//		#define print_prefs

#ifdef print_prefs
		cout<<i<<": ";
		for( int j = 0; j < prefs.size(); ++j )
		{
			cout<<"{"<<prefs[i][j].first<<","<<prefs[i][j].second<<"} ";
		}
		cout<<endl;
#endif

		
	}
	vector<bool> taken(n, false );
	vector<vector<bool> > proposed( n , vector<bool>(n,false ) );
	int left = n/2;
	map<int,int> prefs_pers;
	/*
	for( int i = 0; i < n/2; ++i )
	{
		int t = prefs[i][0].first;
		if( prefs[t][0].first == i ) // we have people who always prefer each other.
		{
			taken[i] = taken[t] = true;
			prefs_pers[i] = t;
			--left;
		}
	}
	*/
#ifdef print_prefs
	cout<<"==========================="<<endl;
	for( int i = 0; i < n; ++i )
	{
		if( taken[i] ) continue;
		cout<<i<<": ";
		for( int j = 0; j < prefs.size(); ++j )
		{
			if( taken[prefs[i][j].first] ) continue;
			cout<<"{"<<prefs[i][j].first<<","<<prefs[i][j].second<<"} ";
		}
		cout<<endl;
	}
#endif

	while( left > 0 )
	{
		//pair<int,int> best_pair;
		//int best_score = 0;
		
		for( int i = 0; i < n/2; ++i )
		{
			if( taken[i] ) continue;
			for( int j = 0; j < prefs[i].size(); ++j )
			{				
				int jp = prefs[i][j].first;
				if( proposed[i][jp] ) continue;
				proposed[i][jp] = true;
				//if( ! taken[jp] )
				if( !taken[jp] )
				{
					/*
					if( best_score < prefs[i][j].second )
					{
						best_score = prefs[i][j].second;
						best_pair = make_pair( i, prefs[i][j].first );
					}
					*/	
					prefs_pers[i] = jp;
					prefs_pers[jp] = i;
					//cout<<"FUCKING CHRIST "<<i<<" " <<jp<<endl;
					taken[i] = taken[jp] = proposed[i][jp] = true;
					--left;
					break;			
				}
				else
				{
					bool jp_prefer_i = false;
					int jp_curr_pref = prefs_pers[jp];
					bool t1 = false;
					bool t2 = false;
					for( int t = 0; t < prefs[jp].size(); ++t )
					{
						if( prefs[jp][t].first == jp_curr_pref ) t1 = true;
						if( prefs[jp][t].first == i ) t2 = true;
						if( t2 && !t1 )
						{
							jp_prefer_i = true;
							//cout<<i<<" "<<jp<<" "<<jp_curr_pref<<endl;
							break;
						}
						if( t1 && !t2 ) break;
					}
					if( jp_prefer_i )
					{
						//cout<<i<<" "<<jp<<" "<<jp_curr_pref<<endl;
						taken[i] = taken[jp] = true;
						taken[jp_curr_pref] = false;
						prefs_pers[i] = jp;
						prefs_pers[jp] = i;
						break;
					}
				}
			}
		}
		/*
		prefs_pers[best_pair.first] = best_pair.second;
		taken[best_pair.first] = taken[best_pair.second] = true;
		--left;
		*/
	}
	/*
	for( map<int,int>::iterator i = prefs_pers.begin(); i != prefs_pers.end(); ++ i )
	{
		cout<<i->first<<" "<<i->second<<endl;
	}
	*/
	cout<<0<<" "<<prefs_pers[0];
	for( int i = 1; i < n/2; ++i )
	{
		cout<<"\n"<<i<<" "<<prefs_pers[i];
	}
	cout<<endl<<endl;;
}
