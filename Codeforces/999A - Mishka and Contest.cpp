#include <bits/stdc++.h>
const int inf = 0x7fffffff;
int a[105];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int cnt = 0;
	bool lok = true;
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		if (lok) {
			if (a[i] <= k) {
				cnt ++;
				a[i] = inf;
			}
			else lok = false;
		}
	}
	bool rok = true;
	for (int i=n-1;i>=0;i--) {
		if (rok) {
			if (a[i] <= k) cnt ++;
			else rok = false;
		}
		else break;
	}
	printf("%d\n",cnt);
	return 0;
}