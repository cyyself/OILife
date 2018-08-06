//WA了半天，样例都没过，然后发现题目说的不是恰好等于x而是at least x
#include <bits/stdc++.h>
using namespace std;
unsigned long long f[155][26];//f[i][j]表示到达i，投j次的方案数
unsigned long long gcd(unsigned long long a,unsigned long long b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
void sim(unsigned long long &a,unsigned long long &b) {
	unsigned long long g = gcd(a,b);
	a /= g;
	b /= g;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int n,x;
		scanf("%d%d",&n,&x);
		memset(f,0,sizeof(f));
		f[0][0] = 1;
		for (int i=0;i<=n*6;i++) {
			for (int j=1;j<=6;j++) {
				for (int k=0;k<n;k++) f[i+j][k+1] += f[i][k];
			}
		}
		unsigned long long fz = 0;
		for (int i=x;i<=n*6;i++) fz += f[i][n];
		unsigned long long fm = pow((long long)6,(long long)n);
		if (fz == 0) printf("Case %d: 0\n",c);
		else {
			sim(fz,fm);
			if (fm == 1) printf("Case %d: %llu\n",c,fz);
			else printf("Case %d: %llu/%llu\n",c,fz,fm);
		}
	}
	return 0;
}
