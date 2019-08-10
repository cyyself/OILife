#include <bits/stdc++.h>
using namespace std;
int ans[1025][1025];
int main() {
	int siz;
	scanf("%d",&siz);
	int n = log2(siz);
	ans[1][1] = 1;
	for (int i=1;i<=n;i++) {
		//左下
		for (int j=(1<<(i-1))+1;j<=(1<<i);j++) for (int k=1;k<=(1<<(i-1));k++) {
			ans[j][k] = ans[j-(1<<(i-1))][k];
		}
		//右上
		for (int j=1;j<=(1<<(i-1));j++) for (int k=(1<<(i-1))+1;k<=(1<<i);k++) {
			ans[j][k] = ans[j][k-(1<<(i-1))];
		}
		//右下
		for (int j=(1<<(i-1))+1;j<=(1<<i);j++) for (int k=(1<<(i-1))+1;k<=(1<<i);k++) {
			ans[j][k] = -ans[j-(1<<(i-1))][k-(1<<(i-1))];
		}
	}
	for (int i=1;i<=siz;i++) {
		for (int j=1;j<=siz-1;j++) {
			printf("%d ",ans[i][j]);
		}
		printf("%d\n",ans[i][siz]);
	}
	return 0;
}
