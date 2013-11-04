#include "RadixTree.h"

dist_t RadixNode::t = RadixNode::_inf;

RadixNode::RadixNode()
{
	word = NULL;
}

void RadixNode::insert( const std::string & word )
{
	RadixNode * curr = this;
	for( size_t i = 0; i < word.size(); ++i )
	{
		if( curr->children.find( word[i] ) == curr->children.end() )
		{
			curr->children[word[i]] = new RadixNode();
		}
		curr = curr->children[word[i]];
	}
	curr->word = new string(word);
}

dist_t RadixNode::depth( )
{
	if( children.size() == 0 ) return 1;
	dist_t ret = 0;
	for( map<char,RadixNode*>::iterator i = children.begin(); i != children.end(); ++i )
	{
		ret = max( ret, 1 + i->second->depth() );
	}
	return ret;
}

dist_t RadixNode::min_lev_dist_rec( char edge_char, const string & word, vector<dist_t> & prev_row )
{
	vector<dist_t> curr_row( word.size() + 1 );
	curr_row[0] = prev_row[0] + 1;
	for( size_t i = 1; i <= word.size(); ++i )
	{
		if( word[i-1] != edge_char )
		{
			dist_t rep_cost = prev_row[i-1] + 1;
			dist_t ins_cost = curr_row[i-1] + 1;
			dist_t del_cost = prev_row[i] + 1;
			curr_row[i] = min( ins_cost, min( del_cost, rep_cost ) );
		}
		else
			curr_row[i] = prev_row[i-1];
		
	}
	dist_t ret = _inf;
	if( this->word != NULL )
	{
		ret = curr_row[word.size()];
	}
	if( children.size() == 0 ) return ret;
	for( map<char, RadixNode*>::iterator i = children.begin(); i != children.end(); ++i )
	{
		ret = min( ret, i->second->min_lev_dist_rec( i->first, word, curr_row ) );
	}
	return ret;
}

dist_t RadixNode::min_lev_dist( const string & word )
{
	RadixNode::t = _inf;
	
	vector<dist_t> curr_row( word.size()+1 );
	for( size_t i = 0; i <= word.size(); ++i )
		curr_row[i] = i;
	
	dist_t answer = _inf;
	
	for( map<char,RadixNode*>::iterator i = children.begin(); i != children.end(); ++i )
	{
		answer = min( answer, i->second->min_lev_dist_rec( i->first, word, curr_row ) );
	}
	return answer;
}

dist_t RadixNode::min_lev_dist_rec2( char edge_char, const string & word, vector<vector<dist_t> > & dem_rows, int level )
{
	vector<dist_t> & prev_row = dem_rows[level-1];
	vector<dist_t> & curr_row = dem_rows[level];
	curr_row[0] = prev_row[0] + 1;
	for( size_t i = 1; i <= word.size(); ++i )
	{
		if( word[i-1] != edge_char )
		{
			dist_t rep_cost = prev_row[i-1] + 1;
			dist_t ins_cost = curr_row[i-1] + 1;
			dist_t del_cost = prev_row[i] + 1;
			curr_row[i] = min( ins_cost, min( del_cost, rep_cost ) );
		}
		else
			curr_row[i] = prev_row[i-1];
		
	}
	dist_t ret = _inf;
	if( this->word != NULL )
	{
		ret = curr_row[word.size()];
	}
	if( children.size() == 0 ) return ret;
	for( map<char, RadixNode*>::iterator i = children.begin(); i != children.end(); ++i )
	{
		ret = min( ret, i->second->min_lev_dist_rec2( i->first, word, dem_rows, level + 1) );
	}
	return ret;
}

dist_t RadixNode::min_lev_dist2( const string & word )
{
	dist_t dat_deepnezz = depth();
	vector<vector<dist_t> > table( dat_deepnezz + 1, vector<dist_t>( word.size() + 1, 0 ) );
	for( size_t i = 0; i <= word.size(); ++i )
	{
		table[0][i] = i;
	}
	
	dist_t answer = _inf;
	for( map<char,RadixNode*>::iterator i = children.begin(); i != children.end(); ++i )
	{
		answer = min( answer, i->second->min_lev_dist_rec2( i->first, word, table ) );
	}
	return answer;
}

dist_t RadixNode::min_lev_dist_rec3( char edge_char, const string & word, vector<vector<dist_t> > & dem_rows, int level )
{
	vector<dist_t> & prev_row = dem_rows[level-1];
	vector<dist_t> & curr_row = dem_rows[level];
	curr_row[0] = prev_row[0] + 1;
	for( size_t i = 1; i <= word.size(); ++i )
	{
		if( word[i-1] != edge_char )
		{
			dist_t rep_cost = prev_row[i-1] + 1;
			dist_t ins_cost = curr_row[i-1] + 1;
			dist_t del_cost = prev_row[i] + 1;
			curr_row[i] = min( ins_cost, min( del_cost, rep_cost ) );
		}
		else
			curr_row[i] = prev_row[i-1];
		
	}
	dist_t ret = _inf;
	if( this->word != NULL ) // this is case of a node representing .
	{
		ret = curr_row[word.size()];
		if( RadixNode::t > ret )
		{
			RadixNode::t = ret;
		}
		if( children.size() == 0 ) return ret;
	}
	dist_t mc = _inf;
	for( size_t i = 0; i < curr_row.size(); ++i )
	{
		mc = min(mc, curr_row[i] );
	}
	if( mc >= RadixNode::t ) return ret;
	for( map<char, RadixNode*>::iterator i = children.begin(); i != children.end(); ++i )
	{
		ret = min( ret, i->second->min_lev_dist_rec3( i->first, word, dem_rows, level + 1) );
	}
	return ret;
}

dist_t RadixNode::min_lev_dist3( const string & word )
{
	RadixNode::t = _inf;
	dist_t dat_deepnezz = depth();
	vector<vector<dist_t> > table( dat_deepnezz + 1, vector<dist_t>( word.size() + 1, 0 ) );
	for( size_t i = 0; i <= word.size(); ++i )
	{
		table[0][i] = i;
	}
	
	dist_t answer = _inf;
	for( map<char,RadixNode*>::iterator i = children.begin(); i != children.end(); ++i )
	{
		answer = min( answer, i->second->min_lev_dist_rec3( i->first, word, table ) );
	}
	return answer;
}

