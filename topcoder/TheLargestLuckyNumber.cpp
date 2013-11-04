#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>




#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )


using namespace std;

bool isLucky( int n )
{
	stringstream s;
	s<<n;
	string st = s.str();
	FOR( i, st.size() )
	{
		if( st[i] != 55 && st[i] != 52 ) return false;
	}
	return true;
}

class TheLargestLuckyNumber 
{
	public:
	int find(int n)
	 {
		for( int i = n; i >= 4; i-- )
		 {
			if( isLucky(i) ) return i;
		 }
	}
};

/* Lev A Neiman's coding here */


// Powered by FileEdit
