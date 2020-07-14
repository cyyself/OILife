#include <bits/stdc++.h>
using namespace std;
int read() {
	int res = 0;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) c = getchar();
	while (c >= '0' && c <= '9') {
		res = res*10 + c - '0';
		c = getchar();
	}
	return res;
}
int gettime() {
	int h = read();
	int m = read();
	int s = read();
	m += h * 60;
	s += m * 60;
	return s;
}
int main() {
	printf("%d\n",abs(gettime() - gettime()));
	return 0;
}
