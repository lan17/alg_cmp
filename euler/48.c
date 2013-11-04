#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull pow(ull b, ull p)
{
	ull ret = 1;
	for( ull i = 0; i < p; ++i )
	{
		ret *= b ;
		ret %= (ull)1e10;
	}
	return ret;
}

int main(int argc, char ** argv)
{
	cout<<pow(2,4)<<endl;
	ull num = 0;
	for( ull i = 1; i <= 1000; ++i )
	{
		num += pow(i,i);
	}
	cout<<num<<endl;
}
