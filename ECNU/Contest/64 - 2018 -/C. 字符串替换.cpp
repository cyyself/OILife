#include <bits/stdc++.h>
using namespace std;
char s[10005];
bool IsDigit(char c) {
	if (c >= '0' && c <= '9') return true;
	return false;
}
int getnum(char *str) {
	int ret = 0;
	while (IsDigit(*str)) {
		ret *= 10;
		ret += *str-'0';
		str ++;
	}
	return ret;
}
int main() {
	scanf("%s",s);
	int len = strlen(s);
	string tmp;
	for (int i=0;i<len;i++) {
		if (!IsDigit(s[i])) tmp = tmp + s[i];
		else {
			if (IsDigit(s[i-1])) continue;
			int num = getnum(&s[i]);
			for (int i=0;i<num;i++) cout << tmp;
			tmp = "";
		}
	}
	cout << tmp;
	cout << endl;
	return 0;
}
