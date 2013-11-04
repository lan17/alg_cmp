#include <iostream>

using namespace std;

int main ( )
{
int res = 0;
int n;
cin>>n;
for (int i = 0; i <= n; ++i){ res += (i + n) * (n - i + 1) / 2 + i * (n - i + 1); }

cout<<res;

}
