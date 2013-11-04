#include <vector>
#include "float.h"

using namespace std;

double f( double x, double R )
{
	return R*x*(1.0-x);
}

class FixedPointTheorem
{
	public:
		double cycleRange( double R )
		{
			double x = .25;
			double low, high;
			low = DBL_MAX;
			high = DBL_MIN;
			for( int i = 1; i <= 200000; ++i )
			{
				x = f( x, R );
			}
			for( int i = 0; i < 1000; ++i )
			{
				if ( low > x )
				{
					low = x;
				}
				if( high < x )
				{
					high = x;
				}
				x = f( x, R );			
			}
			return high - low;
		
		}
		
};


// Powered by FileEdit
