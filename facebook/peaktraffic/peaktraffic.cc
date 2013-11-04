#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

int print_dbg = 1;

#define d_print(x) { if(print_dbg){  cerr << __LINE__ << " " << #x << " = " << x << endl; cerr.flush(); } }
#define in(x,y) ((x).find((y)) != (x).end())
#define ALL(x) (x).begin(), (x).end()
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

typedef vector<string> vecs;
typedef vector<int> veci;
typedef set<int> seti;

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




/**
 * Find maximal cliques in given graph
 *
 * G is current graph.
 * last is index of vertex that has called this.  It is guaranteed to make 2-clique with all vertices in G>
 */
vector<seti> findCliques(  map<int,seti> & G, int last = -1 )
{
	// Return list of cliques.
	vector<seti> ret;
	// map from vertex id to set of indices into ret which correspond to all cliques that id is in.
	map<int,seti> id2clique;

	// iterate over all vertices in graph.
	FOREACH( el, G )
	{
		int v_i = el->first;
		const seti & V = el->second;

		int count = V.size();
		if( count == 1 ) // base case with 2-clique
		{
			if( last >= 0 )
			{
				seti t;
				t.insert( v_i );
				t.insert( *V.begin() );
				ret.push_back( t );
			}
		}
		else if( count > 1 )
		{
			if( last >= 0 )
			{
				// add all the 2-cliques.
				FOREACH( v, V )
				{
					seti t;
					t.insert( *v );
					t.insert( v_i );
					ret.push_back( t );
				}
			}

			// new_graph will be composed of all children of v_i
			// each child will have its children set to intersection of its current children and nodes in V.
			// All vertices of new_graph will be in V.
			map<int, seti > new_graph;
			FOREACH( j, V )
			{
				seti ns;
				FOREACH( v2, G[*j] )
					if( in( V, *v2 ))
						ns.insert( *v2 );
				new_graph[ *j ] = ns;
			}

			// get dem sub_cliques.
			vector< seti > sub_cliques = findCliques( new_graph, v_i );

			// find maximal cliques inside sub_cliques.
			vector<bool> good( sub_cliques.size(), true );
			for( int i = 0; i < sub_cliques.size(); ++i )
			{
				if( !good[ i ] )
					continue;
				for( int j = 0; j < sub_cliques.size(); ++j )
				{
					if( i == j )
						continue;
					if( !good[ j ] )
						continue;
					if( includes( ALL( sub_cliques[i] ), ALL(sub_cliques[j])) ) // if clique i includes j then j can't be maximal, so mark it down as bad.
						good[ j ] = false;
				}
			}

			for( int clique = 0; clique < sub_cliques.size(); ++clique )
			{
				if( !good[ clique ] ) // if guaranteed to not be maximal clique, skip it.
					continue;
				// add v_i to all cliques we found so far.
				sub_cliques[ clique ].insert( v_i );
				// add them to output.
				ret.push_back( sub_cliques[ clique ] );
				// if this is first call map element id to clique it is in.
				if( last == -1 )
					FOREACH( s, sub_cliques[clique] )
						id2clique[ *s ].insert( ret.size() - 1 );
			}
		}
	}

	// filter out non-maximal cliques if this is first call.
	if( last == -1 )
	{
		vector<bool> bad( ret.size(), false );
		FOREACH( v, id2clique )
		{
			int id = v->first;
			seti & cliques = v->second;
			FOREACH( t, cliques )
			{
				FOREACH( t1, cliques )
				{
					if( *t == *t1 )
						continue;
					if( includes( ALL(ret[*t]), ALL(ret[*t1])) )
					{
						bad[ *t1 ] = true;
					}
				}
			}
		}
		vector<set<int> > rret;
		for( int i = 0; i < bad.size(); ++i )
		{
			if( bad[ i ] )
				continue;
			rret.push_back( ret[ i ] );
		}

		return rret;
	}

	return ret;
}

int main( int argc, char ** argv )
{
	int counter = 0;
	map<string,int > name2enum;
	map<int,string> enum2name;
	map<int,seti > enum2connected;

	ifstream ifs( argv[1] );
	string t;
	while( ifs.good() )
	{
		getline( ifs, t );
		vecs line = expand( t, " \t" );
		if( line.size() < 3 ) break;
		string & a = line[line.size()-2];
		string & b = line[line.size()-1];
		if( !in(name2enum,a) )
		{
			name2enum[a] = counter++;
			enum2name[name2enum[a]] = a;
		}
		if( !in(name2enum,b))
		{
			name2enum[b] = counter++;
			enum2name[name2enum[b]] = b;
		}
		int a_id = name2enum[a];
		int b_id = name2enum[b];

		enum2connected[a_id].insert( b_id );
	}
	d_print(enum2connected.size());

	// make undirected graph with edges from lower id to higher id if they both had 2 way correspondence originally.
	map<int,seti > enum2connected_new;
	for( int i = 0; i < counter; ++i )
		FOREACH( j, enum2connected[i] )
			if( in(enum2connected[*j], i ))
				if( *j > i )
					enum2connected_new[i].insert(*j);

	d_print( name2enum.size() );
	d_print(enum2connected_new.size());

	// find all cliques.
	vector<seti > cliques = findCliques( enum2connected_new );

	d_print(cliques.size());

	// create output.
	vector<string> answers;
	for( int i = 0; i < cliques.size(); ++i )
	{
		vector<string> c;
		FOREACH( k, cliques[i] )
		{
			c.push_back( enum2name[ *k ] );
		}
		if( c.size() < 3 )
			continue;

		sort( c.begin(), c.end() );
		stringstream s;
		for( int j = 0; j < c.size() - 1; ++j )
		{
			s << c[ j ] << ", ";
		}
		s << c[ c.size() - 1 ];
		answers.push_back( s.str() );
	}
	sort( ALL(answers));
	for( int i = 0; i < answers.size(); ++i )
		cout<<answers[i]<<endl;
}
