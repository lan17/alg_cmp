#line 2 "InverseFactoring.cpp"
#include <algorithm>
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

int minV( vector<int> & fact )
{
    int m = 1<<29;
    FOR( i, fact.size() ) m = min( m, fact[i] );
    return m;
}

int maxV( vector<int > & fact )
{
    int m = 0;
    FOR( i, fact.size() ) m = max( m, fact[i] ) ;
    return m;
}

bool isF( vector <int> & factors, int n )
{
     FOR( i, factors.size() )
     {
          if( n % factors[i] != 0 || factors[i] == n || factors[i] == 1 ) return false;
     }
     return true;
}

class InverseFactoring 
{
	public:
	int getTheNumber(vector <int> factors) 
	{
        if( factors.size() == 1 ) return factors[0] * factors[0];
        int s = minV( factors );
             int l = maxV( factors );
             //cout<<s<<" "<<l<<endl;
             //cout<<isF( factors, 8 );
        FORR( i, s * l, l * l )
        {
              if( isF( factors, i ) ) return i;
        }
             
        
	}
};

int main()
{
    vector< int> p;
    p.push_back( 3 );
    p.push_back( 12 );
    p.push_back( 100 );
    p.push_back( 110 );
    InverseFactoring c;
    cout<<c.getTheNumber( p );
    int cing;
    cin>>cing;
}
