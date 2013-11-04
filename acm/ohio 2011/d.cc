#include <iostream>


typedef unsigned long long ull;

#include <vector>
#include <string>
#include <map>
 
using namespace std;

bool cmp( const pair<char,int> & a, const pair<char,int> & b )
{
	if( a.first < b.first ) return true;
	if( a.first > b.first ) return false;
	return a.second < b.second;
}

void trim(string & t )
{
	for( int i = 0; i < t.size(); ++i )
	{
		if( t[i]==' ' || t[i] =='\r' || t[i] =='\n') t.erase(i,1);
	}
}

string solve( string keyword, string cipher )
{
	trim( keyword );
	trim( cipher );
	//cout<<"KEYWORD='"<<keyword<<"'"<<endl;
	//cout<<"CIPHER='"<<cipher<<"'"<<endl;
	vector<string> cols(keyword.size(),"");
	vector<int> col_order;
	vector<pair<char,int> > keyword_p;
	for( int i = 0; i < keyword.size(); ++i )
	{
		keyword_p.push_back( make_pair( keyword[i], i ) );
	}	
	sort( keyword_p.begin(), keyword_p.end() );
	//for( int i = 0; i < keyword_p.size(); ++i )
	//	cout<<keyword_p[i].first<<":"<<keyword_p[i].second<< " ";
	//cout<<endl;

	int i = 0;
	int col_len = cipher.size()/keyword.size();
	int cnt = 0;
	while( i < cipher.size() )
	{
		string t = cipher.substr(i,col_len);
		cols[keyword_p[cnt++].second]=t;
		i += col_len;
		//cout<<cols[cols.size()-1]<<endl;
	}
	//cout<<"COL SIZE = " <<cols.size()<<endl;

	string ret = "";
	for( int i = 0; i < col_len; ++i )
	{
		for( int j = 0; j < cols.size(); ++j )
		{
			ret += cols[j][i];
		}
	}
	
	return ret;
}

int main( int argc, char ** argv )
{
	while( !cin.eof() )
	{
		string t;
		getline( cin, t );
		if( t == "THEEND" ) break;
		string m;
		getline( cin, m );
		cout<<solve(t,m)<<endl;
	}
}
