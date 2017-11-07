#include <bits/stdc++.h>
struct Matrix{
	int h,w;
	long long a[3][3];
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
	int T;
	scanf("%d",&T);
	while (T--) {
		int q;
		scanf("%d",&q);
		if (q == 1) {
			printf("1\n");
			continue;
		}
		Matrix ma;
		ma.h = 3;
		ma.w = 3;
		int a[3][3] = {
			{0,1,1},
			{0,0,1},
			{1,1,1}
		};
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++) ma.a[i][j] = a[i][j];
		ma = ma.pow(q/2);
		printf("%lld\n",ma.a[2][1+q%2]);
	}
	return 0;
}
