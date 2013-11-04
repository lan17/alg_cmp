#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


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

void find_liking(	map<string,vector<string> > & liking, string curr, set<string> & group, set<string> & taken, int & group_liking, int max )
{
	if( group.size() >= max ) return;

	vector<string> & friends = liking[curr];
	for( int i = 0; i < friends.size(); ++i )
	{
		if( group.find( curr) != group.end() )
			if( group.find( friends[i] ) != group.end() )
				continue;
		if( ( group.find( friends[i] ) != group.end() ) || taken.find( friends[i] ) == taken.end() )
		{
			taken.insert( curr );
			taken.insert( friends[i] );
			group.insert( curr );
			group.insert( friends[i] );
			cout<<curr<< " " << friends[i]<<endl;
			++group_liking;
			vector<string> & t = liking[friends[i]];
			for( int k = 0; k < t.size(); ++k )
			{
				if( t[k] == curr ) ++group_liking;
			}
			find_liking( liking, friends[i], group, taken, group_liking, max );
		}
	}
}

int main( int argc, char ** argv )
{
	map<string,vector< string > > liking;
	string t;
	getline(cin,t);
	int n = atoi(t.c_str() );
	
	for( int i = 0; i < n; ++i )
	{
		getline( cin, t );
		vector<string> l = expand( t, " " );
		liking[l[0]].push_back( l[2] );
	}
	
	int a,b,c;
	cin>>a>>b>>c;
	vector<int> monst(3);
	monst[0] = a;
	monst[1] = b;
	monst[2] = c;
	
	vector<set<string> > groups(3);
	vector<int> group_liking(3,0);
	set<string> taken;
	int left = 7;
	
	for( int i = 0; i <3; ++i )
	{
			if( groups[i].size() >= 4 ) continue;
			for( map<string,vector< string > >::iterator im = liking.begin(); im != liking.end(); ++im )
			{
				if( taken.find( im->first ) == taken.end() )
				{
					cout<<i<<endl;
					cout<<im->first<<endl;
					find_liking( liking, im->first, groups[i], taken, group_liking[i],4 );
				}
				left -= groups[i].size();
			}
	}

	int liking_total = 0;
	for( int i = 0; i < group_liking.size(); ++i )
	{
		cout<<"Size of group "<<i<< " is "<< groups[i].size()<<endl;
		liking_total += group_liking[i];
	}

	sort(monst.begin(),monst.end() );
	int bg,sg,bgi,sgi;
	bg = 0;
	sg = 1<<29;
	bgi = 0;
	sgi = 0;
	for( int i = 0; i < groups.size(); ++i )
	{
		int s = groups[i].size();
		if( s == 0 ) s+= 1;
		if( bg < s )
		{
			bg = s;
			bgi = i;
		}
		if( sg > s )
		{
			sg = s;
			sgi = i;
		}
	}

	int diff = floor(double(monst[2]) / double(sg)) - floor(double(monst[0])/double(bg));

	cout<<diff<<" "<<liking_total<<endl;

	

}
