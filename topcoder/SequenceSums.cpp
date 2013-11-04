#line 2 "SequenceSums.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 


using namespace std;

inline int Sn( int n, int a1, int a2 )
{
       //return n * ( (a1+a2)/2);      
       
       int ret = 0;
       FORR( i, a1, a2 )
       {
             ret+=i;
       }
       return ret;
       
}

inline int solve_a1( int N, int n )
{
              return ((int)ceil(((double)N/(double)n))*2-n+1)/2;
}

int tmp1,tmp2;
inline int good( int N, int n )
{
       tmp1 = solve_a1( N, n );
       if( tmp1 < 0 ) return -1;
       //cout<<"Solving a1 = "<<tmp1<<" for "<<n<<endl;
       tmp2 = Sn( n, tmp1, tmp1+n-1 );
     //   cout<<"Solving a1 = "<<tmp1<<" for "<<n<<" sum = "<<tmp2<<endl;
       if( tmp2 == N ) return tmp1;
       else return -1;
}

class SequenceSums 
{
	public:
	vector <int> sequence(int N, int L) 
	{
		vector<int> ret;
		int a1;
		FORR( i, L, 100 )
		{
              a1 = good( N, i );
             // cout<<i<<" "<<a1<<endl;
              if( a1 == -1 ) continue;
              else
              {
               FORR( j, a1, a1 + i -1)
               {
                     ret.push_back( j );
               }
               break;
               }
        }
        return ret;
		 
	}
};
