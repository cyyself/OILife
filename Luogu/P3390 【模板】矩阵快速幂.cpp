#include <cstdio>
#include <cstring>
using namespace std;
int n;
struct Matrix{
	int w,h;
	long long num[105][105];
	Matrix(int w,int h):w(w),h(h) {
		memset(num,0,sizeof(num));
	}
	inline Matrix operator *(const Matrix &a) const{
		Matrix t(w,a.h);
		for (int i=0;i<w;i++)
			for (int j=0;j<a.h;j++)
				for (int k=0;k<h;k++){
					t.num[i][j] += (num[i][k] * a.num[k][j]);
					t.num[i][j] %= 1000000007;
				}
		return t;
	}
};

Matrix mqpow(Matrix a,long long n) {
	Matrix t = a;
	Matrix k = a;
	n --;
	while(n != 0) {
		if (n % 2 == 1) t = t * k;
		k = k * k;
		n /= 2;
	}
	return t;
}

int main() {
	int n;
	long long k;
	scanf("%d%lld",&n,&k);
	Matrix m(n,n);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%lld",&m.num[i][j]);
	m = mqpow(m,k);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) printf("%lld ",m.num[i][j]);
		printf("\n");
	}
	return 0;
}