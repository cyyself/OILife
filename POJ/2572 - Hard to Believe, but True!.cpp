#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string s;
bool IsDigit(char c) {
	if (c >= '0' && c <= '9') return true;
	else return false;
}
int main() {
	while (cin >> s) {
		long long l = 0;
		long long xs = 1;
		int i = 0;
		while (IsDigit(s[i])) {
			l += (s[i] - '0') * xs;
			xs *= 10;
			i ++;
		}
		i ++;
		long long r = 0;
		xs = 1;
		while (IsDigit(s[i])) {
			r += (s[i] - '0') * xs;
			xs *= 10;
			i ++;
		}
		i++;
		long long sum = 0;
		xs = 1;
		while (IsDigit(s[i])) {
			sum += (s[i] - '0') * xs;
			xs *= 10;
			i ++;
		}
		if (l + r == sum) printf("True\n");
		else printf("False\n");
	}
	return 0;
}
