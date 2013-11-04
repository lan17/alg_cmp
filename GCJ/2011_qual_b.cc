#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

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
	int T = atoi( t.c_str() );
	for( int CASE = 1; CASE <= T; ++CASE )
	{
		getline( cin, t );
		vector<string> prob = expand( t, " " );
		
		map<pair<char,char>, char> combine;
		map<char,set<char> > opposed;
		int i = 1;
		int tmp;
		int C = atoi( prob[0].c_str() );
		
		for( i = 1; i < 1 + C; ++i )
		{
			combine[make_pair(prob[i][0], prob[i][1] )] = prob[i][2];
			combine[make_pair(prob[i][1], prob[i][0] )] = prob[i][2];
		}
		int D = atoi( prob[i++].c_str() );
		tmp = i;
		for( ; i < tmp + D; ++i )
		{
			opposed[prob[i][0]].insert( prob[i][1] );
			opposed[prob[i][1]].insert( prob[i][0] );
		}
		int N = atoi( prob[i++].c_str() );
		string seq = prob[i];
		
		vector<char> rseq;
		set<char> sseq;
		
		for( int j = 0; j < seq.size(); ++j )
		{
			rseq.push_back( seq[j] );
			sseq.insert( seq[j] );
			
			if( rseq.size() >= 2 )
			{
				char a = rseq[rseq.size()-2];
				char b = rseq[rseq.size()-1];
				if( combine.find( make_pair(a,b) ) != combine.end() )
				{
					char c= combine[make_pair(a,b)];
					rseq[rseq.size()-2] = c;
					rseq.pop_back();
					sseq.erase( a );
					sseq.erase( b );
					sseq.insert( c );
					//continue;
				}
			}
			
			for( map<char,set<char> >::iterator oi = opposed.begin(); oi != opposed.end(); ++oi )
			{
				if( sseq.find( oi->first) != sseq.end() )
				{
					for( set<char>::iterator k = oi->second.begin(); k != oi->second.end(); ++k )
					{
					if( sseq.find( *k ) != sseq.end() )
					{
						rseq.clear();
						sseq.clear();
						break;
					}
				}
				}
			}
			
			
		}
		
		cout<<"Case #"<<CASE<<": [";
		if( rseq.size() > 0 )
		{
			for( int j = 0; j < rseq.size()-1; ++j )
			{
				cout<<rseq[j]<<", ";
			}
			if( rseq.size() > 0 ) cout<<rseq[rseq.size()-1];
		}
		cout<<"]"<<endl;
		
	}
}
