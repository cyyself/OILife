#include <bits/stdc++.h>
using namespace std;
string findstr[4] = {"2-","8-","10-","16-"};
int gethex(char c) {
	if (c >= 'a' && c <= 'f') return 10 + c - 'a';
	if (c >= 'A' && c <= 'F') return 10 + c - 'A';
	if (c >= '0' && c <= '9') return c - '0';
	return -1;
}
int phrase(string t) {
	int ans = -1;
	for (int i=0;i<t.length();i++) {
		for (int j=0;j<4;j++) {
			if (t[i] == findstr[j][0]) {
				int k;
				for (k=1;k<findstr[j].length();k++) if (t[i+k] != findstr[j][k]) break;
				if (k == findstr[j].length()) {
					int ret = 0;
					switch (j) {
						case 0:
							while (i+k < t.length() && t[i+k] >= '0' && t[i+k] <= '1') {
								ret <<= 1;
								ret += t[i+k]-'0';
								k ++;
							}
							break;
						case 1:
							while (i+k < t.length() && t[i+k] >= '0' && t[i+k] <= '7') {
								ret <<= 3;
								ret += t[i+k]-'0';
								k ++;
							}
							break;
						case 2:
							while (i+k < t.length() && t[i+k] >= '0' && t[i+k] <= '9') {
								ret *= 10;
								ret += t[i+k]-'0';
								k ++;
							}
							break;
						case 3:
							while (i+k < t.length() && gethex(t[i+k]) != -1) {
								ret <<= 4;
								ret += gethex(t[i+k]);
								k ++;
							}
					}
					ans = max(ans,ret);
				}
			}
		}
	}
	return ans;
}
int main() {
	string tmp;
	while (getline(cin,tmp)) {
		int ans = phrase(tmp);
		while (getline(cin,tmp)) {
			ans = max(ans,phrase(tmp));
			if (tmp == "") break;
		}
		if (ans != -1) cout << ans << endl;
		else cout << "Poor TaoSama" << endl;
	}
	return 0;
}
