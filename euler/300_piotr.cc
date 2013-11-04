#include <iostream>
#include <ctime>


using namespace std;

char ary[64*64];

int d[4] = { -1, 1, 16, -16};

int best = -1;
int op = 0;
int maxk = 15;
void dfs(int digits, int val, int p, int sum) {
	if (ary[p] >= 0) return;
	ary[p] = val & 1;
	int nsum = sum;
	if (val & 1) {
		for (int di = 0; di < 4; di++) {
			nsum += ary[p + d[di]] == 1;
		}
	}

	if (digits == 1) {
		if (best < nsum) best = nsum;
		ary[p] = -1;
		return;
	}
	if (digits == maxk) {
		for (int di = 0; di < 1; di++) {
			dfs(digits - 1, val >> 1, p + d[di], nsum);
		}
	}
	else 
	if (digits == maxk - 1) {
		for (int di = 0; di < 3; di++) {
			dfs(digits - 1, val >> 1, p + d[di], nsum);
		}
	}
	else {
		for (int di = 0; di < 4; di++) {
			dfs(digits - 1, val >> 1, p + d[di], nsum);
		}
	}
	ary[p] = -1;
}

int res[1<<16];

int main() {
	int k = maxk;
	for (int i = 0; i < 64*64; i++) ary[i] = -1;
	int result = 0;
	for (int i = 0; i < (1<<k); i++){
		int rev = 0;
		for (int g = 0; g < k; g++) if (i&(1<<g)) rev |= 1<<k-1-g;

		if (rev < i) {
			res[i] = res[rev];
		}
		else {
			best = -1; 
			dfs(k, i, 64 * 32, 0); 
			res[i] = best;
		}

		result += res[i];
	}
	cout.precision(20);
	cout << clock() << endl;
	cout << op << endl;
	cout << k << endl;
	cout<<result<<endl;
	cout << (double)result / (1<<k) << endl;
	return 0;
}
