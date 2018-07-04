#include <bits/stdc++.h>
using namespace std;
const long long mo = (long long)100000007*100000007;
long long f[100005];
map <long long,int> ha;
inline bool read(long long &ret) {
	ret = 0;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) {
		if (c == EOF) return false;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret %= mo;
		ret += c - '0';
		ret %= mo;
		c = getchar();
	}
	return true;
}
int main() {
	f[0] = 1;
	f[1] = 1;
	ha[1] = 1;
	for (int i=2;i<=100000;i++) {
		f[i] = (f[i-1] + f[i-2]) % mo;
		if (ha[f[i]]) printf("hash collision!\n");
		else ha[f[i]] = i;
	}
	long long q;
	while (read(q)) {
		printf("%d\n",ha[q]);
	}
	return 0;
}
