#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main( int argc, char ** argv )
{
	vector<int> p;
	for( int i = 0; i <=9; ++i ) p.push_back(i);
	for( int i = 0; i < 1e6-1; ++i ) next_permutation(p.begin(),p.end());
	for( int i = 0; i < p.size(); ++i ) cout<<p[i];
	cout<<endl;
}
