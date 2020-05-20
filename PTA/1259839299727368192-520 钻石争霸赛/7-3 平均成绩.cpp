#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	int cnt[2]={0,0},sum[2]={0,0};
	for (int i=0;i<n;i++) {
		int g,s;
		scanf("%d%d",&g,&s);
		cnt[g] ++;
		sum[g] += s;
	}
	if (n == 0) printf("X X X\n");
	else {
		printf("%0.1lf",(double)(sum[0]+sum[1])/(cnt[0]+cnt[1]));
		if (cnt[1]) printf(" %0.1lf",(double)sum[1]/cnt[1]);
		else printf(" X");
		if (cnt[0]) printf(" %0.1lf",(double)sum[0]/cnt[0]);
		else printf(" X");
		printf("\n");
	}
	return 0;
}
