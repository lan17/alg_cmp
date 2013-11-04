#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <bitset>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ull;

using namespace std;
#define d_print(x) cout<<#x<<" = "<<x<<endl;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())

typedef float f_t;
typedef pair<int, pair<f_t,f_t> > f_loc;

vector<string> expand( const string & input, string delimiters = " \t" )
{
#define string_find(del,k) ((del).find((k)) != string::npos)
	vector<string> out;
	size_t begin = 0;
	size_t i;
	for( i = 0; i < input.length(); i++ )
	{
		if( i > 0 && string_find( delimiters, input[i] ) && !string_find( delimiters, input[i-1] ) )
		{
			out.push_back( input.substr( begin, i - begin ) );
			begin = i + 1;
		}
		else
		{
			if( string_find( delimiters, input[i] ) )
			{
				begin = i + 1;
			}
		}
	}
	if( begin < i )
	{
		out.push_back( input.substr( begin ) );
	}
	return out;
#undef string_find
}



int bin_search( vector<f_loc> & vec, double val, bool x )
{
	int a = 0;
	int b = vec.size() - 1;
	while( b - a > 1 )
	{
		int m = (a+b)/2;
		f_t n,k;
		n = x ? vec[m].second.first : vec[m].second.second;
		k = x ? vec[m+1].second.first : vec[m+1].second.second;
		if( n <= val && k >= val )
			return m;

		if( n > val )
		{
			b = m;
		}
		else
		{
			a = m;
		}
	}
	if( vec[vec.size()-1].second.second < val )
		return vec.size() - 1;
	return 0;
}

/*
================
SquareRootFloat
================
*/
float SquareRootFloat(float number) {
    long i;
    float x, y;
    const static float f = 1.5F;

    x = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;
    i  = 0x5f3759df - ( i >> 1 );
    y  = * ( float * ) &i;
    y  = y * ( f - ( x * y * y ) );
    y  = y * ( f - ( x * y * y ) );
    return number * y;
}

inline float Q_rsqrt( float number )
{
        long i;
        float x2, y;
        const float threehalfs = 1.5F;

        x2 = number * 0.5F;
        y  = number;
        i  = * ( long * ) &y;                       // evil floating point bit level hacking [sic]
        i  = 0x5f3759df - ( i >> 1 );               // what the fuck? [sic]
        y  = * ( float * ) &i;
        y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

        return y;
}

inline f_t my_sqrt( f_t numb )
{
//	return numb * Q_rsqrt( numb );
	return sqrt(numb);
//	return SquareRootFloat( numb );
}

bool x_sort( const f_loc & a, const f_loc & b )
{
	return a.second.first < b.second.first;
}

bool y_sort( const f_loc & a, const f_loc & b )
{
	return a.second.second < b.second.second;
}

bool neigh_sort( const pair<int, f_t> & a, const pair<int, f_t> & b )
{
	return a.second < b.second;
}

vector<f_loc> friends;
vector<f_loc> xf;
vector<f_loc> yf;

map<int, int> friends_map;
map<int, int> x_map;
map<int, int> y_map;

void solve( int n, map<int, vector<pair<int, f_t> > > & closest_neighbors )
{
	int bin_size = 400;

	vector<vector<int> > bins( n / bin_size + 1, vector<int> ( 0 ) );

	set<int> redo_left;
	set<int> redo_right;
	set<int> redo;

	int bin_cnt = 0;
	for( int xi = 0; xi < n; xi += bin_size )
	{
		if( n - xi < bin_size  )
		{
			xi = n - bin_size;
			if( xi < 0 ) xi = 0;
		}

		int xe = xi + bin_size - 1 ;
		if( xe >=n ) xe = n -1;

		f_t x_min = xf[ xi ].second.first;
		f_t x_max = xf[ xe ].second.first;

		for( int x = xi; x < xi + bin_size && x < n; ++x )
		{
			vector<pair<int, f_t> > & xv = closest_neighbors[ xf[ x ].first ];
			f_t ld = 1<<29;
			for( int x1 = xi; x1 < xi + bin_size && x1 < n; ++x1 )
			{
				if( x == x1 ) continue;

				f_t yd,xd;
				yd = fabs( xf[x1].second.first - xf[x].second.first );
				xd = fabs( xf[x1].second.second - xf[x].second.second);

				if(  yd > ld ) continue;
				if(  xd > ld ) continue;
				f_t dd = my_sqrt(pow(yd,2)+pow(xd,2));
				xv.push_back( make_pair( xf[ x1 ].first, dd ) );

				if( xv.size() >= 4 )
				{
					sort( ALL(xv),neigh_sort );
					xv.resize(3);
					ld = xv[2].second;
				}
			}

			ld = xv[3].second;

			if( ( ld > fabs( x_min - xf[x].second.first ) ) || ( ld > fabs( x_max - xf[x].second.first ) ) )
			{
				redo.insert(x);
			}
		}
	}

	d_print(redo.size() );

	for( set<int>::iterator i = redo.begin(); i != redo.end(); ++i )
	{
		vector<pair<int, f_t> > & xv =closest_neighbors[xf[ *i ].first];
		f_t ld = xv[2].second;
		f_t ld2 = ld;
		int yb = bin_search( yf, xf[*i].second.second - ld, false );
		//int ye = bin_search( yf, xf[*i].second.second + ld, false );
		if( yb < 0 ) yb = 0;

		f_t yd;
		for( int yi = yb; ( yd = yf[yi].second.second - xf[*i].second.second ) < ld; ++yi )
		{
			if(yi >= n ) break;
			if( xf[*i].first == yf[yi].first ) continue;

			f_t xd = fabs( yf[yi].second.first - xf[*i].second.first );
			if( xd > ld ) continue;
			f_t d = my_sqrt(pow(yd,2)+pow(xd,2));//dist( xf[*i], yf[yi] );
			if( d < ld )
			{
				xv.push_back( make_pair( yf[yi].first, d ) );

				sort(ALL(xv), neigh_sort );
				unique( ALL(xv) );
				xv.resize(4);

				ld = xv[3].second;
			}
		}
	}
}

int main( int argc, char ** argv )
{
	ifstream ifs( argv[ 1 ] );

	while( ifs.good() )
	{
		string t;
		getline( ifs, t );
		//d_print(t);
		vector<string> nums = expand( t, " \t" );
		if( nums.size() < 3 )
			break;
		friends.push_back( make_pair( atoi( nums[ 0 ].c_str() ), make_pair( atof( nums[ 1 ].c_str() ) * 1e2, atof( nums[ 2 ].c_str() ) * 1e2 ) ) ); // I multiply coordinates to prevent precision errors later.
	}

	int n = friends.size();

	xf = friends;
	yf = friends;
	sort( xf.begin(), xf.end(), x_sort );
	sort( yf.begin(), yf.end(), y_sort );

	map<int, vector<pair<int, f_t> > > closest_neighbors;

	solve( n, closest_neighbors );

	for( map<int, vector<pair<int, f_t> > >::iterator i = closest_neighbors.begin(); i != closest_neighbors.end(); ++i )
	{
		vector<pair<int, f_t> > & neighs = i ->second;
		cout << i->first << " ";
		for( int z = 0; z < 2; ++z )
		{
			cout << neighs[ z ].first << ",";
		}
		cout << neighs[ 2 ].first << endl;
	}

}
