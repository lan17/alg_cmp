#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>

using namespace std;

typedef vector<int> veci;



bool isPrime(int n )
{
	for( int i = 2; i <= n / 2; ++i )
	{
		if( n % i == 0 ) return false;
	}
	return true;
}

class MagicStonesStore {
	public:
	string ableToDivide(int n) 
	{
		veci primes;
		for( int i = 2; i <= 2000; ++i )
		{
			if( isPrime(i)) primes.push_back(i);
		}
		for( int i = 0; i < primes.size(); ++i )
		{
			for( int j = 0; j < primes.size(); ++j )
			{
				if( primes[i] + primes[j] == 2 *n ) return "YES";
			}
		}
		return "NO";
	}
};
