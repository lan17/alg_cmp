#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <cstdio>
#include <valarray>      
#include <ext/hash_set> 
#include <ext/hash_map>
#include "float.h"

#define FMAX DBL_MAX
#define FMIN DBL_MIN

#define ld long double
#define ll long long
#define ull unsigned long long

#define vecs vector< string > 
#define veci vector< int >
#define vecsi vector<string>::iterator
#define vecii vector<int>::iterator
#define vec vector

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define pnt(x) cout<<#x<<" = "<<(x)<<endl;

using namespace std;

class BoxFilling 
{
	public:
	
	int rX, rY, rZ;

	bool is3D( int x, int y, int z )
	{
		if( x > 1 && y > 1 && z > 1 ) return true;
		return false;
	}

	bool is2D( int x, int y, int z )
	{
		if( x == 1 && y > 1 && z > 1 ) return true;
		if( x > 1 && y == 1 && z > 1 ) return true;
		if( x > 1 && y > 1 && z == 1 ) return true;
		return false;
	}
	
	bool is1D( int x, int y, int z )
	{
		if( x==1 && y == 1 && z > 1 ) return true;
		if( x > 1 && y == 1 && z == 1 ) return true;
		if( x ==1 && y > 1 && z == 1 ) return true;
		return false;


	}

	int count2D( int x, int y, int z, int x1, int y1, int z1, long & ans, int c = 0 )
	{
				if( c == 0 )
		{
			rX = x;
			rY = y;
			rZ = z;
		}
		//cout<<x<<" "<<y<<" "<<z<<endl;
		//if( x==1 && y==1 && z==1 ) return c+1;
		if( is1D(x,y,z) )
		{
			if( ans == 0 ) 
			{
				if( y > 1 )
				{
					ans = c + (y1-(rY-y));
				}
				if( x > 1 )
				{
					ans = c + (x1-(rX-x));
				}
				if( z > 1 )
				{
					ans = c + (z1-(rZ-z));
				}
			}
			if( z > 1 ) return c+z;
			if( y > 1 ) return c+y;
			if( x > 1 ) return c+x;
		}
		if( x > 1 )
		{
			if( y1 == abs( y-rY ) + 1 )
				if( z1 == abs(z-rZ) + 1 ) 
					{ if( ans == 0 ) ans = c + x1-(rX-x); }
			c += x;
			if( y > 1 ) y -= 1;
			if( z > 1 ) z -= 1;
		}
		if( is2D( x,y,z ) && y > 1 )
		{
			if( x1 == abs(x-rX)+1)
				if( z1 == abs(z-rZ) + 1 )
					{ if( ans == 0 ) ans = c + (y1-(rY-y)); }
			c += y;
			if( x != 1 ) x -= 1;
			if( z != 1 ) z -= 1;
		}
		if( is2D( x,y,z ) && z > 1 ) 
		{
			if( x1 == abs(x-rX)+1)
				if( y1 == abs(y-rY) + 1 )
					{ if( ans == 0 ) ans = c + (z1-(rZ-z)); }
			c += z;
			if( x != 1 ) x -= 1;
			if( y != 1 ) y -= 1;
		}
		return count2D( x,y,z,x1,y1,z1,ans,c);

	}

	int count3D( int x, int y, int z, int x1, int y1, int z1, long & ans, int c = 0 )
	{

		if( !is3D( x, y, z ) )
		{
			return count2D( x,y,z,x1,y1,z1,ans, c);
		}
		c+=count2D( x,y,1,x1,y1,z1,ans,c );
		z -= 1;
		if( is3D( x,y,z ) )
		{
			c+=count2D( x,1,z,x1,y1,z1,ans,c);
			y -= 1;
		}
		if( is3D( x,y,z) )
		{
			c+=count2D(1,y,z,x1,y1,z1,ans,c);
			x -= 1;
		}
		return count3D(x,y,z,x1,y1,z1,ans,c);

	}
	
	long long getNumber(int sizeX, int sizeY, int sizeZ, int cubeX, int cubeY, int cubeZ)
	{
		long ans = 0;
		//cout<<count2D( 4,5,1,3,4,1,ans)<<endl;
		//cout<<ans<<endl;
		count3D( sizeX,sizeY,sizeZ,cubeX,cubeY,cubeZ,ans);
		return ans;

		
	}
};

/* Lev A Neiman's coding here */


// Powered by FileEdit
