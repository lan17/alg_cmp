#include <iostream>
#include <vector>
#include "BigInteger.hh"
#include "BigUnsigned.hh"

using namespace std;

typedef BigInteger bint;
typedef BigUnsigned buint;
typedef unsigned int uint;
typedef unsigned long long ull;

const ull BUFF_LIMIT = 1e6;
bool buff[BUFF_LIMIT]; 

// s
// 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25 27, 29
// 0, 1, 2, 3,  4, 5, 6,

// i = ( n - s ) / 2 
// n = i * 2 + s

inline ull index(buint x, )
{
	return (x-s)/2;
}

inline buint numba(ull x)
{
	return i*2+s;
}

int main( int argc, char ** argv )
{
	vector<buint> numbas;
	int count = 0;
	buint start_count = 1e16+1;

	memset(buffer,(uint(0)-1),sizeof(bool)*BUFF_LIMIT);
	buint number = 3;
	bool straight = true;
	bool * b1 = buff;
	bool * b2 = buff+BUFF_LIMIT/2;
	while( count < int(1e6) )
	{
		for( ull ii = 0; ii < BUFF_LIMIT * 2; ++ii )
		{
			bool fh = ii < (BUFF_LIMIT/2);
			bool * b = fh ? straight ? b1 : b2 : straight ? b2 : b1;

			if(b[ii])
			{
				ull jj = ii;
				buint mm = 3;
				while(jj < BUFF_LIMIT * 2)
				{
					//bool * bb = 
					//jj = index(numba(jj)*mm)
					  
					
				}
			}

		}


	}
	
}
