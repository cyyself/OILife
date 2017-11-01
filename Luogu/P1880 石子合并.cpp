#include <bits/stdc++.h>
using namespace std;
int a[205];
int s[205];
int f[205][205];//min
int g[205][205];//max
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		a[i+n] = a[i];
	}
	for (int i=1;i<=n*2;i++) s[i] = s[i-1] + a[i];
	for (int len=2;len<=n;len++) {
		for (int i=1;i<=n*2-len+1;i++) {
			int j = i + len - 1;
			int MIN = 0x7fffffff;
			int MAX = 0;
			for (int k=i;k<j;k++) {
				MIN = min(MIN,f[i][k] + f[k+1][j] + s[j] - s[i-1]);
				MAX = max(MAX,g[i][k] + g[k+1][j] + s[j] - s[i-1]);
			}
			f[i][j] = MIN;
			g[i][j] = MAX;
		}
	}
	int MIN = 0x7fffffff;
	int MAX = 0;
	for (int i=1;i<=n;i++) {
		MIN = min(MIN,f[i][i-1+n]);
		MAX = max(MAX,g[i][i-1+n]);
	}
	printf("%d\n%d\n",MIN,MAX);
	return 0;
}
