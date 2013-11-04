#line 2 "FeudaliasBattle.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

inline double pow( int a , int b )
{
       return pow( (double) a, (double) b );
       }
 
class FeudaliasBattle 
{
	public:
	double getMinimumTime(vector <int> baseX, vector <int> baseY, vector <int> siloX, vector <int> siloY, int takeOffTime, int rechargeTime, int missileSpeed) 
	{
           double ca = sqrt( pow( siloX[0] - baseX[0], 2 ) + pow( siloY[0] - baseY[0], 2 ) );
           double cb = sqrt( pow( siloX[0] - baseX[1], 2 ) + pow( siloY[0] - baseY[1], 2 ) );
           double da = sqrt( pow( siloX[1] - baseX[0], 2 ) + pow( siloY[1] - baseY[0], 2 ) );
           double db = sqrt( pow( siloX[1] - baseX[1], 2 ) + pow( siloY[1] - baseY[1], 2 ) );
           
           cout<<ca<<endl<<cb<<endl<<da<<endl<<db<<endl;
           
           double cacb = 2 * ( (double)takeOffTime / 60.0 ) + max( ca/(double)missileSpeed , cb / (double)missileSpeed ) + (double) rechargeTime;
           
           double cadb = (double)takeOffTime / 60.0 + max( ca/(double)missileSpeed, db / (double)missileSpeed );
           double cbda = (double)takeOffTime / 60.0 + max( cb/(double)missileSpeed, da / (double)missileSpeed );
           double dadb = 2 * ( (double)takeOffTime / 60.0 ) + max( da/(double)missileSpeed , db / (double)missileSpeed ) + (double) rechargeTime;
           
           cout<<cacb<<endl;
           cout<<cadb<<endl;
           cout<<cbda<<endl;
           cout<<dadb<<endl;
           
           double ret = min( cacb, cadb );
           ret = min( cbda, ret );
           ret = min( dadb, ret ); 
           return ret;
		
	}
};
