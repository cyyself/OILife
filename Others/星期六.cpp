#include <bits/stdc++.h>
using namespace std;
int sum[205][13][32];
int m[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int read() {
	int ret = 0;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}
	return ret;
}
int main() {
	int cur = 0;
	int day = 0;
	for (int i=1900;i<=2100;i++) {
		if ( (i % 4 == 0 && i % 100 != 0) || i % 400 == 0) m[2] = 29;
		else m[2] = 28;
		for (int j=1;j<=12;j++) {
			sum[i-1900][j][0] = cur;
			for (int k=1;k<=m[j];k++) {
				day = (day + 1) % 7;
				if (day == 6) cur ++;
				sum[i-1900][j][k] = cur;
			}
		}
	}
	int T;
	scanf("%d",&T);
	while (T --) {
		int y1=read(),m1=read(),d1=read();
		int y2=read(),m2=read(),d2=read();
		printf("%d\n",sum[y2-1900][m2][d2]-sum[y1-1900][m1][d1-1]);
	}
	return 0;
}
