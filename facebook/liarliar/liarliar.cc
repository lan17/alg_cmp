#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

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

unsigned int getNameId( map<string,unsigned int> & m, string & name )
{
	static unsigned int counter = 0;
	if( m.find( name ) != m.end() ) return m[name];
	m[name] = counter++;
	return m[name];
}

unsigned int solve( map<unsigned int, vector<unsigned int> > & liars, vector<char> & tt, unsigned int truther )
{
	
}

int main( int argc, char ** argv )
{
	map<unsigned int, vector<unsigned int> > liars;
	map<string,unsigned int> names;
	unsigned int counter = 0;
	
	ifstream ifs( argv[1] );
	int n;
	ifs>>n;
	while( ifs.peek() == '\n' || ifs.peek() =='\r' ) ifs.ignore();
	for( int i = 0; i < n; ++i )
	{
		string t;
		getline( ifs, t );
		//cout<<t<<endl;
		vector<string> accuser = expand( t );
		unsigned int a_id = getNameId( names, accuser[0] );
		int m = atoi( accuser[1].c_str() );
		for( int j = 0; j < m; ++j )
		{
			getline( ifs, t );
			liars[a_id].push_back( getNameId( names, t ) );
		}
	}
	for( map<string, unsigned int>::iterator i = names.begin(); i != names.end(); ++i )
	{
		cout<<i->first<<": "<<i->second<<endl;
	}
	for( map<unsigned int,vector<unsigned int> >::iterator i = liars.begin(); i != liars.end(); ++i )
	{
		cout<<i->first<<": ";
		for( int j = 0; j < i->second.size(); ++j )
		{
			cout<<i->second[j]<<", ";
		}
		cout<<endl;
	}
}
