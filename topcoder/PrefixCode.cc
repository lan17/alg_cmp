#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;



class PrefixCode
{
      public:
             
             bool isPrefix( vector <string > words, string word, int z )
             {
                  for( int i = 0; i < words.size( ); ++i )
                  {
                       string tmp = words[i].substr( 0, word.size( ) );
                       if( word == tmp && i != z ) { return true; }
                  }
                  return false;
              }
             string isOne(vector <string> words)
             {
                    if( words.size( ) == 1 ) { return "Yes"; }
                    for( int i = 0; i < words.size( ); ++i )
                    {
                         if( isPrefix( words, words[i], i ) )
                         {
                             stringstream s;
                             s<<i;
                             return "No, " + s.str( );
                        
                         }
                    }
                    return "Yes";
                    
             }
      
      
      };
      
int main( )
{
    return 0;
}
