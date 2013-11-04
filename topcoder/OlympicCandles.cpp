#line 2 "OlympicCandles.cpp"
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

class OlympicCandles 
{
	public:
	int numberOfNights(vector <int> candles) 
	{
        sort( ALL( candles ) );
        int nights = 0;
        int night = 0;
        
        while( true ) 
        {
               
               sort( ALL( candles ) );
               night++;
              int candle = candles.size() - night; 
              if( candle < 0 ) break;
              if( candles[candle] == 0 ) break;
              
              FORR( i, candle, candle + ( night - 1 ) ) 
              {
                    cout<<i<<endl;
                    //if( candles[i] == 0 ) return night;
                    candles[i]--;                    
              }
              cout<<"=========="<<endl;
              
              
              
        }
        return night-1;
		
	}
};
