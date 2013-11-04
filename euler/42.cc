#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <math.h>

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

set<int> make_triangles( )
{
	set<int> ret;
	for( int i = 1; i < 1000; ++i )
	{
		ret.insert( (i*(i+1))/2);
	}
	return ret;
}

int main( int argc, char ** argv )
{
	set<int> nums = make_triangles();

	ifstream ifs( argv[1] );
	string t;
	getline( ifs, t );
	vector<string> words = expand( t, "\",");
	int count = 0;
	for( int i = 0; i < words.size(); ++i )
	{
		string & word = words[i];
		cout<<word<<endl;
		int sum = 0;
		for( int j = 0; j < word.size(); ++j )
		{
			sum += word[j] - 'A' + 1;
		}
		if( nums.find( sum ) != nums.end() ) ++ count;
	}	
	cout<<count<<endl;
}
