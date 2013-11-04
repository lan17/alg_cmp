#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

template <class T >
string toString( const T & a )
{
       stringstream s;
       s<<a;
       return s.str( );
}

pair<int,int> extractdate( const string & a )
{
	int i = a.find( "/" );
	int j = a.find( " " );
	if( j == string::npos ) j = a.size() -1;
	return make_pair( atoi( a.substr( 0, i ).c_str() ), atoi( a.substr( i+1, j-i ).c_str()) );
}

bool cmp( const string & a, const string & b )
{
	pair<int,int> ad = extractdate( a );
	pair<int,int> bd = extractdate( b );
	if( ad.first < bd.first ) return true;
	if( ad.first == bd.first ) return ad.second < bd.second;
	return false;
}

class Birthday
{
      public:
             string getNext( string date, vector< string > birthdays )
             {
		     if( birthdays.size() == 1 )
		     {
			     return birthdays[0].substr( 0, birthdays[0].find(' '));
		     }
		     sort( birthdays.begin(), birthdays.end(), cmp );
		     pair<int,int> dd = extractdate( date );
		     int i = 0;
		     while( i < birthdays.size() && cmp( birthdays[i], date ) ) ++i;
		     if( i == birthdays.size() ) return birthdays[0].substr( 0, birthdays[0].find(' ' ));
		     return birthdays[i].substr( 0, birthdays[i].find(' '));
             }
                    
};


// Powered by FileEdit
