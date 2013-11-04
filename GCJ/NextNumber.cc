#include <iostream>
#include <fstream>
#include <algorithm>

#include <string>

using namespace std;


int main( int argc, char ** argv )
{
     char * in_file = argv[1];
     char * out_file = argv[2];
     
     ifstream ifs(in_file);
     ofstream ofs( out_file );
     int T;
    ifs>>T;
    cout<<T<<endl;
     for( int case_num = 1; case_num <= T; ++case_num )
     {
         
          string n;
 while( ifs.peek() == '\n' || ifs.peek() == '\r' ) ifs.ignore();
          getline( ifs,n);
          int len = n.size();
           while( ifs.peek() == '\n' || ifs.peek() == '\r' ) ifs.ignore();
           
          //char * c_n = new char[n.size()];
         // for( int i = 0; i < n.size();++i ) c_n[i] = n[i];
         //           cout<<c_n<<endl;
          bool e = next_permutation( n.begin(), n.end() );
          
         cout<<e<<endl;
          //n.assign(c_n);
          //n.substr( 0, len );
          if( e )
          {
              
          }
          else
          {
              int num_digit = 0;
             int num_zero = 1;
              int k = -1;
              string M = "";
              for( int i = 0; i < n.size(); ++i )
              {
                   if( n[i] != '0' )
                   {
                       num_digit++;
                       M += n[i];
                   }
                   if( n[i] != '0' && k == -1 ) k = i;
                   if( n[i] == '0' )
                   {
                       num_zero++;
                      //n =  n.erase( i, 1 );
                      
                   }
               }      
               n = M;
               sort( n.begin(), n.end());
               
               string zeros = "";
               for( int i = 0; i < num_zero; ++i ) zeros += "0";
               string rem = "";
               if( n.size() > 1 ) rem = n.substr( 1 );
               n = n[0] + zeros + rem;;
               
               
              //n.assign( c_n );
              
              
          }
          cout<<n<<endl;
          ofs<<"Case #"<<case_num<<": "<<n<<endl;
          
          
      }
      ofs.close();
}
