#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

#define lim 1000000

char primes[lim];

void make_primes()
{
	memset(primes, 1, sizeof(bool) * lim );
	primes[0]=primes[1] = 0;
	for( int i = 2; i *2 < lim; ++i )primes[i*2]=0;
	
	for( int i = 3; i < lim; i += 2 )
	{
		if( !primes[i] ) continue;
		for( int j = 2; j * i < lim; ++j )
		{
			primes[i*j] = 0;
		}
	}
}

int num( int a, int b )
{
	int num = 0;
	for( int n = 0; n < 100000; ++n )
	{
		int t = n*n+a*n+b;
		if( t < 0 ) break;
		if( primes[t] )++num;
		else break;
	}
	return num;
}

int main( int argc, char ** argv )
{
	make_primes();	
	cout<<num(1,41)<<endl;
	cout<<num(-79,1601)<<endl;

	int answer = 0;
	int a_m,b_m;
	for( int a = -1000; a < 1000; ++a )
	{
		for( int b = -1000; b < 1000; ++b )
		{
			int t = num(a,b);
			if( answer <= t )
			{
				answer = t;
				a_m = a;
				b_m = b;
			}
		}
	}
	cout<<answer<<','<< a_m<<','<<b_m<<endl;
	cout<<(a_m*b_m)<<endl;
}
