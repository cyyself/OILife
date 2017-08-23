#include <bits/stdc++.h>
using namespace std;
double p[1005];
double f[1005];
int main() {
	int N;
	scanf("%d",&N);
	for (int i=1;i<=N;i++) {
		int n,k,m;
		scanf("%d%d%d",&n,&k,&m);
		for (int j=0;j<n;j++) scanf("%lf",&p[j]);
		for (int j=0;j<=m;j++) f[j] = 0;
		f[1] = p[0];
		for (int j=2;j<=m;j++) 
			for (int l=0;l<n;l++) f[j] += p[l] * pow(f[j-1],l);
		printf("Case #%d: %0.7lf\n",i,pow(f[m],k));
	}
	return 0;
}
