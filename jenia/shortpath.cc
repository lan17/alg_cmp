#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <cassert>
#include "GraphAlgorithms.h"

#include "routines.h"


using namespace std;

main() {

  cout << "Program syntax:  shortpath < test_case.inp " << endl;

  GraphAlgorithms my_ga;
  vector<list<pair<int,int> > > adj_list;

  vector<list<int> > paths;
  read_graph(cin,adj_list);

  paths = my_ga.shortest_path(adj_list,0);  // You need to complete this


  //cout << "need to complete the shortest path routine " << endl;



   list<int>::iterator p;
   for (int i=0;i<adj_list.size();i++) {
     bool first = true;
     int last = 0;
     int sum = 0;
     for (p=paths[i].begin();p!=paths[i].end();++p) {
      if (first) {
	first = false;
	last = *p;
      } else {
	if (in_list(adj_list[last],*p)) {
	  sum+=val_in_list(adj_list[last],*p);
	} else {
	  cout << "Error! " << " edge " << last <<"->" << *p << "not in graph" << endl;
	}
	last = *p;
      }
    }
    cout << "Shortest path to vertex " << i << " has length =" << sum <<endl;
  }
 




}
