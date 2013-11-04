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


class bday
{
      public:
             bday( ){ }
             bday( int month, int day ): month( month ), day( day ){ start = false; }
       int month;
       int day;
       bool start;
       string name;
       bool operator< ( const bday b ) const
       {
            if( month < b.month ){ return true;}
            if( month == b.month && day < b.day ){ return true; }
            else return false;
       }
       string print( )
       {
              string m,d;
              if( month < 10 ) 
              {
                  m =  "0" + toString( month );
              }
              else
              {
                  m = toString( month );
              }
              if( day < 10 )
              {
                  d = "0" + toString( day );
              }
              else
              {
                  d = toString( day );
              }
              return m + "/" + d;
       }
};

class Birthday
{
      public:
             string getNext( string date, vector< string > birthdays )
             {
                    vector< bday > dayz;
                    dayz.resize( birthdays.size( ) + 1 );
                    dayz[0].start = true;
                    dayz[0].month = atoi( date.substr( 0, 2 ).c_str( ) );
                    dayz[0].day = atoi( date.substr( 3, 2 ).c_str( ) );
                    for( int i = 0; i < birthdays.size( ); ++i )
                    {
                         dayz[i+1].start = false;
                         dayz[i+1].month = atoi( birthdays[i].substr( 0, 2 ).c_str( ) );
                         dayz[i+1].day = atoi( birthdays[i].substr( 3, 2 ).c_str( ) );
                     }
                     sort( dayz.begin( ), dayz.end( ) );
                     for( int i = 0; i < dayz.size( ); ++i )
                     {
                          if( dayz[i].start )
                          {
                              if( i < dayz.size( ) - 1 ) 
                              {
                                  return dayz[i+1].print( );
                              }
                              else
                              {
                                  return dayz[0].print( );
                              }
                          }
                     } 
             }
                    
};

int main( )
{
    return 0; 
}
