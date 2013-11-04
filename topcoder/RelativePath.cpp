#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>


#define vecs vector< string > 
#define veci vector< int >
#define vecsi vector<string>::iterator
#define vecii vector<int>::iterator
#define vec vector


using namespace std;

vecs expand( const string & input, char delimiter )
{
     vecs out;
     int begin = 0;
     int i;
     for( i = 0; i < input.length( ); i++ )
     {
          if( i > 0 && input[i] == delimiter && input[i-1] != delimiter ) 
          { 
              out.push_back( input.substr( begin, i - begin ) ); 
              begin = i+1 ;
          }
          else
          {
              if( input[i] == delimiter ){ begin = i+1; }
          }
     }
     if( begin < i )
     {
         out.push_back( input.substr( begin ) );
     }
     return out;
}

class RelativePath 
{
	public:
	string makeRelative(string path, string currentDir)
	{
		vecs p = expand( path, '/' );
		vecs c = expand( currentDir, '/' );
		int i, n = max( p.size(), c.size() );

		for( i = 0; i < p.size() && i < c.size(); ++i )
		{
			if( p[i] != c[i] ) break;
		}
		
		string ret = "";
		for( int j = 0; j < c.size() - i; ++j )
		{
			ret += "../";
		}
		for( int j = i; j < p.size(); ++j )
		{
			ret += p[j];
			if( j < p.size() - 1 ) ret += "/";
		}
		return ret;
	}
};

/* Lev A Neiman's coding here */
