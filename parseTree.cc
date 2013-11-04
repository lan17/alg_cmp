#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct node
{
	string name;
	vector<node*> children;
	

	string print()
	{
		string ret = " " + name + " ";
		if( children.size() > 0 ) ret += "(";
		for( int i = 0; i < children.size(); ++i )
		{
			ret += children[i]->print();
		}
		if( children.size() > 0 ) ret += ")";
		return ret;
	}
};

node * parse( string a )
{
	stack<node*> s;
	node * top = new node();
	for( int i = 0; i < a.size(); ++i )
	{
		if( a[i] == '(' )
		{
			s.push( top );
			top = new node();			
		}
		if( a[i] == ')' )
		{
			top = s.top();
			s.pop();
		}
		if( isalpha(a[i] ) )
		{
			string tt;
			while( isalpha(a[i]) )
			{
				tt.push_back( a[i++] );
			}
			i--;
			top = new node();
			top->name=tt;
			s.top()->children.push_back(top);		
		}
	}
	return top;
}

int main( int argc, char ** argv )
{
	string t(argv[1]);
	string out = parse(t)->print();
	cout<<out<<endl;
}
