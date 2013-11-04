/*
// PROBLEM STATEMENT
// The Greek mathematician Archimedes of Syracuse (287-212 B.C.) was most likely the first in finding a way to systematically (iteratively) approximate the value of Pi, the ratio between the perimeter and the diameter of a circle.

He inscribed and circumscribed regular polygons in/around a circle and calculated their perimeter. These are lower (inscribed polygon) and upper (circumscribed polygon) bounds for the perimeter of the circle, and therefore can be used to calculate lower and upper bounds for Pi. He then found a formula for directly calculating the perimeter of inscribed and circumscribed polygons with 2*n sides only using the values previously calculated for polygons with n sides.

You now have a slightly simpler task, considering only inscribed polygons. You are given an int numSides, the number of sides of a regular polygon that is inscribed in a circle. Return a double, the approximated value for Pi when the perimeter of that polygon is used as an approximation for the perimeter of the circle.


[Image showing a circle with an 8-sided regular polygon inscribed]


DEFINITION
Class:Archimedes
Method:approximatePi
Parameters:int
Returns:double
Method signature:double approximatePi(int numSides)


NOTES
-Perimeter of a circle: 2 * PI * radius
-Perimeter of a n-sided regular polygon: n * sidelength
-Reminder how doubles are evaluated:If your result is within 1e-9 of the expected result, your solution will be evaluated as correct.If your result is between (1+1e-9) * expected and (1-1e-9) * expected, it will be evaluated as correct.


CONSTRAINTS
-numSides will be between 3 and 100000, inclusive.


EXAMPLES

0)
3

Returns: 2.598076211353316

1)
8

Returns: 3.0614674589207183

2)
17280

Returns: 3.1415926362832276

*/
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

#define PI 3.14159265
#define CRA 0.0174532925

class Archimedes {
	public:
	double approximatePi(int numSides) 
	{
		double r=1.0;
		double a=360.0/(double)numSides;
		cout<<"a="<<a<<endl;
		double t=(180.0-a)/2.0;
		cout<<"t="<<t<<endl;
		a *= CRA;
		t *= CRA;
		double s=fabs((r*sin(a))/sin(t));
		cout<<"s="<<s<<endl;
		double perimeter = numSides * s;
		cout<<"perimeter="<<perimeter<<endl;
		double diameter = r*2;
		cout<<"diameter="<<diameter<<endl;
//		return 0.5 * sin( a ) / sin( t ) * numSides; 
		return numSides * sin( PI / numSides );
	}
};
