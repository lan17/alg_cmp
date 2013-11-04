#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <cstdio>
#include <valarray>      
#include <ext/hash_set> 
#include <ext/hash_map>
#include <list>
#include "float.h"

#define FMAX DBL_MAX
#define FMIN DBL_MIN

#define ld long double
#define ll long long
#define ull unsigned long long

#define vecs vector< string > 
#define veci vector< int >
#define vecsi vector<string>::iterator
#define vecii vector<int>::iterator
#define vec vector

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define pnt(x) cout<<#x<<" = "<<(x)<<endl;

using namespace std;

int findP( int sum, int p, vector< int > & s, int length )
{
     //cout<<sum<<" "<<p<<endl;
    if( sum + p > length ) return 0;
    if( sum + p == length )
    {
        s[p-1] += p;
        return p;
    }
    bool ret = 0;
    FORR( i, p+1, sum + p +1 )
    {
          int min_c = 1<<30;
          int c = findP( sum + p, i, s, length );
          if( c > 0 )
          {
              if( min_c > c ) min_c = c;
              //s[i-1] = min_c;
              ret = min_c;
              //break;
          }
          
    }
    if( ret > 0 ) s[p-1] += ret;
    return ret;
    
}

class IdealString 
{
	public:
	string construct(int length)
	 {
           if( length == 1 ) return "A";
        string ret ="";
        vector< int > s( length, 0 );
        s[0] = 1;
        /*
        cout<<"CAN SOLVE = "<<findP( 1,2, s, length )<<endl;
        
        */
        if( findP( 1, 2, s, length ) )
        {
            FOREACH( el, s )
        {
                 cout<<*el<<" ";
        }
            map<char, int > m;
            ret.resize( length, 'A' );
            char curr='B';
            FORR( i,1,  s.size() - 1  )
            {
                 if( s[i] )
                 {
                     m[curr] = i;
                     ret[i] = curr;
                     curr++;
                 }
             }
             curr ='B';
             FORR( i, 1, s.size() - 1 )
             {
                  if( !s[i] )
                  {
                      ret[i] = curr;
                      m[curr]--;
                      if( m[curr] == 0 ) curr++;
                  }
              }
              
              
              return ret;
        }
        else return "";
		
	}
};

/* Lev A Neiman's coding here */


// Powered by FileEdit


// Powered by FileEdit
