#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <iostream>

#define in(x,y) ((x).find((y)) != (x).end())
#define d_print(x) cout<<#x<<"="<<x<<endl

using namespace std;

const int INF = 1 << 29;
vector<int> perf_sq;
vector <int> holes;
set<int> holez;

map<int,int> mem;

bool inbetween( int i, int j )
{
	for( int k = 0; k < holes.size(); ++k )
	{
		if( holes[k] >= i && holes[k] <= j ) return true;
	}
	return false;
}

int solve( int gp, int cp, int so_far )
{
	if( cp == gp ) return so_far;
	if( so_far > 5 ) return INF;

	cout<<"SHIT"<<endl;

	if( in(mem,cp))
	{
		return mem[cp];
	}

	int answer = 100000;
	for( int i = 0; i < perf_sq.size(); ++i )
	{
		int t,t1;
		t = cp + perf_sq[i];
		t1 = cp - perf_sq[i];
		if( ! inbetween( cp, t) )
		{
			answer = min(answer, solve( gp, t, so_far + 1) );
		}
		if(! inbetween(t1,cp) )
		{
			answer = min(answer, solve(gp,t1, so_far + 1));
		}

	}

	mem[cp] = answer;

	return answer;

}

class CubeRoll 
{
	public:
	int getMinimumSteps(int initPos, int goalPos, vector <int> holePos) 
	{

		for( int i = 0; i < holePos.size(); ++i )
		{
			int p = holePos[i];
			if( initPos > goalPos )
			{
				if( p > goalPos && p < initPos ) return -1;
			}
			else if( p > initPos && p < goalPos ) return -1;
			holez.insert( p );
		}
		sort( holePos.begin(), holePos.end());
		int border = -1;
		for( int i = 0; i < int(holePos.size())-1; ++i )
		{
			if( holePos[i] < initPos && holePos[i+1] > initPos )
			{
				border = i;
			}
		}


		for( int i = 1; i*i <= 100000; ++i )
		{
			perf_sq.push_back(i*i);
		}
		d_print(perf_sq.size());

		for( int i = 0; i < holePos.size(); ++i )
		{
			if( i == border || i == border + 1 )
			{
				holes.push_back(holePos[i]);
				d_print(holePos[i]);
			}
		}
		//holes = holePos;

		cout<<"SHIT"<<endl;
		return solve( goalPos, initPos, 0 );
	}
};
