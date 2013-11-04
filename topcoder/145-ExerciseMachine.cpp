#include <string>
#include <iostream>
#include "math.h"

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define eps 1e-10

using namespace std;

class ExerciseMachine
{
      public:
             double getPercent( int seconds, int second )
             {
                    double answer = (double)second / (double) seconds;
                    return answer * 100.0;
             }
             
             int getPercentages( string time )
             {
                 int seconds = 0;
                 int count = -1;
                 seconds += atoi( time.substr( 0, 2 ).c_str( ) ) * 3600;
                 seconds += atoi( time.substr( 3, 2 ).c_str( ) ) * 60;
                 seconds += atoi( time.substr( 6, 2 ).c_str( ) );
                 FOR( second, seconds )
                 {
                      double z = getPercent( seconds, second );
                      if( fabs( z - floor( z + 0.5 ) ) <= eps  ) { count++; }
                 }
                 return count;
                 
             }
};
