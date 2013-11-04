//****************************************************************************
// This is a start on HW #5.
//***************************************************
#include <iostream>
#include "GraphAlgorithms.h"

#include "routines.h"

class w_edge {
public:
  int u;
  int v;
  int weight;
  friend bool operator < (const w_edge &e1, const w_edge &e2);
};
bool operator <(const w_edge &e1, const w_edge &e2) {
  return e1.weight > e2.weight;
}


#include <queue>
#include <set>

// Infinity == 2^29
#define INF 1<<29

// Utility macro for easier time iterating through STL containers.
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

vector<int> GraphAlgorithms::mst(
				 const vector<list<pair<int,int> > > &adj_list,int v) {
  vector<int> temp( adj_list.size(), -1 );
  set<int> vis; // stores nodes we already put in spanning tree.
  vis.insert( v );
  while( vis.size() != temp.size() )
  {
	  // find node that has min edge to one of the nodes in vis
	  int min_c = INF; // this stores the cost of the minimum edge that leads from a node in vis to a node not in vis
	  int min_i = -1; // this will store index of node not in vis that has the min edge between it and one of the elements in vis.
	  int min_j = -1; // this will store element in vis that connects to min_i and will become min_i's parent.

	  // go through each element in vis
	  FOREACH( vi, vis )
	  {
		  FOREACH( ui, adj_list[*vi] )
		 {
			  if( vis.count(ui->first) == 0 )
			  {
				  if( min_c > ui->second )
				  {
					  min_i = ui->first;
					  min_j = *vi;
					  min_c = ui->second;
				  }
			  }
		 }
	  }
	  temp[min_i] = min_j;
	  vis.insert( min_i );
  }


  return temp;
}



vector<list<int> > GraphAlgorithms::shortest_path(
						  const vector<list<pair<int,int> > > &adj_list,int v) {
	// simple Bellman ford implementation.

  int n = adj_list.size();
  // store distance from v to i in dist
  vector<int> dist( n, INF );
  // store predecessor in shortest path from v to i
  vector<int> pred( n, -1 );
  dist[v] = 0;

  // relax
  for( int i = 0; i < n; ++i )
  {
	  for( int u = 0; u < n; ++u )
	  {
		  FOREACH( vv, adj_list[u] )
		  {
			  int dd = vv->second;
			  int v = vv->first;
			  if( dist[u] + dd < dist[v] )
			  {
				  dist[v] = dist[u] + dd;
				  pred[v] = u;
			  }

		  }
	  }
  }

  // check for negative cycle.
  for( int i = 0; i < adj_list.size(); ++i )
  {
	  FOREACH ( jj, adj_list[i] )
		{
		  int u = i;
		  int v = jj->first;
		  // if there is a negative cycle throw exception.
		  if( dist[u] + jj->second < dist[v] )
		  {
			  throw 1337;
		  }
		}
  }

  // output in desired format.
  vector<list<int> > temp(n);

  for( int i = 0; i < n; ++i )
  {
	  //if( i == v ) continue;
	  int c = i;
	  while( c != v )
	  {
		  temp[i].push_back( c );
		  c = pred[c];
	  }
	  temp[i].push_back(c);
  }
  return temp;
}

bool GraphAlgorithms::new_cycle(const vector<list<pair<int,int> > > &adj_list)
{
	// simply run shortest_path and check if exception was raised.  If it was then this graph must have had a negative cycle.
	try
	{
		shortest_path( adj_list, 0 );
	}
	catch( int shit )
	{
		return true;
	}

  return false;
}

/*******************************************************************/
/* Some useful routines */

int choose(vector<int> & dist, vector<bool> &known, vector<bool> & S) {
  int min = (1<< 30);
  int min_index = 0;
  for (int i=0;i<dist.size();i++) {
    if (known[i]&&!S[i]) {
      if (min > dist[i]) {
	min = dist[i];
	min_index = i;
      }
    }
  }
  return min_index;
}

