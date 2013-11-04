#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef vector<string> vecs;
typedef unsigned long long ull;

#define in(x,y) ((x).find((y)) != (x).end())
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

const int inf = 1<<29;

const int N_MAX = 20; // assume we never get input larger than 20.

vector<double> id2prob;
map<string,int> place2id;
vector<vector<int> > graph;

double dist[N_MAX][1<<N_MAX];
double prob_sum[1<<N_MAX];

int m;

double solve()
{
	for( int i = 0; i < m; ++i )
	{
		for( int j = 0; j <= 1<<m; ++j )
		{
			dist[i][j] = double(inf);
		}
	}	

	for( int i = 0; i < 1<<m; ++i )
	{
		prob_sum[i] = 0;
		for( int j = 0; j < m; ++j )
		{
			if( ( i & (1<<j) ) == 0 )
				prob_sum[i] += id2prob[j];
		}
	}

	dist[0][1] = 0.0;

	int counter = 0;

	for( int i = 0; i < 1<<m; ++i )
	{
		for( int j = 0; j < m; ++j )
		{
			if( dist[j][i] < double(inf) )
			{
				double curr = dist[j][i];
				for( int k = 0; k < m; ++k )
				{
					counter++;
					if( ( i & (1<<k) ) == 0 ) // k is
					{
						int v_mask = i | (1<<k);
						dist[k][v_mask] = min(dist[k][v_mask], curr + prob_sum[i] * graph[j][k] );
					}
				}
			}
		}
	}
	cout<<counter<<endl;

	double answer = double(inf);
	for( int i = 0; i < m; ++i )
	{
		answer = min( answer, dist[i][ (1<<m) -1] );
	}
	return answer;

}

int main( int argc, char ** argv )
{
	ifstream ifs( argv[1] );
	string t;


	getline( ifs, t );
	m = atoi( t.c_str() );
	graph.resize(m,vector<int>(m,inf));
	id2prob.resize(m);

	for( int i = 0; i < m; ++i )
	{
		graph[i][i] = 0;
	}

	int counter = 0;
	for( int i = 0; i < m; ++i )
	{
		getline(ifs,t);
		vecs line = expand( t, " \t" );
		int id = counter++;
		double prob = atof( line[1].c_str() );
		place2id[line[0]] = id;
		id2prob[id] = prob;
	}
	int c;
	getline(ifs,t);
	c = atoi( t.c_str() );
	for( int i = 0; i < c; ++i )
	{
		getline( ifs, t);
		vecs line = expand( t, " \t" );
		if( line.size() == 0 ) break;
		int a = place2id[line[0]];
		int b = place2id[line[1]];
		int d = atoi( line[2].c_str() );
		
		graph[a][b] = graph[b][a] = d;
	}

	// Perform Floyd-Warshall step to compute connected graph with shortest distances from each pair of 
	// vertices.
	for( int k = 0; k < m; ++k )
	{
		for( int i = 0; i < m; ++i )
		{
			for( int j = 0; j < m; ++j )
			{
				graph[i][j] = min( graph[i][j], graph[i][k] + graph[k][j] );
			}
		}
	}

	double answer = 0;
	// check if there is no solution in case one of the graph is not connected.
	for( int i = 0; i < m; ++i )
	{
		for( int j = 0; j < m; ++j )
		{
			if( graph[i][j] == inf )
			{
				answer = inf;
			}
		}
	}
	
	if( answer == 0.0 ) // answer is guaranteed.  find it.
	{
		answer = solve();
		//cout<<answer<<endl;
		printf("%.2lf\n", answer);
	}
	else
	{
		cout<<"-1.00"<<endl;
	}
	
}
