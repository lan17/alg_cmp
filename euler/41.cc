#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <bitset>
#include <boost/dynamic_bitset.hpp>

using namespace std;

const unsigned long long prime_lim = (unsigned long long)1e7;

bitset<prime_lim> primes;
// boost::dynamic_bitset<>  primes( prime_lim );

set<unsigned long long> prime_set;

string num = "1234567";

void make_primes()
{
	primes.reset();
	primes.flip();
	primes[0]=primes[1]=0;
	for( unsigned int i = 3; i < primes.size(); i += 2 )
	{
		if( !primes[i] ) continue;
		prime_set.insert(i);
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
	make_primes();
	cout<<"made primes with "<<primes.size()<<" numbas"<<endl;
	cout<<"there are "<<prime_set.size()<<" primes"<<endl;
	unsigned long long answer = 0;
	unsigned long long answer_max = 0;
	while( true )
	{
//		if( num[0] == '0' ) continue;
		unsigned long long n = atol(num.c_str() );
		//cout<<n<<endl;
		if( is_prime( n ) )
		{
			if( n > answer_max )
			{
				answer_max = n;
				//cout<<n<<endl;
			}
		} 
		//cout<<n<<endl;
		if( !next_permutation( num.begin(), num.end() ) ) break;
	}
	cout<<answer_max<<endl;
}
