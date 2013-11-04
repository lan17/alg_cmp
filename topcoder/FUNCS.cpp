#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> expand( const string & input, char delimiter )
{
     vector<string> out;
     size_t begin = 0;
     size_t i;
     for( i = 0; i < input.length( ); i++ )
     {
          if( i > 0 && input[i] == delimiter && input[i-1] != delimiter ) 
          { 
              out.push_back( input.substr( begin, i - begin ) ); 
              begin = i+1 ;
          }
          else
          {
              if( input[i] == delimiter ){ begin = i+1; }
          }
     }
     if( begin < i )
     {
         out.push_back( input.substr( begin ) );
     }
     return out;
}

std::vector<std::string> svsplit(const std::string& s, const std::string& delim, int limitElements=-1) {
	std::vector<std::string> res;
	std::string t;
	for (size_t i = 0; i < s.length(); ++i)
	{
		if (delim.find(s[i]) != std::string::npos && limitElements != 0) 
		{
                             res.push_back(t);
			t = "";
			--limitElements;
		} 
		else 
		{
			t += s[i];
		}
	}	
	res.push_back(t);
	return res;
}

void printV( vector<string> & v )
{
     for( size_t i = 0; i < v.size(); ++i )
     {
          cout<<"'"<<v[i]<<"' ";
     }     
}



std::vector<std::string> splitString( const std::string & input, const std::string & delimeter )
{
     std::vector<std::string> ret;
     
     size_t pos, last_pos = 0;
     while( ( pos = input.find( delimeter, last_pos ) ) != std::string::npos )
     {
            std::string tmp = input.substr( last_pos, pos - last_pos );
            if( tmp.size() > 0 ) ret.push_back( tmp );
            last_pos = pos+delimeter.size();
     }
     if( last_pos < input.size() ) ret.push_back( input.substr( last_pos ) );
     return ret;
}

int main()
{
    vector<string> list = splitString( "/lev_test_3_small/src/zomg.java^&^neiman^&^9", "/" );
    printV( list );
    
    string str1( "Alpha Beta  Omega Gamma Delta" );
     string::size_type loc = str1.find( "Omega", 0 );
     if( loc != string::npos ) {
       cout << "Found Omega at " << loc << endl;
     } else {
       cout << "Didn't find Omega" << endl;
     }
    
    int i;
    cin>>i;
}
