#include <iostream>


typedef unsigned long long ull;

#include <vector>
#include <string>
 
using namespace std;

#define eat_input() while( cin.peek() =='\n' || cin.peek() =='\r') cin.ignore()

int solve( vector<int> & x, vector<int> & y )
{
	
}

int main( int argc, char ** argv )
{
	int case_num = 1;
	while( !cin.eof() )
	{
		eat_input();
		int n;
		cin>>n;
		eat_input();
		cout<<n<<endl;
		if( n == 0 ) break;
		vector<int> x;
		vector<int> y;
		for( int i = 0; i < n; ++i )
		{
			eat_input();
			int xt,yt;
			cin>>xt>>yt;
			cout<<"xt = "<<xt<<endl<<"yt = "<<yt<<endl;
			x.push_back(xt);
			y.push_back(yt);
			
		}
		//cout<<"The towers in case "<<(case_num++)<<" can be covered in "<<solve( x,y)<<" frequencies."<<endl;
	}
}
