#include <bits/stdc++.h>
int f[305];
int t[305];
int main() {
	for (int i=0;i<=300;i++) f[i] = 1;
	int add = 3;
	for (int i=4;i<=289;add += 2,i += add) {
		memset(t,0,sizeof(t));
		for (int j=0;j<=300;j++) for (int k=j;k<=300;k+=i) t[k] += f[j];
		memcpy(f,t,sizeof(f));
	}
	int q;
	while (scanf("%d",&q) == 1 && q) printf("%d\n",f[q]);
	return 0;
}