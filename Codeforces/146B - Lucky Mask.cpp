#include <bits/stdc++.h>
using namespace std;
int a,b;
int reverse_int(int x) {
	int ret = 0;
	while (x > 0) {
		ret *= 10;
		ret += x % 10;
		x /= 10;
	}
	return ret;
}
bool check(int x) {
	int mask = 0;
	while (x > 0) {
		int cur = x % 10;
		x /= 10;
		if (cur == 4 || cur == 7) {
			mask *= 10;
			mask += cur;
		}
	}
	return (mask == b);
}
int main() {
	cin >> a >> b;
	b = reverse_int(b);
	a ++;
	while (!check(a)) a ++;
	printf("%d\n",a);
	return 0;
}
