#include <cstdio>
#include <cstring>
int n,k,m;
struct Matrix {
	long long num[35][35];
	int size;
	Matrix() {
		memset(num,0,sizeof(num));
	}
	Matrix (int _n) {
		size = _n;
		memset(num,0,sizeof(num));
	}
	Matrix operator * (const Matrix &b) {
		Matrix tmp(size);
		for (int i=0;i<size;i++)
			for (int j=0;j<size;j++) {
				for (int k=0;k<size;k++) {
					tmp.num[i][j] += (num[i][k] * b.num[k][j]);
					tmp.num[i][j] %= m;
				}
			}
		return tmp;
	}
	Matrix operator + (const Matrix &b) {
		Matrix tmp(size);
		for (int i=0;i<size;i++)
			for (int j=0;j<size;j++) {
				tmp.num[i][j] += num[i][j] + b.num[i][j];
				tmp.num[i][j] %= m;
			}
		return tmp;
	}
	Matrix pow(long long b) {
		Matrix a(size);
		Matrix tmp(size);
		memcpy(a.num,num,sizeof(num));
		if (b == 1) return a;
		tmp = a.pow(b/2);
		if (b % 2 == 1) return (tmp * tmp) * a;
		else return tmp * tmp;
	}
};
Matrix sum(Matrix a,long long k) {
	if (k == 1) return a;
	Matrix tmp = sum(a,k/2);
	Matrix tmp2 = a.pow(k/2);
	if (k & 1) {
		return tmp + tmp * tmp2 + a.pow(k);
	}
	else return tmp + tmp * tmp2;
}
int main() {
	while (scanf("%d%d%d",&n,&k,&m) == 3) {
		Matrix cur(n);
		for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%lld",&cur.num[i][j]);
		Matrix ans = sum(cur,k);
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				if (j != 0) printf(" ");
				printf("%lld",ans.num[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
