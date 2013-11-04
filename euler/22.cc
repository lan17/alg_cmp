#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

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


int main( int argc, char ** argv )
{
	ifstream ifs( argv[1] );
	string line;
	getline( ifs, line );
	vector<string> names = expand(line,"\",");
	sort( names.begin(), names.end() );
	unsigned long long answer = 0;
	for( size_t i = 0; i < names.size(); ++i )
	{
		unsigned long long score = 0;
		for( size_t j = 0; j < names[i].size(); ++j )
		{
			score += names[i][j] - 'A' + 1;
		}
		score *= i + 1;
		cout<<names[i]<<": "<<score<<endl;
		answer += score;
	}
	cout<<answer<<endl;
}
