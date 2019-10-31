#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const long long mo = 1e9+7;
int sufr[maxn][maxn],sufd[maxn][maxn];
inline int lowbit(int x) {return x & -x;}
char s[maxn][maxn];
struct BIT {
	long long a[maxn];
	void add(int x,long long d) {
		for (int i=x;i<maxn;i+=lowbit(i)) a[i] += d;
	}
	long long query(int x) {
		long long sum = 0;
		for (int i=x;i>0;i-=lowbit(i)) sum += a[i];
		return sum;
	}
}prex[maxn][2],prey[maxn][2];//0为向右，1为向下
long long f[maxn][maxn][2];
long long MO(long long x) {
	return (x % mo + mo) % mo;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	if (n == 1 && m == 1) {
		printf("1\n");
		return 0;
	}
	for (int i=1;i<=n;i++) scanf("%s",&s[i][1]);
	for (int i=1;i<=n;i++) 
		for (int j=m;j>=1;j--) 
			sufr[i][j] = sufr[i][j+1] + (s[i][j] == 'R');
	for (int j=1;j<=m;j++) 
		for (int i=n;i>=1;i--) 
			sufd[i][j] = sufd[i+1][j] + (s[i][j] == 'R');
	//for (int i=1;i<=n-sufd[1][1];i++) f[i][1] = 1;
	//for (int j=1;j<=m-sufr[1][1];j++) f[1][j] = 1;
	f[1][1][0] = f[1][1][1] = 1;
	for (int i=1;i<=n;i++) { 
		for (int j=1;j<=m;j++) {
			f[i][j][0] = MO(f[i][j][0] + prex[i][0].query(j) + prey[j][0].query(i));
			f[i][j][1] = MO(f[i][j][1] + prex[i][1].query(j) + prey[j][1].query(i));
			int r = m - sufr[i][j+1];//最后一个可行的位置
			if (r >= j + 1) {
				prex[i][0].add(j+1,f[i][j][1]);
				prex[i][0].add(r+1,-f[i][j][1]);
			}
			int d = n - sufd[i+1][j];
			if (d >= i + 1) {
				prey[j][1].add(i+1,f[i][j][0]);
				prey[j][1].add(d+1,-f[i][j][0]);
			}
		}
	}
	printf("%lld\n",MO(f[n][m][0] + f[n][m][1]));
	return 0;
}
