#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
	getline(cin,s);
	bool add = true;
	int cnt[2] = {0};//cnt[1]代表加号数量，cnt[2]代表减号数量
	int n = 0;
	for (int i=0;i<s.length();i++) {
		if (s[i] == ' ') continue;
		if (s[i] == '+') add = true;
		else if (s[i] == '-') add = false;
		else if (s[i] == '?') cnt[add] ++;
		else if (s[i] == '=') {
			i ++;//跳过=
			i ++;//跳过空格
			while (i < s.length()){
				n *= 10;
				n += s[i] - '0';
				i ++;
			}
		}
	}
	int maxnum = cnt[1] * n - cnt[0];
	int minnum = cnt[1] - cnt[0] * n;
	if (n > maxnum || n < minnum) {
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	int dec = 1;
	int each = (n + cnt[0] * dec) / cnt[1];
	int rem  = (n + cnt[0] * dec) % cnt[1];
	while (each == 0) {
		dec ++;
		each = (n + cnt[0] * dec) / cnt[1];
		rem  = (n + cnt[0] * dec) % cnt[1];
	}
	add = true;
	for (int i=0;i<s.length();i++) {
		if (s[i] == ' ') cout << s[i];
		if (s[i] == '+') {
			add = true;
			cout << s[i];
		}
		else if (s[i] == '-') {
			add = false;
			cout << s[i];
		}
		else if (s[i] == '?') {
			if (add) {
				if (rem) {
					cout << each + 1;
					rem --;
				}
				else cout << each;
			}
			else cout << dec;
		}
		else if (s[i] == '=') {
			while (i < s.length()) {
				cout << s[i];
				i ++;
			}
		}
	}
	cout << endl;
	return 0;
}
