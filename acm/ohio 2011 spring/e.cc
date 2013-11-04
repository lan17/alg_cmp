#include <iostream>
#include <map>
#include <vector>
#include <bitset>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ext/hash_map>

namespace std { using namespace __gnu_cxx; }


typedef unsigned long long ull;

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

#define eat_shit() while(cin.peek() =='\n' || cin.peek() =='\r') cin.ignore()


int rotate( int n, bool clock_wise, int curr, long long rot )
{
	if( !clock_wise) return ( curr + rot ) % n;
	
	long long t1 = rot / n;
	t1 = t1 < 0 ? -t1 : t1;
	rot += n * t1;

	rot = rot < 0 ? -rot : rot;

	//cout<<"rot = "<<rot<<endl;

	int t = (curr - rot) % n;	
	//cout<<"T = "<<t<<endl;
//	while( abs(t) > n )
	//{
	//	t += n;
	//}

	if( t < 0 ) 
	{
		t = n - abs(t );
	}
	return t;
}

int main( int argc, char ** argv )
{
	//cout<<rotate(60, true, 0, -12412312)<<endl;

	string t;
	int case_i = 1;
	while( true )
	{
		if( cin.peek() == '0' ) break;
		int n,x,y,z;
		cin>>n>>x>>y>>z;
		eat_shit();
	
		vector<pair<bool,long long> > rotations;

		
			string accum;
			while(true)
			{
				eat_shit();
				getline(cin,t);
				eat_shit();		
				accum += string(" ") + t;
				if( t.find("?") != string::npos ) break;
			}
			vector<string> rots = expand( accum, " " );
			for( int i = 0; i < rots.size()-2; i += 2 )
			{
				rotations.push_back( make_pair( rots[i] == "C" ? true : false, atoi(rots[i+1].c_str() ) ) );
			}

			vector<pair<bool,long long> > rotz;
		for( size_t i = 0; i < rotations.size(); ++i )
		{
			pair<bool,int> t = rotations[i];
			size_t j;
			for(j = i + 1; j < rotations.size(); ++j )
			{
				if( rotations[j].first != t.first ) break;
				t.second += rotations[j].second;
			}
			i = j-1;
			rotz.push_back(t);
		}
		rotations=rotz;
		
		/*
		for( int i = 0; i < rotations.size(); ++i )
		{
			cout<<rotations[i].first<<" "<<rotations[i].second<<endl;
		}
		cout<<"==========="<<endl;
		*/

		bool s1,s2,s3;
		s1 = s2 = s3 = false;

		int state = 0;

		int curr = 0;

//int rotate( int n, bool clock_wise, int curr, int rot )

		int cc = 0;
		int c = 0;
		bool open = false;
		for( size_t i = 0; i < rotations.size(); ++i )
		{
			bool cwise = rotations[i].first;
			int rot = rotations[i].second;
			if( cwise )
			{
				c += rot;
				cc = 0;
			}						
			else
			{
				cc += rot;
				c = 0;
			}

			int next = rotate( n, cwise, curr, rot );

			//cout<<"next = "<<next<<endl;

			switch(state)
			{
				case 0:
					if( c >= n && next ==x )
					{
						state = 1;
					}
					break;
				case 1:
					if( cc > 0 && next == y )
					{
						state = 2;
					}
					else state = 0;
					break;
				case 2:
					if( c > 0 && c < n && next == z )
					{
						state = 3;
					}
					else state = 0;
					break;
			}
			//cout<<" state = "<<state<<endl;
			curr = next;
			
		}
		if( state == 3 ) open = true;
		cout<<"Case "<<(case_i++)<<": "<<(open?"Open":"Closed")<<endl;

	}
}
