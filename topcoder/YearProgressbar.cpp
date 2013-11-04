#line 2 "YearProgressbar.cpp"
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

int month_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string month_names[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int num_min()
{
    int ret = 0;
    FOR( i, 12 )
    {
         ret += month_days[i]*24*60;
    }
    return ret;
}

int num_min_leap()
{
    int ret = 0;
    FOR( i, 12 )
    {
         ret += month_days[i]*24*60;
    }
    return ret + 24 * 60;
}



bool isLeapYear( int year )
{
     return year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 );
}

int wholeYear( string year )
{
    int y = atoi( year.c_str() );
    if( isLeapYear( y ) ) return num_min_leap(); else return num_min();
}

int countMin( string month, string day, string year, string hour, string min )
{
    int ans = 0;
    int month_num = 0;
    int year_num = atoi( year.c_str() );
    int day_num = atoi( day.c_str() );
    int hour_num = atoi( hour.c_str() );
    int min_num = atoi( min.c_str() );
    FOR( i, 12 )
    {
         if( month_names[i] == month )
         {
             month_num = i;
             break;
         }
    }
    FOR( i, month_num )
    {
         ans += month_days[i] * 24 * 60;
         if( isLeapYear( year_num ) && i == 1 ) ans += 24 * 60;
    }
    ans += ( day_num - 1 ) * 24 * 60;
    ans += hour_num * 60;
    ans += min_num;
    return ans;
}

class YearProgressbar 
{
	public:
	double percentage(string currentDate) 
	{
		string month = currentDate.substr( 0, currentDate.find_first_of( ' ' ) );
		string day = currentDate.substr( currentDate.find_first_of( ' ' ) + 1, 2 );
        string year = currentDate.substr( currentDate.find_first_of( ',' ) + 1, currentDate.find( currentDate.find_first_of( ',' ), ' ' ) - currentDate.find_first_of( ',' ) );
        year = year.substr( 0, year.find_last_of( ' ' ) );
        string hour = currentDate.substr( currentDate.find( ':' ) - 2, 2 );
        string min = currentDate.substr( currentDate.find( ':' ) +1, 2 );
        cout<<month<<endl<<day<<endl<<year<<endl<<hour<<endl<<min;
        
        return (double)countMin( month, day, year, hour, min ) / (double)wholeYear( year ) * 100.0;
        
	}
};
