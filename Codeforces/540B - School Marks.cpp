#include <bits/stdc++.h>
using namespace std;
int a[1005];
int b[1005];
int main() {
	int n,k,p,x,y;
	scanf("%d%d%d%d%d",&n,&k,&p,&x,&y);
	int sum = 0;
	for (int i=1;i<=k;i++) {
		scanf("%d",&a[i]);
		sum += a[i];
	}
	int need = n - k;
	int ans = -1;
	for (int small=0;small<=need;small ++) {//枚举要放小数字的数量
		int big = need - small;
		int MIN = 1;
		bool flag = true;
		if (small != 0) {
			while ((x - sum - MIN * small) > p * big) {
				MIN ++;
				if (MIN > p) {
					flag = false;
					break;
				}
			}
		}
		if (!flag) continue;
		int MAX;
		int rem;
		if (big == 0 && small != 0) {
			if ((x - sum - MIN * small) != 0) continue;
		}
		else {
			MAX = (x - sum - MIN * small) / big;
			rem = (x - sum - MIN * small) % big;
			if (MAX > p) MAX = p;
			if (MAX + (rem?1:0) > p) rem = 0;
			if (MAX < 1) continue;
		}
		int j = k;
		for (int i=0;i<big;i++) {
			a[++j] = MAX;
			if (rem) {
				a[j] ++;
				rem --;
			}
		}
		for (int i=0;i<small;i++) a[++j] = MIN;
		
		memcpy(b,a,sizeof(a));
		sort(b+1,b+1+n);
		if (b[(n+1)/2] < y) {
			//不可能玩电脑的
			continue;
		}
		ans = 1;
		for (int i=k+1;i<=n;i++) {
			if (i > k + 1) printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");
		break;
	}
	if (ans == -1) printf("-1\n");
	return 0;
}
