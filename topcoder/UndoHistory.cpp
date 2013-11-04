#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>

using namespace std;

int print_dbg = 1;

#define d_print(x) { if(print_dbg){  cerr << __LINE__ << " " << #x << " = " << x << endl; cerr.flush(); } }

typedef vector<string> vecs;
typedef vector<int> veci;
typedef unsigned long long ull;
typedef long long ll;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

struct Node
{
	Node * parent;
	vector<Node*> children;
	char num;
	bool isWord;

	Node()
	{
		children.resize(27,NULL);
		num = 0;
		isWord = false;
	}

	Node * get( char a )
	{
		return children[a-'a'];
	}

	Node * get(const string word, int i ) const
	{
		if( i == word.size()-1)return children[word[i]-'a'];
		return children[word[i]-'a']->get(word,i+1);
	}

	Node * add( char a )
	{
		children[a-'a'] = new Node();
		children[a-'a']->parent = this;
		++num;
		return children[a-'a'];

	}

	Node * getOrCreate( char a )
	{
		int i = a-'a';
		Node * ret = children[i];
		if( NULL == ret )
		{
			ret = add(a);
		}
		return ret;
	}

	//bool hasParent

};

class UndoHistory
{
	int solve( const vector<string> & lines )
	{
		int ret = 0;
		Node * root = new Node();
		Node * walker = root;
		for( int l = 0; l < lines.size(); ++l )
		{
			string line = lines[l];
			Node * pWalker = walker;

			bool hadToTeleport = true;
			int tW = 0;
			if( l == 0 || lines[l] != lines[l-1])
			{
				walker = root;
				for( int i = 0 ; i < line.size(); ++i )
				{
					char c = (line)[i];
					if(walker->get(c)==NULL)tW++;
					walker = walker->getOrCreate(c);
					if( walker == pWalker  ) hadToTeleport = false;
				}
			}
			int cost = 1 + tW;
			if( hadToTeleport &&( pWalker != root) && lines[l] != lines[l-1]) cost += 2;
			ret += cost;

			walker->isWord = true;
			d_print("===");
			d_print(line);
			d_print(cost);
			d_print(hadToTeleport);
			d_print(tW);

		}
		return ret;
	}

	public:
	int minPresses(vector <string> lines)
	{
		return solve(lines);
		//return tree->countNodes() - 1 + tree->countWords() * 2;
	}
};
