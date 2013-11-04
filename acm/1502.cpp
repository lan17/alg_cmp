#include <iostream>
#include <set>
#include <map>

using namespace std;

int main ( )
{
    int n;
    cin>>n;
	__int64 ret = 3;
    for( __int64 i = 2; i <= n; ++i )
    {
		 __int64 j = i*(i+1);
         ret += j+j/2;
    }
    cout<<ret;
}
