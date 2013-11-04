#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp( const pair<int, char> & a, const pair<int, char> & b )
{
	return a.first < b.first;
}
class Filtering {
	public:
	vector <int> designFilter(vector <int> sizes, string outcome) 
	{
		vector<pair<int,char> > el;
		for( int i = 0; i < sizes.size(); ++i )
		{
			el.push_back(make_pair( sizes[i], outcome[i] ) );
		}
		sort( el.begin(), el.end(), cmp );
		for( int i = 0; i < el.size(); ++i )
		{
			cout<<el[i].first<<":"<<el[i].second<<"  ";
		}
		cout<<endl;
		vector<int> ret;
		int A, B;
		bool saw_a=false;
		bool saw_a_r=false;
		for( int i = 0; i < el.size(); ++i )
		{
			if( el[i].second == 'A' && !saw_a)
			{
				A = el[i].first;
				saw_a = true;
			}
			if( el[i].second == 'R' && saw_a && !saw_a_r)
			{
				B = el[i-1].first;
				saw_a_r = true;				
			}
			if( el[i].second == 'A' && saw_a_r )
			{
				return ret;
			}
		}
		if( !saw_a_r ) B = el[el.size()-1].first;
		ret.push_back(A);
		ret.push_back(B);
		return ret;	
	}
};


// Powered by FileEdit
