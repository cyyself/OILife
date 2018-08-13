#include <cstdio>
#include <cstring>
#include <algorithm>
struct Matrix {
	int num[3][3];
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
			for (int k=0;k<size;k++) if (num[i][k]) {//小优化
				for (int j=0;j<size;j++) {
					tmp.num[i][j] += num[i][k] * b.num[k][j];
					tmp.num[i][j] %= 10007;
				}
			}
		return tmp;
	}
	Matrix pow(long long b) {
		Matrix a(size);
		Matrix tmp(size);
		memcpy(a.num,num,sizeof(num));
		if (b <= 0) {
			Matrix ret;
			ret.base(size);
			return ret;
		}
		if (b == 1) return a;
		tmp = a.pow(b/2);
		if (b % 2 == 1) return (tmp * tmp) * a;
		else return tmp * tmp;
	}
	void base(int _size) {
		size = _size;
		memset(num,0,sizeof(num));
		for (int i=0;i<size;i++) num[i][i] = 1;
	}
}mt;
int main() {
	mt = Matrix(3);
	mt.num[0][0] = 2;
	mt.num[0][1] = 1;
	mt.num[0][2] = 0;
	mt.num[1][0] = 2;
	mt.num[1][1] = 2;
	mt.num[1][2] = 2;
	mt.num[2][0] = 0;
	mt.num[2][1] = 1;
	mt.num[2][2] = 2;
	int T;
	scanf("%d",&T);
	while (T--) {
		int n;
		scanf("%d",&n);
		Matrix ans = mt.pow(n);
		printf("%d\n",ans.num[0][0]);
	}
	return 0;
}
