#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define d_print(x) cout<<#x<<"="<<(x)<<endl

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

bool cmp( const pair<double, pair<int,int> > & a, const pair<double, pair<int,int> > & b )
{
	return a.first > b.first;
}


int main( int argc, char ** argv )
{
	string fname = argv[1];
	ifstream ifs( fname.c_str() );
	string t;
	getline(ifs,t);
	
	int W = atoi( t.c_str() );
	// weight / value
	vector<pair<double, pair<int,int> > > items;
	
	while( ifs.good() )
	{
		getline(ifs,t);
		vector<string> line = expand(t," \t" );
		if( line.size() < 3 ) break;
		int w,v;
		w = atoi( line[1].c_str() );
		v = atoi( line[2].c_str() );
		double r = double(w)/double(v);
		items.push_back( make_pair(r,make_pair(w,v)) );
	}
	sort( items.begin(), items.end(), cmp );

	if( W > items[0].second.first )
	{
		int w = items[0].second.first;
		int val = items[0].second.second;
		d_print(w);

		int M = W / w;
		int v = M * val;
		int left = W % w;

		d_print(M);
		d_print(v);
		d_print(left);

		int v_min = (int)1e29;
		for( int i = 0; i < items.size(); ++i )
		{
			if( items[i].second.first >= left )
			{
				v_min = min(v+items[i].second.second, v_min );
			}
		}
		cout<<v_min<<endl;
	}
}
