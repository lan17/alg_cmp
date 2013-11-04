#line 2 "Embassy.cpp"
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

int comp( vector <int> forms, int dayLength, int openTime, int st )
{
    cout<<"========"<<endl;
    cout<<st<<endl;
    int ret = 0;
    int time = st;
    FOR( i, forms.size() )
    {
         time += forms[i];
         ret += forms[i];
         cout<<time<<" "<<ret<<endl;
         if( time > openTime )
         {
             if( time > dayLength )
             {
                 ret += time - dayLength;
                 time = time - dayLength;
             }
             else
             {
                 ret += dayLength - time;
                 time = 0;
             }
         }
         
          
    }
    cout<<ret<<endl;
    return ret;
}

class Embassy 
{
	public:
	int visaApplication(vector <int> forms, int dayLength, int openTime) 
	{
        int ret = (1<<29);
		for( int t = forms[0] * -1; t < dayLength; ++t )
		{
             ret = min( ret, comp( forms, dayLength, openTime, t ) );
         }
         return ret;
	}
};
