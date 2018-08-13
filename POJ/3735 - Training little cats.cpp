//语言选择C++，G++会爆栈RE
#include <cstdio>
#include <cstring>
#include <algorithm>
struct Matrix {
	long long num[105][105];
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
				for (int j=0;j<size;j++) tmp.num[i][j] += num[i][k] * b.num[k][j];
			}
		return tmp;
	}
	Matrix operator + (const Matrix &b) {
		Matrix tmp(size);
		for (int i=0;i<size;i++)
			for (int j=0;j<size;j++) {
				tmp.num[i][j] += num[i][j] + b.num[i][j];
				//tmp.num[i][j] %= mod;
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
	void clearu(int y) {
		for (int i=0;i<size;i++) num[i][y] = 0;
	}
	void clearv(int x) {
		for (int i=0;i<size;i++) num[x][i] = 0;
	}
	void swapu(int y1,int y2) {
		for (int i=0;i<size;i++) std::swap(num[i][y1],num[i][y2]);
	}
	void swapv(int x1,int x2) {
		for (int i=0;i<size;i++) std::swap(num[x1][i],num[x2][i]);
	}
	void base(int _size) {
		size = _size;
		memset(num,0,sizeof(num));
		for (int i=0;i<size;i++) num[i][i] = 1;
	}
};
int main() {
	Matrix cur;
	int n,k;
	long long m;
	while (scanf("%d%lld%d",&n,&m,&k) == 3 && n) {
		cur.base(n+1);
		while (k--) {
			char op[5];
			scanf("%s",op);
			int i,j;
			switch (op[0]) {
				case 'g':
					scanf("%d",&i);
					i --;
					cur.num[i][n] ++;
					break;
				case 'e':
					scanf("%d",&i);
					i --;
					cur.clearv(i);
					break;
				case 's':
					scanf("%d%d",&i,&j);
					i --;
					j --;
					cur.swapv(i,j);
					break;
			}
		}
		Matrix ans = cur.pow(m);
		for (int i=0;i<n;i++) {
			if (i != 0) printf(" ");
			printf("%lld",ans.num[i][n]);
		}
		printf("\n");
	}
	return 0;
}
