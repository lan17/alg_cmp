#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

const unsigned long long prime_lim = (unsigned long long)1e7;

bitset<prime_lim> primes;
// boost::dynamic_bitset<>  primes( prime_lim );

string num = "1234567";

void make_primes( ofstream & os )
{
	primes.reset();
	primes.flip();
	primes[0]=primes[1]=0;
	for( unsigned int i = 3; i < primes.size(); i += 2 )
	{
		if( !primes[i] ) continue;
		os<<i<<endl;
		//cout<<i<<endl;
		for( int j = 2; i * j < primes.size(); ++j )
		{
			primes[i*j] = false;
		}
	}
}

bool is_prime( unsigned long long num )
{
	if( num % 2 == 0 ) return false;
	return primes[num];
}

int main( int argc, char ** argv )
{
	
	cout<<"Made primes..."<<endl;
	ofstream ofs( argv[1] );
	ofs<<"2"<<endl;
	make_primes(ofs);
	ofs.close();
}
