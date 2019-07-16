#include <bits/stdc++.h>
using namespace std;
const int mo = 6;
struct Matrix {
	int n,m;
	int a[1000][1000];
	const int getval(int x,int y) {
		return a[x][y];
	}
	Matrix(int _n,int _m) {
		n = _n;
		m = _m;
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) a[i][j] = 0;
	}
	Matrix(const Matrix &b) {
		n = b.n;
		m = b.m;
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) a[i][j] = b.a[i][j];
	}
	void read() {
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&a[i][j]);
	}
	Matrix operator * (Matrix &b) {
		Matrix ret(n,b.m);
		for (int i=0;i<n;i++) for (int j=0;j<b.m;j++) {
			for (int k=0;k<m;k++) {
				ret.a[i][j] += (a[i][k] * b.a[k][j]) % mo;
				ret.a[i][j] %= mo;
			}
		}
		return ret;
	}
	Matrix pow(long long b) {
		Matrix cur(n,m);
		Matrix ret(n,m);
		for (int i=0;i<n;i++) ret.a[i][i] = 1;
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) cur.a[i][j] = a[i][j];
		if (b == 1) return cur;
		while (b) {
			if (b & 1) {
				ret = ret * cur;
			}
			b >>= 1;
			cur = cur * cur;
		}
		return ret;
	}
};
int main() {
	int n,k;
	while (scanf("%d%d",&n,&k) == 2 && n && k) {
		Matrix A(n,k),B(k,n);
		A.read();
		B.read();
		Matrix tmp = B * A;
		tmp = tmp.pow(n*n-1);
		Matrix ans = A * tmp;
		ans = ans * B;
		long long sum = 0;
		for (int i=0;i<ans.n;i++) for (int j=0;j<ans.m;j++) sum += ans.a[i][j];
		printf("%lld\n",sum);
	} 
	return 0;
}
