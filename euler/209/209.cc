#include <iostream>
#include <map>
#include <vector>
#include <bitset>
#include <set>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef unsigned char uchar;

#define NV 6

const uchar NV_MASK = 255 >> (8-NV);

void rotate_var_char( uchar & var )
{
	bool last = var>>(NV-1) ^ ( (var >> (NV-2) & 1) & (var >> (NV-3) & 1 ));
	//cout<<"LAST = " <<last<<endl;
	var = var<<1;
	var += last ? 1 : 0;
	var &= NV_MASK;
}

ull count_cycle_char( const uchar & start )
{
	uchar walker = start;
	rotate_var_char( walker );
	ull answer = 1;
	while( walker != start )
	{
	//	cout<<int(start)<<" "<<int(walker)<<endl;
		rotate_var_char(walker);
		++answer;
	}
	return answer;
}

map<pair<uchar,pair<bool,bool> >,ull > mem;

ull cnt = 0;

ull count_ways_char( uchar start, bool start_true, uchar curr, bool curr_true, bool * nodes_done )
{	
	pair<uchar,pair<bool,bool> > cc = make_pair(curr,make_pair(start_true, curr_true ) );
	if( mem.find( cc ) != mem.end() ) return mem[cc];
	++cnt;
	
	uchar next = curr;
	rotate_var_char( next );
	nodes_done[start] = nodes_done[curr] = nodes_done[next] = true;
	if( next == start)
	{
		if( start_true && curr_true ) return 0;
		return 1;
	}
	ull answer = 0;
	if( !curr_true )
	{
		answer += count_ways_char( start, start_true, next, true, nodes_done ) + count_ways_char( start, start_true, next, false, nodes_done );
	}
	else
	{
		answer += count_ways_char( start, start_true, next, false, nodes_done );
	}
	
	mem[cc] = answer;
	
	return answer;
}

ull count_ways_char( uchar start, bool * nodes_done )
{
	return count_ways_char( start, false, start, false, nodes_done ) + count_ways_char( start, true, start, true, nodes_done );
}

int main( int argc, char ** argv )
{
	ull answer = 1;	
		
	bool nodes_done[1<<NV];	
	for( int i = 0; i < 1<<NV; ++i )
	{
		nodes_done[i] = false;
	}	
	for( int i = 0; i < 1<<NV; ++i )
	{
		if( nodes_done[i] ) continue;
		cout<<"doing "<<i<<" which has cycle length "<<count_cycle_char( uchar(i) )<<endl;
		answer *= count_ways_char(uchar(i), nodes_done );
	}	
	cout<<"Number of times inside recursive function = "<<cnt<<endl;
	cout<<answer<<endl;
}
