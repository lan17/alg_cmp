#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

#define d_print(x) cout<<#x<<" = "<<x<<endl

double e = 2.7182818284590452353;
int infinity = 1<<29;

inline bool string_find( const string & del, const char & k )
{
	return del.find(k) != string::npos;
}

vector<string> expand( const string & input, string delimiters = " \t")
{
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
}

template <class T>
string toString( const T & a )
{
	stringstream s;
	s<<a;
	return s.str();
}

double round(double d)
{
  return floor(d + 0.5);
}


double P(double z, double s)
{
	const double lim = (double)(1<<10);
	//P(z,s) = e^(-63s+10)/(e^(-63s+10)+e^(-21z))
	//return pow( e, -63.0*s + 10.0 ) / ( pow( e, -63.0 * s + 10.0 ) + exp( -21.0 * z ) );
	//return exp( -63.0 * s + 10.0 ) / ( exp( -63.0 * s + 10.0 ) + exp( -21.0 * z ) );
	double p = -21.0*z+63.0*s-10.0;
	if(fabs(p)>=lim)
	{
		if( p < 0 ) return 1.0;
		else return 0.0;
	}
	return 1.0 / ( 1.0  + exp(p) );
}

double E( double z, double s, double m )
{
	if( z <= 0.0 ) return 0;
	double t = P(z,s);
	//cout<<"t : "<<t<<endl;
	return round( t * m );
}

int min_zerg( int z, double s, double m )
{
	double mm = E( z, s, m );
	if( mm <= 0.0 || z == 0 ) return infinity;
//	cout<<"mm = "<<mm<<endl;
	while( true )
	{
		mm = E( z-1, s, m );
		if( mm < m ) break;
		z -= 1;
		
	}
	return z;
}

struct t_base
{
	int index;
	int s;
	int m;

	t_base( int index, int s, int m ):index(index),s(s),m(m){}
};


double z_cmp = 0;
bool t_base_cmp( const t_base & a, const t_base & b )
{
	double a1 = ((double)a.m)/(double)min_zerg( z_cmp, a.s, a.m );
	double b1 = ((double)b.m)/(double)min_zerg( z_cmp, b.s, b.m );

	return a1 > b1;
}

void ltrim( string & t )
{
	int i = 0;
	for( ; t[i] == ' '; ++i );
	t = t.substr( i );
}


int main( int argc, char ** argv )
{
	ifstream ifs( argv[1] );
//	cout<<E( 1000, 234, 455 )<<endl;
//	cout<<min_zerg( 701, 230, 455 )<<endl;
	int P;
	ifs>>P;
	vector<vector<t_base > > planet_bases(P);
	vector<int> planet_zerg(P);
	for( int p = 0; p < P; ++p )
	{
		int T, Z;
		ifs>>T>>Z;
		planet_zerg[p] = Z;
		for( int t = 0; t < T; ++t )
		{
			int s, m;
			ifs>>s>>m;
			double e = E( (double)Z, (double)s, (double)m );
//			cout<<Z<<" "<<s<<" "<<m<<" "<<e<<" "<<endl;
//			if( e >= 1.0 ) 
				planet_bases[p].push_back(t_base(t,s,m) );
		}
	}


	for( int i = 0; i < P; ++i )
	{
		//z_cmp = planet_zerg[ i ];
		//sort( planet_bases[i].begin(), planet_bases[i].end(), t_base_cmp );
		/*
		for( int t = 0; t < planet_bases[i].size(); ++t )
		{
			cout<<"{ "<<planet_bases[i][t].index<<": "<<planet_bases[i][t].s<<", "<<planet_bases[i][t].m<<" } ";
		}
		cout<<endl;
		*/
	}

	for( int p = 0; p < P; ++p )
	{
		int Z = planet_zerg[p];
		int T = planet_bases[p].size();
		//d_print(Z);
		//d_print(T);
		vector<vector<int> > m( T+1, vector<int>(Z+1, 0 ) );
		vector<vector<pair<int,pair<int,int> > > > mb( T+1, vector<pair<int,pair<int,int> > >(Z+1, make_pair(0, make_pair(0,0) ) ) );
		for( int i = 1; i <= T; ++ i )
		{
			for( int z = 1; z <= Z; ++z )
			{
				int w = min_zerg( z, planet_bases[p][i-1].s, planet_bases[p][i-1].m );
				//d_print(w);
				if( w > z )
				{
					m[i][z] = m[i-1][z];
					mb[i][z] = make_pair( 0, make_pair( i-1, z ) );
				}
				else
				{
					int t0 = m[i-1][z];
					int t1 = m[i-1][z-w] + planet_bases[p][i-1].m;
					//d_print( t0 );
					//d_print( t1 );
					//d_print( i );
					//d_print( z );
					//cout<<"==========="<<endl;
					if( t0 > t1 )
					{
						m[i][z] = t0;
						mb[i][z] = make_pair( 0, make_pair( i-1, z ) );
					}
					else
					{
						m[i][z] = t1;
						mb[i][z] = make_pair( w, make_pair( i-1, z - w ) );
					}
					//m[i][z] = max( t0, t1 );
				}
			}
		}
		string assignments = "";
		int total_z = 0;
		int x1 = T;
		int y1 = Z;
		while( !( x1==0 && y1==0 ) )
		{
			int x2 = mb[x1][y1].second.first;
			int y2 = mb[x1][y1].second.second;
			int w1 = mb[x1][y1].first;
			if( w1 > 0 )
			{
				total_z += w1;
				assignments = " " + toString( x1 - 1) + " " + toString( w1 ) + assignments;
			}
			x1 = x2;
			y1 = y2;
		}
		ltrim( assignments );
		cout<<total_z<<" "<<m[T][Z]<<endl;
		cout<<assignments<<endl;
	}
	

	
	
}
