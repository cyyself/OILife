#include <bits/stdc++.h>
struct Matrix {
	int h,w;
	int a[55][55];
	Matrix operator * (const Matrix &b) {
		Matrix t;
		t.h = h;
		t.w = b.w;
		for (int i=0;i<h;i++) 
			for (int j=0;j<b.w;j++) {
				t.a[i][j] = 0;
				for (int k=0;k<w;k++) {
					t.a[i][j] += a[i][k] * b.a[k][j];
					t.a[i][j] %= 10000;
				}
			}
		return t;
	}
	Matrix pow(int m) {
		Matrix t;
		memcpy(t.a,a,sizeof(a));
		t.h = h;
		t.w = w;
		if (m == 1) return t;
		Matrix ret = t.pow(m/2);
		if (m % 2 == 1) return ret * ret * t;
		else return ret * ret;
	}
	void clearu(int y) {
		for (int i=0;i<h;i++) a[i][y] = 0;
	}
	void clearv(int x) {
		for (int i=0;i<w;i++) a[x][i] = 0;
	}
}t[12];
inline int read() {
	int ret = 0;
	int f = 1;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}
	return ret * f;
}
int main() {
	int n,m;
	int st,ed;
	n = read();
	m = read();
	st = read();
	ed = read();
	int k = read();
	for (int i=0;i<12;i++) {
		t[i].h = n;
		t[i].w = n;
		//for (int j=0;j<n;j++) t[i].a[j][j] = 1;
	}
	while (m--) {
		int x,y;
		x = read();
		y = read();
		for (int i=0;i<12;i++) {
			t[i].a[x][y] = 1;
			t[i].a[y][x] = 1;
		}
	}
	int nfish = read();
	while (nfish--) {
		int T = read();
		int fishp[4];
		for (int i=0;i<T;i++) fishp[i] = read();
		for (int i=0;i<T;i++) {
			for (int j=i;j<12;j+=T) {
				t[j].clearv(fishp[i]);
				t[j].clearu(fishp[(i+1)%T]);
			}
		}
	}
	int k2 = k / 12;
	Matrix ans = t[0];
	if (k2 > 0) {
		for (int i=1;i<12;i++) ans = ans * t[i];
		ans = ans.pow(k2);
		for (int i=0;i<(k%12);i++) ans = ans * t[i];
	}
	else {
		for (int i=1;i<(k%12);i++) ans = ans * t[i];
	}
	printf("%d\n",ans.a[st][ed]%10000);
	return 0;
}
