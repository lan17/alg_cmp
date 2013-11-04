#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

typedef vector<string> vecs;
typedef unsigned long long ull;

#define in(x,y) ((x).find((y)) != (x).end())
#define d_print(x) cout<<#x<<"="<<(x)<<endl

const int inf = 1<<29;

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

map<int,double> id2prob;
map<string,int> place2id;
vector<vector<int> > graph;
vector<pair<int,double > > probs;
vector<vector<pair<int,double> > > greedy;
int curr_node = -1;
double curr_distanze = 0.0;


int m;

double global_min = ull(1)<<32;

bool prob_cmp(const pair<int,double > & a, const pair<int,double > & b )
{
	return a.second > b.second;
}

bool greedy_cmp( const pair<int,double> & a, const pair<int,double> & b )
{
	double t =  curr_distanze;
	double t1 = curr_distanze;
	//double t,t1;
	//t=t1=1.0;
	return t + a.second < t1 + b.second;
}

double solve( double curr_exp, int curr_time, int curr, vector<bool> & visited, int left )
{
	curr_node = curr;
	curr_distanze = curr_time;
	double new_exp = curr_time * id2prob[curr] + curr_exp;
	//cout<<left<<" "<<new_exp<<endl;
	if( new_exp > global_min )
	{
		//visited[curr] = false;
		return new_exp;
	}
	if( left == 1 )
	{
		global_min = min( global_min, new_exp );
	//	cout<<new_exp<<endl;
		//visited[curr] = false;
		return new_exp;
	}

	visited[curr] = true;
	int next_el = -1;
	double best = ull(1)<<32;
	double answer = ull(1)<<32;
	/*
	for( int i = 0; i < m; ++i )
	{
		int index = probs[i].first;
		if( !visited[index] )
		{
			double t = solve( new_exp, curr_time + graph[curr][index], index, visited, left - 1 );
			answer = min(t,answer);
		}
	}
	*/
	int pen = 0;
	sort( greedy[curr].begin(), greedy[curr].end(), greedy_cmp );
	for( int i = 0; i < greedy[curr].size(); ++i )
	{
		int index = greedy[curr][i].first;
		if( !visited[index] )
		{
			double t= solve( new_exp, curr_time + graph[curr][index], index, visited, left - 1 );
			//visited[i] = true;
			if( t > global_min )
			{
				++pen;
			}
			if( pen == 2 ) break;
			answer = min( t, answer );
		}
	}
	//global_min = min(global_min, answer );
	visited[curr] = false;
	return answer;

}

int main( int argc, char ** argv )
{
	ifstream ifs( argv[1] );
	string t;
	double answer = 0;

	getline( ifs, t );
	m = atoi( t.c_str() );
	graph.resize(m,vector<int>(m,inf));


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
		id2prob[place2id[line[0]]] = prob;

		probs.push_back(make_pair( id, prob ));
	}
	sort( probs.begin(), probs.end(), prob_cmp );
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
	greedy.resize(m);
	for( int k = 0; k < m; ++k )
	{
		for( int i = 0; i < m; ++i )
		{
			greedy[k].push_back(make_pair(i,double( graph[k][i] )));
		}
	//	sort( greedy[k].begin(), greedy[k].end(), greedy_cmp );
	}

	for( int i = 0; i < m; ++i )
	{
		for( int j = 0; j < m; ++j )
		{
		//	cout<<graph[i][j]<<" ";
		}
		//cout<<endl;
	}

	//double solve( double curr_exp, int curr_time, int curr, vector<bool> & visited, int left )
	//cout<<global_min<<endl;
	vector<bool> visited(m,false);
	visited[0]=true;
	if( answer == 0.0 )
	{
		answer = solve(0,0,0,visited,m);
		//cout<<answer<<endl;
		printf("%.2lf\n", answer);
	}
	else
	{
		cout<<"-1.00"<<endl;
	}

}
