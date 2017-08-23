#include <bits/stdc++.h>
int f[125];
int t[125];
int main() {
	f[0] = 1;
	for (int i=1;i<=120;i++) {
		memset(t,0,sizeof(t));
		for (int j=0;j<=120;j++) for (int k=j;k<=120;k+=i) t[k] += f[j];
		memcpy(f,t,sizeof(t));
	}
	int q;
	while (scanf("%d",&q) == 1) printf("%d\n",f[q]);
	return 0;
}