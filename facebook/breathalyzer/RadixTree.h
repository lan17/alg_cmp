#pragma once

#include <map>
#include <string>
#include <vector>

using namespace std;

typedef unsigned int dist_t;

class RadixNode
{
		map<char, RadixNode*> children;
		std::string * word;
		static dist_t t;
		static const dist_t _inf = 1<<30;
		
		dist_t min_lev_dist_rec( char edge_char, const string & word, vector<dist_t> & prev_row );
		dist_t min_lev_dist_rec2( char edge_char, const string & word, vector<vector<dist_t> > & dem_rows, int level = 1 );
		dist_t min_lev_dist_rec3( char edge_char, const string & word, vector<vector<dist_t> > & dem_rows, int level = 1 );
		
	public:
		
		RadixNode();
		
		dist_t depth( );
		
		void insert( const std::string & word );
		dist_t min_lev_dist( const string & word );
		dist_t min_lev_dist2( const string & word );
		dist_t min_lev_dist3( const string & word );
};
