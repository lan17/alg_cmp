 #include <string>
#include <cstdio>
#include <iostream>

using namespace std;

string solve(string s) {
	string res = "";
	while (s.size() > 0) {
		printf("%s\n", s.c_str());
		int mask = 0; int used = 0;
		int best_char = 'a';
		int n = s.size();
		int pos = 9999;
		for (int i = n-1; i >= 0; i--) {
			if (!(mask & (1<<(s[i]-'a')))) {
				cout<<s[i]<<endl;
				mask |= 1 << (s[i]-'a');
				used++;
				best_char = s[i];
				pos = i;
			}
			if (s[i] >= best_char) {
				best_char = s[i];
				pos = i;
			}
		}
		string next = "";
		for (int i = pos; i < n; i++) {
			if (s[i] != best_char)
				next += s[i];
		}
		res += best_char;
		printf("%c\n", best_char);
		printf("%s\n", res.c_str());
		s = next;
	}
	return res;
}

int main() {
	string input = "abcd";
	printf("out %s\n",solve(input).c_str());
	return 0;
}
