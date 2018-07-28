#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int mo = 10000;
struct Matrix {
	long long m[2][2];
	Matrix operator * (const Matrix &b) {
		Matrix t;
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++) {
				t.m[i][j] = 0;
				for (int k=0;k<2;k++) {
					t.m[i][j] += m[i][k] * b.m[k][j];
					t.m[i][j] %= mo;
				}
			}
		return t;
	}
	Matrix pow(long long b) {
		Matrix a;
		memcpy(a.m,m,sizeof(m));
		if (b == 0) {
			Matrix base;
			base.m[0][0] = 1;
			base.m[0][1] = 0;
			base.m[1][0] = 0;
			base.m[1][1] = 1;
			return base;
		}
		if (b == 1) return a;
		Matrix tmp;
		tmp = a.pow(b/2);
		if (b & 1) return tmp * tmp * a;
		else return tmp * tmp;
	}
};

int main() {
	long long k;
	while (cin >> k) {
		if (k == -1) break;
		if (k == 0) {
			cout << 0 << endl;
			continue;
		}
		Matrix mtx;
		mtx.m[0][0] = 1;
		mtx.m[0][1] = 1;
		mtx.m[1][0] = 1;
		mtx.m[1][1] = 0;
		mtx = mtx.pow(k-1);
		cout << mtx.m[0][0] << endl;
	}
	return 0;
}
