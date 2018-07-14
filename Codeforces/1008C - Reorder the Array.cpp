#include <bits/stdc++.h>
using namespace std;
struct num{
	int x;
	int v;
	friend bool operator < (const num &a,const num &b) {
		return a.v < b.v;
	}
}num[100005];
int n;
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&num[i].v);
		num[i].x = i;
	}
	sort(num,num+n);
	int j = 1;
	int ans = 0;
	for (int i=0;i<n;i++) {
		while (num[j].v == num[i].v && j < n) j ++;
		if (j >= n) break;
		if (num[j].v > num[i].v) {
			ans ++;
			j ++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
