#include <bits/stdc++.h>
double e[100005];
void dfs(int n) {
	if (n == 1) return;
	if (e[n] != 0) return;
	double sum = 0;
	int cnt = -1;
	for (int i=1;i*i<=n;i++) {
		if (n % i == 0) {
			cnt ++;
			if (i != n) dfs(i);
			sum += e[i] + 1;
			if (i * i != n) {
				cnt ++;
				if (n / i != n) dfs(n / i);
				sum += e[n/i] + 1;
			}
		}
	}
	e[n] = sum / cnt;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int x;
		scanf("%d",&x);
		dfs(x);
		printf("Case %d: %0.10lf\n",c,e[x]);
	}
	return 0;
}
