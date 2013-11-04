#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <bitset>
#include <math.h>
#include <sstream>

using namespace std;

#define H 1
#define P 0

int d_x[4] = { -1, 1, 0,  0 };
int d_y[4] = {  0, 0, -1, 1 };

string d_s[4] = {"left", "right", "up", "down" };


#define str_len 15

#define bitset_row (str_len*2+3)
#define bitset_size (bitset_row*bitset_row)

#define board_type vector<char>


inline bool getBit( const board_type & board, char x, char y )
{
	return board[ y*bitset_row + x ];
}

inline void setBit( board_type & board, char x, char y )
{
	board[ y*bitset_row + x ] = 1;
}

inline void clearBit( board_type & board, char x, char y )
{
	board[ y*bitset_row + x ] = 0;
}

int dfs( board_type & board, board_type & visited, unsigned short str, char i, char x, char y, int sum = 0 )
{
	if( x < 0 || y < 0 || x >= bitset_row || y >= bitset_row ) return 0;
	if( getBit( visited, x, y ) ) return 0;

	int ret = 0;

	int nsum = sum;

	setBit( visited, x, y );
	if( str & ( 1 << i ) )
	{
		setBit( board, x, y );
		for( int k = 0; k < 4; ++k )
		{
			if( getBit( board, x + d_x[k], y +d_y[k] ) ) ++nsum;
		}
	}

	if( i == str_len - 1 )
	{
//		ret = connects( board );
		ret = nsum;
	}
	else
	{
		for( int d = 0; d < 4; ++d )
		{
			if( i == 0 && d != 1 ) continue;
			if( i == 1 && ( d!= 1 && d != 2 ) ) continue;
//			if( d == 0 && dp == 1  ) continue;
			ret = max( ret, dfs( board, visited, str, i + 1, x + d_x[d], y + d_y[d], nsum ) );
		}
	}

	clearBit( board, x, y );
	clearBit( visited, x, y );

	return ret;
	
}

unsigned short reflect( unsigned short str )
{
	int i,j;
	unsigned short ret = 0;
	for( i = 0, j = str_len - 1; i < str_len; ++i, --j )
	{
		bool t = ( str & ( 1 << i ) ) != 0;
		if( t ) ret |= 1 << j;
	}
	return ret;
}


//unsigned long long dfs( bitset<bitset_size> & board, bitset<bitset_size> & visited, unsigned short str, char i, char x, char y )

int main( int argc, char ** argv )
{
	unsigned long long num = 0;
	//find_good_paths();

	board_type board(bitset_size, 0);
	board_type visited(bitset_size,0);

//	visited.reset();
//	board.reset();

	int memz[1<<(str_len+1)];
	memset( memz, -1, sizeof(int)*(1<<(str_len+1)));

	for( unsigned short str = 0; str < (1 << str_len); ++str )
	{
		int t = 0;
		int t1 = reflect(str);
		int t3 = memz[t1];
		if( t3 > 0 ) t = t3;
		else 
			t = dfs( board, visited, str, 0, bitset_row/2, bitset_row/2 );
		memz[t1] = t;
		memz[str] = t;
		num += t;
		//cout<<board<<endl;
		//cout<<str<<endl;
	}
	cout<<num<<endl;
}
