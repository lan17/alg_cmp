#line 2 "PrimeSoccer.cpp"
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

unsigned long long fact( int i )
{
    unsigned long long ret = 1;
    FORR( j, 1, i )
    {
          ret *= j;
    }
    //cout<<i<<" "<<ret<<endl;
    return ret;
}

double nCk( int n, int k )
{
       return ((double)fact(n)) / ( double( fact(k) * fact( n - k ) ) );
}

double Pr( int n, int k, double p )
{
       return nCk( n, k ) * pow( p, k ) * pow( ( 1 - p ), n - k );
}

int prime[7] = { 2, 3, 5, 7, 11, 13, 17 };

class PrimeSoccer 
{
	public:
	double getProbability(int skillOfTeamA, int skillOfTeamB) 
	{
           		double ret = 0.0;
           		double Ap = (double)skillOfTeamA / 100.0;
           		double Bp = (double)skillOfTeamB / 100.0;
           		FOR( i, 7 )
           		{
                     //ret += max( Pr( 18, prime[i], Ap ), Pr( 18, prime[i], Bp ) );
                     ret += Pr( 18, prime[i], Ap );
                     //ret += Pr( 18, prime[i], Bp );
                }
                double ret2 = 0.0;
                FOR( i, 7 )
                {
                     ret2 += Pr( 18, prime[i], Bp );
                }
                ret += ret2 * ( 1- ret );
                return ret;
           		
	}
};


// Powered by FileEdit
