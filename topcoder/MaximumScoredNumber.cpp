#line 2 "MaximumScoredNumber.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

map< int, int > table;

int num_squares( int a )
{
    int ret = 0;
    int sq = (int)sqrt( (float) a );
    // cout<<sq<<endl;
    for( int i = 0; i <= sq; ++i )
    {
         for( int j = i; j <= sq; ++j )
         {
              
              if( i *i + j*j == a )
              {
                  //cout<<i<<" "<<j<<endl;
                  ret ++;
                  }
         }
     }
     return ret;
}

class MaximumScoredNumber 
{
	public:
	int getNumber(int lowerBound, int upperBound) 
	{
		int largest = 0;
		int largest_ways = 0;
		//cout<<num_squares(25);
		
		for( int i = lowerBound; i <= upperBound; ++i )
		{
             int n = num_squares( i );
             //cout<<i<<" "<<num_squares(i)<<endl;
             if( n >= largest_ways )
             {
                 largest_ways = n;
                 largest = i;
             }
        }
        
        return largest;
	}
};
