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

int print_dbg = 1;

#define d_print(x) { if(print_dbg){  cerr << __LINE__ << " " << #x << " = " << x << endl; cerr.flush(); } }

typedef vector<string> vecs;
typedef vector<int> veci;
typedef unsigned long long ull;
typedef long long ll;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

int main( int argc, char ** argv )
{
    int T;
    cin>>T;
    for( int CASE=1; CASE <= T; ++CASE )
    {
        int N,S,p;
        cin>>N>>S>>p;
        vector<int> t;
        for( int i = 0; i < N; ++i )
        {
            int tt;
            cin>>tt;
            t.push_back(tt);
        }
        vector<bool> surp(N,false);
        int sol = 0;
        for( int i = 0; i < N; ++i )
        {
            if( p == 0 )
            {
                ++sol;
            }
            else if( p <= 1 )
            {
                sol += t[i] > 0 ? 1 : 0;
            }
            else if( p*3-2 <= t[i] )
            {
                sol++;
                surp[i] = true;
            }
            else
            {
                if( S == 0 ) continue;
                if( ( 3*p-4 ) <= t[i] )
                {
                    ++sol;
                    --S;
                }
            }
        }
        cout<<"Case #"<<CASE<<": "<<sol<<endl;
    }

}
