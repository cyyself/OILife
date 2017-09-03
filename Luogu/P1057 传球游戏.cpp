#include <bits/stdc++.h>
int f[35][2];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	f[1][0] = 1;
	for (int k=1;k<=m;k++) 
		for (int i=1;i<=n;i++)
			f[(i+n)%n][k&1] = f[(i-1+n)%n][(k-1)&1] + f[(i+1+n)%n][(k-1)&1];
	printf("%d\n",f[1][m&1]);
	return 0;
}
