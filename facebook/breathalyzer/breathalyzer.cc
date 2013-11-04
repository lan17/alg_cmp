#include <iostream>
#include <fstream>
#include <string>
#include <string>
#include <sys/time.h>

#include "RadixTree.h"

using namespace std;

/**
 * Return microsecond difference between start and end 
 */
unsigned long long getTimeSpan( struct timeval start, struct timeval end )
{
	if( start.tv_sec == end.tv_sec )
		return end.tv_usec - start.tv_usec;
	return (end.tv_sec - (start.tv_sec + 1)) * 1e6 + (1e6 - start.tv_usec) + end.tv_usec;
}

/**
 * Return difference in seconds between start and end
 */
double getTimeSpan_seconds( struct timeval start, struct timeval end )
{
	double t = (double) getTimeSpan( start, end );
	return t / 1e6;	
}

string alphastring( string & str )
{
	string t = "";
	for( size_t i = 0; i < str.size(); ++ i )
	{
		if( isalpha( str[i] ) ) t += str[i];
	}
	return t;
}

RadixNode * buildTree()
{
	RadixNode * ret = new RadixNode();
	
	ifstream ifs( "/var/tmp/twl06.txt" );
	while( ifs.good() )
	{
		string t;
		getline( ifs, t );
		t = alphastring( t );
		for( size_t i = 0; i < t.size(); ++i )
			t[i]=tolower(t[i]);
		//cout<<"inserting '"<<t<<"'"<<endl;
		//cout<<t.size()<<endl;
		ret->insert( t );
	}
	return ret;
}

vector<string> expand( const string & input, char delimiter = ' ')
{
     vector<string> out;
     size_t begin = 0;
     size_t i;
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

int main( int argc, char ** argv )
{
	struct timeval start_time,end_time;
	
	//gettimeofday( &start_time, NULL );
	RadixNode * tree = buildTree();
	//gettimeofday( &end_time, NULL );
	//cout<<"Built the tree in "<<getTimeSpan_seconds( start_time, end_time )<< " seconds "<<endl;
	
	//cout<<tree->depth()<<endl;
	///cout<<tree->min_lev_dist2( "shit" )<<endl;
	
	size_t answer = 0;
	
	//gettimeofday( &start_time, NULL );
	ifstream ifs( argv[1] );
	while( ifs.good() )
	{
		string line;
		getline( ifs, line );
		vector<string> words = expand( line );
		for( size_t i = 0; i < words.size(); ++i )
		{
			dist_t min_dist = tree->min_lev_dist3( words[i] );
			answer += min_dist;
		//	cout<<words[i]<<": "<<min_dist<<endl;
		}
	}
	ifs.close();
	//gettimeofday( &end_time, NULL );
	
	//cout<<"Computed in "<< getTimeSpan_seconds( start_time, end_time )<< " seconds"<<endl;
	
	cout<<answer<<endl;
}
