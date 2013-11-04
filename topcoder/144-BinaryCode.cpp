#include <string>
#include <sstream>
#include <vector>

using namespace std;

template <class T >
string toString( const T & a )
{
       stringstream s;
       s<<a;
       return s.str( );
       }

class BinaryCode
{
      public:
             
      string inttostring(  vector<int> & message )
      {
             string ret= "";
             for( int i = 0; i < message.size( ); ++i )
             {
                  ret += toString( message[i] );
             }
             return ret;
      }
             
      string get( vector<int> message, int first )
      {
             if( message.size( ) == 1 ){ if( message[0] == first ) return inttostring( message ); else return "NONE"; }
             vector<int> decoded;
             decoded.resize( message.size( ) );
             decoded[0] = first;

             decoded[1] = message[0] - first;
             if( decoded[1] > 1 ){ return "NONE"; }
             //if( message.size( ) == 2 ) { return inttostring( decoded ); }
             
             for( int i = 2; i < message.size( ); ++i )
             {
                    decoded[i] = message[i-1] - decoded[i-1] - decoded[i-2];
                    if( decoded[i] > 1 || decoded[i] < 0 ) { return "NONE"; }
             }
             if( message.size( ) ==2 )
             {
                 if( decoded[1] < 0 || decoded[1] > 1 ) { return "NONE"; }
                 if( message[message.size( ) - 1 ] == decoded [0] + decoded[1] )
                 {
                     return inttostring( decoded );
                     }
                     return "NONE";
                     }
             if( message[message.size( ) - 1] == decoded[decoded.size( ) - 2 ] + decoded[decoded.size( ) - 1 ] )
             {
             return inttostring( decoded );
             }
             return "NONE";
             
      }
      
      vector <string> decode(string message)
      {
            vector<int> messagei; 
            messagei.resize( message.size( ) );
            for( int i = 0; i < message.size( ); ++i )
            {
                 messagei[i] = message[i] - 48;
            }
            vector<string> ret;
            ret.resize( 2 );
            ret[0] = get( messagei, 0 );
            ret[1] = get( messagei, 1 );
            return ret;
            
            
             
      }
};
