#include <bits/stdc++.h>
struct Matrix{
	int h,w;
	long long a[2][2];
	Matrix operator * (const Matrix &b) {
		Matrix t;
		t.h = h;
		t.w = b.w;
		for (int i=0;i<h;i++) 
			for (int j=0;j<b.w;j++) {
				t.a[i][j] = 0;
				for (int k=0;k<w;k++) {
					t.a[i][j] += a[i][k] * b.a[k][j];
					t.a[i][j] %= 1000000007;
				}
			}
		return t;
	}
	Matrix pow(long long m) {
		Matrix t;
		t.h = h;
		t.w = w;
		memcpy(t.a,a,sizeof(a));
		if (m == 1) return t;
		Matrix tmp = t.pow(m / 2);
		if (m % 2) return tmp * tmp * t;
		else return tmp * tmp;
	}
};
int main() {
	long long n;
	scanf("%lld",&n);
	Matrix ma;
	ma.h = 2;
	ma.w = 2;
	ma.a[0][0] = 1;
	ma.a[0][1] = 1;
	ma.a[1][0] = 1;
	ma.a[1][1] = 0;
	if (n != 1)ma = ma.pow(n-1);
	printf("%lld\n",ma.a[0][0]);
	return 0;
}
