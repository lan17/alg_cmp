#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main( int argc, char ** argv )
{
	set<char> vow;
	char vowarr[6] = {'a','o','y','e','u','i'};
	for( int i = 0; i < 6; ++i )
	{
		vow.insert(vowarr[i]);
		vow.insert(vowarr[i] - ('a'-'A'));		
	}
	string s;
	getline(cin,s);
	s.erase(s.find_last_not_of(" \n\r\t")+1);
	string o;
	for( int i = 0; i < s.size(); ++i )
	{
		if( vow.find(s[i]) == vow.end() )
		{
			o += ".";
			o += tolower(s[i]);
		}		
	}
	cout<<o<<endl;
}
