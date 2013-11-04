#include <iostream>
using namespace std;

int main(int argc, char ** argv )
{
	int w;
	cin>>w;
	if( w == 2 )
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<(w%2?"NO":"YES")<<endl;
}
