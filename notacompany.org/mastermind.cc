#include <iostream>
#include <string>

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */

#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

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
}

char colors [6] = {'R', 'O', 'Y', 'G', 'B', 'V' };
set<string> allGuesses;

void genAllGuesses( string t, int i )
{
	if( t.size() == 4 )
	{
		allGuesses.insert( t );
		return;
	}
	t += colors[i];
	for( int j = 0; j < 6; ++j )
	{
		genAllGuesses( t, j );
	}
}

void genAllGuesses()
{
	string t;
	for( int i = 0; i < 6; ++i ) genAllGuesses(t,i);
}

bool couldBe( string couldBe, string guess, int x, int y )
{
	int X, Y;
	X = Y = 0;
	bool meh[4] = {false, false, false, false };
	for( int i = 0; i < 4; ++i )
	{
		if( couldBe[i] == guess[i] )
		{
			++X;
			meh[i] = true;
		}
	}
	for( int i = 0; i < 4; ++i )
	{
		for( int j = 0; j < 4; ++j )
		{
			if(meh[i] || meh[j] ) continue;
			if( i == j ) continue;
			if( couldBe[i] == guess[j] )
			{
				++Y;
				meh[i] = meh[j] = true;
			}
			
		}
	}
	//cout<<X<<" "<<Y<<endl;
	return X ==x && Y ==y;
}

int main( int argc, char ** argv )
{	
	
	cout<<couldBe("ROBG", "GGRY", 0, 2 )<<endl;
	///return 0;
	
	genAllGuesses();
	cout<<allGuesses.size()<<endl;
	cout<<*allGuesses.find("ROBG")<<endl;
		
	string t;
	getline( cin, t );
	int n = atoi( t.c_str() );
	for( int i = 0; i < n; ++i )
	{
		getline(cin,t);
		
		vector<string> line = expand(t, " " );
		string guess = line[0];
		int x = atoi( line[1].c_str() );
		int y = atoi( line[2].c_str() );
		
		set<string> guesses;
		FOREACH( i, allGuesses )
		{
			if( couldBe( guess, *i, x, y ) )
			{
				guesses.insert( *i );
			}
		}
		allGuesses = guesses;
	}
	if( allGuesses.size() == 1 )
	{
		cout<<*allGuesses.begin()<<endl;
	}
	else
	{
		cout<<allGuesses.size()<<endl;
		FOREACH( i, allGuesses )
		{
			cout<<*i<<endl;
		}
	}
}
