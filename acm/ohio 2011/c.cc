#include <iostream>


typedef unsigned long long ull;

#include <vector>
#include <string>
 
using namespace std;
 
class AmoebaDivTwo
{
  public:
    static int count(vector <string> & table, int K)
    {
	for( int i = 0; i < table.size();++i )
	{
	//	cout<<table[i]<<endl;
	}
	//cout<<"K="<<K<<endl;
      int n = table.size();
      int m = table[0].size();
	//cout<<"m="<<m<<endl;
	//cout<<"n="<<n<<endl;
      int ret = 0;
      for( int i = 0; i < n; ++i )
      {
        for( int j = 0; j < m; ++j )
        {
        bool ok;
          if( table[i][j] == 'M' ) continue;
          if( n - i >= K )
          {
           ok = true;
          for( int i1 = i+1; i1 < n && i1 < i + K; ++i1 )
          {
		//cout<<"I1"<<i1<<endl;
            if( table[i1][j] != 'A' ) 
            {
              ok = false;
              break;
            }
          }
          if( ok ) ++ret;
          }
          
          
          if( m - j >= K )
          {
		ok = true;
		//cout<<"JSHIT!"<<endl;
          for( int j1 = j + 1; j1 < m && j1 < j + K; ++j1 )
          {
	  //  cout<<"j1"<<j1<<endl;
            if( table[i][j1] != 'A' )
            {
              ok = false;
              break;
            }
          }
          if( ok ) ++ret;
          }
        }
      }
      if( K == 1 )
      {
      ret= 0;
        for( int i = 0; i < n; ++i )
        {
          for( int j = 0; j < m; ++j )
          {
            if( table[i][j] == 'A' ) ret ++;
          }
        }
      }
      return ret;
    }
};

#define eat_input() while( cin.peek() =='\n' || cin.peek() =='\r') cin.ignore()

int main(int argc, char ** argv )
{
	int X,K;
	cin>>X;
	vector<string> table;
	//if( cin.peek() == '\n' ) cin.ignore();
	//cout<<"FUCK SHIT PISS"<<endl;
	//cout<<X<<endl;
	for( int i = 0; i < X; ++i )
	{
		eat_input();
		string t;
		getline( cin, t );
		eat_input();
		table.push_back( t );
		//cout<<t<<endl;
	}
	eat_input();
	cin>>K;
	//cout<<K<<endl;
	cout<<AmoebaDivTwo::count(table, K )<<endl;
}
