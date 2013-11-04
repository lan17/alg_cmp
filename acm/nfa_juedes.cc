#include <set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool check_conv(vector<string> &valid_w, string &conv) {
  set<pair<int,int> > valid_states;

  valid_states.insert(make_pair(-1,0));

  for (int i=0;i<conv.size();i++) {
    // Process conv[i]
    set<pair<int,int> >:: iterator p;
    set<pair<int,int> > temp;
    for (p=valid_states.begin();p!=valid_states.end();++p) {
      if (p->first == -1) {
	// Check to see if this character matches any of the first characters
	for (int j=0;j<valid_w.size();j++) {
	  if (conv[i] == valid_w[j][0]) {
	    temp.insert(make_pair(j,1));
	  }
	}
      } else {
	if (conv[i] == valid_w[p->first][p->second]) {
	  // It matches! 
	  if (p->second == valid_w[p->first].length()-1) { // last char
	    temp.insert(make_pair(-1,0));
	  } else {
	    temp.insert(make_pair(p->first,p->second+1));
	  }
	}
      }
    }
    valid_states = temp;
  }
  set<pair<int,int> >::iterator p;
  
  p = valid_states.find(make_pair(-1,0));
  if (p!=valid_states.end()) {
    return true;
  } else return false;
}


int main( int argc, char ** argv) {
  int n;
  vector<string> words;
  words.push_back("one");
  words.push_back("out");
  words.push_back("puton");
  words.push_back("in");
  words.push_back("input");
  words.push_back("output");

  cin >> n;
  string conv;
  for (int i=0; i < n ; i++) {
    cin >> conv;
    if (check_conv(words,conv)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

