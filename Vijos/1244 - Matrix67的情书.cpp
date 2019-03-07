#include <bits/stdc++.h>
using namespace std;
string s;
int cnt_e(int t) {
	int cnt = 0;
	for (auto x:s) {
		if (x >= 'a' && x <= 'z') {
			char c = 'a' + (x - 'a' + t) % 26;
			if (c == 'e') cnt ++;
		}
		else if (x >= 'A' && x <= 'Z') {
			char c = 'A' + (x - 'A' + t) % 26;
			if (c == 'E') cnt ++;
		}
	}
	return cnt;
}
void out(int t) {
	for (auto x:s) {
		if (x >= 'a' && x <= 'z') {
			char c = 'a' + (x - 'a' + t) % 26;
			printf("%c",c);
		}
		else if (x >= 'A' && x <= 'Z') {
			char c = 'A' + (x - 'A' + t) % 26;
			printf("%c",c);
		}
		else printf("%c",x);
	}
}
int main() {
	string t;
	while (getline(cin,t)) s += t + "\n";
	int max_cnt = 0;
	int max_t = 0;
	for (int i=0;i<26;i++) {
		int c = cnt_e(i);
		if (c > max_cnt) {
			max_cnt = c;
			max_t = i;
		}
	}
	out(max_t);
	return 0;
}
