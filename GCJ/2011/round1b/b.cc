#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define d_print(x) cout<<#x<<"="<<(x)<<endl;

typedef vector<string> vecs;
typedef unsigned long long ull;
typedef long long ll;

#define in(x,y) ((x).find((y)) != (x).end())

bool good( vector<double> & xs, double D )
{
	for( int i = 0; i < xs.size()-1; ++i )
	{
		if( xs[i+1] - xs[i] < D ) return false;
	}
	return true;
}

bool good(  const vector<double> & xs, double D, double t )
{
	vector<double> xi = xs;
	double max_dist = t;
	//d_print(max_dist);
	xi[0] -= max_dist;
	for( int i = 1; i < xi.size(); ++i )
	{
		double dist = fabs( xi[i-1] - xi[i] );
		if( dist < D ) return false;
		double dx;
		if( max_dist > (dist-D))
		{
			dx = dist-D;
		}
		else
		{
			dx = max_dist;
		}
		xi[i] -= dx;
	}
	return true;
}

double solve( const vector<double> & xs, double D )
{
	double a,b;
	a = 0;
	b = 10e20;
	while( fabs(a-b) > 0.1 )
	{
		//if( a==b) break;
		double t = ( a + b ) / 2.0;
		//cout<<t<<endl;
		bool g =good( xs, D, t );
		//d_print(a);
		//d_print(b);
		//d_print(t);
		//d_print(g);
		if( g )
		{
			b = t;
		}
		else
		{
			a = t;
		}
	}
	return a;
}



int main( int argc, char ** argv )
{
	int T;
	cin>>T;
	for( int CASE =1 ; CASE <= T; ++ CASE )
	{
		int C, D;
		cin>>C>>D;
		vector<vector<int> > input( C, vector<int>(2,0));
		vector<double> Xs;
		for( int i = 0; i < C; ++i )
		{
			int P,V;
			cin>>P>>V;
			input[i][0] = P;
			input[i][1] = V;
			for( int j = 0; j < V; ++j )
			{
				Xs.push_back( P );
			}
		}
		sort( Xs.begin(), Xs.end() );
		for( int i = 0; i < Xs.size(); ++i )
		{
			//cout<<Xs[i]<<" ";
		}
		//cout<<endl;
		double time = solve( Xs, D )/2.0;
		/*
		while( !good( Xs, D ))
		{
			time += 0.5;
			Xs[0] -= 0.5;
			Xs[Xs.size()-1] += 0.5;
			for( int i = 1; i < Xs.size()-1; ++i )
			{
				if( fabs( Xs[i+1] - Xs[i] ) > fabs( Xs[i-1] - Xs[i] ) )
				{
					Xs[i] += 0.5;
				}
				else if( fabs( Xs[i+1] - Xs[i] ) < fabs( Xs[i-1] - Xs[i] ) )
				{
					Xs[i] -= 0.5;
				}
			}
		}
	*/
		cout.setf(ios::fixed,ios::floatfield);            // floatfield not set
		cout.precision(1);
		cout<<"Case #"<<CASE<<": "<<time<<endl;

	}
	//cout<<mind( 1,1,1)<<endl;
}
