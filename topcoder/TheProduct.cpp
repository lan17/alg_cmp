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
#include "float.h"

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

#define print(x) cout<<#x<<" = "<<(x)<<endl;

using namespace std;
class TheProduct {
	public:
	long long maxProduct(vector <int> numbers, int k, int maxDist) 
	{
		 long long INF = 100000000000000000LL;
		  long long dp[2][50][11];
		  // Initialize
		  for (int i = 0; i < 50; i++)
		    for (int j = 1; j <= 10; j++)
		      { dp[0][i][j] = INF; dp[1][i][j] = 0LL-INF; }

		  for (int i = 0; i < numbers.size(); i++)
		    for (int j = 1; j <= k; j++)
		      if (j==1) dp[0][i][j] = dp[1][i][j] = numbers[i]; // Initialize for (j == 1)
		      else
		      {
		        // Compute for j >= 2
		        // Use conditional operator to distinguish between case 1 and case 2
		        for (int m = 1; m <= maxDist && m <= i; m++)
		        {
		          dp[0][i][j] = min(dp[0][i][j], dp[((numbers[i]>=0)?0:1)][i-m][j-1]*numbers[i]);
		          dp[1][i][j] = max(dp[1][i][j], dp[((numbers[i]>=0)?1:0)][i-m][j-1]*numbers[i]);
		        }
		      }

		  // Get answer
		  long long ret = 0LL - INF;
		  for (int i = 0; i < numbers.size(); i++)
		    ret = max(ret, dp[1][i][k]);
		  return ret;
	}
};


// Powered by FileEdit
