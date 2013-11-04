

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>

using namespace std;

#define rep(i,b) for(int i=(0);i<(b);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(__typeof((b).begin()) a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>

int cond = (ll)1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }


const int sz = 20;
ld sum[1<<sz];
ld dp[1<<sz][sz];

void solve() {
	map <string, int> names;
	char buf[100], buf2[100];
	int dst[100][100];
	rep (i, 100) rep (j, 100) dst[i][j] = (int)1e9;
	int n;
	scanf("%d", &n);
	ld prob[100] = {};
	rep (i, n) {
		scanf("%s%Lf", buf, &prob[i]);
		names[buf] = i;
	}
	int m;
	scanf("%d", &m);
	rep (i, m) {
		int cost;
		scanf("%s%s%d", buf, buf2, &cost);
		if (names.count(buf) == 0) names[buf] = names.size();
		if (names.count(buf2) == 0) names[buf2] = names.size();
		dst[names[buf]][names[buf2]] = cost;
		dst[names[buf2]][names[buf]] = cost;
	}
	int g = names.size();
	rep (a, g) rep (b, g) rep (c, g) dst[b][c] = min(dst[b][c], dst[b][a] + dst[a][c]);
	rep (i, (1<<g)) {
		rep (j, g) if (i & (1<<j)) sum[i] += prob[j];
	}
	rep (i, (1<<g))  rep (j, g) dp[i][j] = (int)1e9;
	dp[1][0] = 0;
	rep (i, (1<<g)) rep (j, g) if (dp[i][j] < (int)1e9) {
		ld cur = dp[i][j];
		rep (k, g) if (!((i) & (1<<k))) {
			int ni = i | (1 << k);
			dp[ni][k] = min(dp[ni][k], cur + (1 - sum[i]) * dst[j][k]);
		}
	}
	ld result = (ld)1e9;
	rep (j, g) result = min (result, dp[(1<<g)-1][j]);
	printf("%.2Lf\n", result == (ld)1e9 ? -1 : result);
}

int main(int argc, char ** argv) {
    //  freopen("../1.in","r",stdin); 
    //  freopen("../2.in","r",stdin); 
    //  freopen("../3.in","r",stdin); 
    //  freopen("../A-small.in","r",stdin); freopen("../A-small.out","w",stdout);
    //  freopen("../A-small-attempt0.in","r",stdin);freopen("../A-small-attempt0.out","w",stdout);
    //  freopen("../A-small-attempt1.in","r",stdin);freopen("../A-small-attempt1.out","w",stdout);
    //  freopen("../A-small-attempt2.in","r",stdin);freopen("../A-small-attempt2.out","w",stdout);
    //  freopen("../A-large.in","r",stdin); freopen("../A-large.out","w",stdout)

    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int t;
    t = 1;
    fo (i, 1, t) {
        solve();
    }
	return 0;
}
