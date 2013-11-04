#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char**argv)
{
    string input;
    getline( cin, input );
    string nums;
    getline( cin, nums );
    int num = atoi( nums.c_str() );
    vector<string> matches;
    for( int i = 0; i < num; ++i )
    {
         string t;
         getline( cin, t );
         bool ok = true;
         for( size_t j = 0; j < input.size() && j < t.size(); ++j )
              if( t[j] != input[j] ) ok = false;
         if(ok)matches.push_back(t);
     }
     sort( matches.begin(), matches.end() );
     if( matches.size() == 0 ) cout<<input<<endl;
     else cout<<matches[0]<<endl;
}
