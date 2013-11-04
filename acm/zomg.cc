#include <cmath>
#include <map>

using namespace std;

map<float,float> zomg;

int main()
{
    while( 1 )
    {
           for( float i = 0; i < 10000; i += .1 )
           {
                zomg[i] = sin( i );
           }
    }
}
