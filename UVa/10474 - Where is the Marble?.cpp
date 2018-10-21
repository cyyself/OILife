#include <bits/stdc++.h>
using namespace std;
bool judge(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
char s[1000005];
set <string> ans;
int main() {
	char c = getchar();
	int len = 0;
	while (c != EOF) {
		s[len ++] = c;
		c = getchar();
	}
	string t;
	for (int i=0;i<len;i++) {
		if (judge(s[i])) {
			t += s[i] | 32;
		}
		else {
			if (t != "") ans.insert(t);
			t = "";
		}
	}
	if (t != "") ans.insert(t);
	for (auto a:ans) cout << a << endl;
	return 0;
}
