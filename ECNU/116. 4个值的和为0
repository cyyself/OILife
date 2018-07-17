#include <bits/stdc++.h>
using namespace std;
int a[4000];
int b[4000];
int c[4000];
int d[4000];

int e[16000000];//each a+b
int ecnt = 0;
int f[16000000];//each c+d
int fcnt = 0;

int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) {
			e[ecnt++] = a[i] + b[j];
			f[fcnt++] = c[i] + d[j];
		}

	sort(e,e+ecnt);
	sort(f,f+fcnt);

	long long ans = 0;
	for (int i=0;i<ecnt;i++) {
		long int p = lower_bound(f,f+fcnt,-e[i]) - f;
		while (f[p] == -e[i]) {
			ans ++;
			p ++;
			if (p >= fcnt) break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
